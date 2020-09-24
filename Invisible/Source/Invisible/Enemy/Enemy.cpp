// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"

#include "Engine.h"
#include "Invisible/ActionableObject/Locker.h"
#include "Invisible/Player/PlayerCharacter.h"
#include "Invisible/System/MyGameInstance.h"
#include "Invisible/System/SoundObject.h"
#include "Invisible/System/SoundSystem.h"
#include "Invisible/System/StencilBitValue.h"
#include "Kismet/GameplayStatics.h"

#include <string>

namespace
{
	constexpr float WALKING_THRESHOLD = 0.5f; //!< 歩いているとみなす閾値
	constexpr float WALKING_SOUND_PLAY_INTERVAL = 0.5f; //!< 歩行音の再生間隔

	float GetDeg_XY(FVector forward)
	{
		auto vector = forward;
		forward.Z = 0;
		auto normal = forward.GetSafeNormal();
		auto rad = FMath::Atan2(normal.Y, normal.X);
		auto deg = FMath::RadiansToDegrees(rad);
		return deg;
	}

	FVector VectorXY(FVector vector)
	{
		vector.Z = 0;
		return vector;
	}

	float Height()
	{
		return 150.0f;
	}
}

// Sets default values
AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("capsule"));
	capsule->InitCapsuleSize(20.0f, 80.0f);
	RootComponent = capsule;

	skeltal = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeltal"));
	skeltal->SetupAttachment(RootComponent);

	actionableArea = CreateDefaultSubobject<USphereComponent>(TEXT("ActionableArea"));
	actionableArea->InitSphereRadius(2000.0f);
	actionableArea->SetCollisionProfileName("OverlapOnlyPawn");
	actionableArea->SetSimulatePhysics(false);
	actionableArea->SetupAttachment(RootComponent);

	actionableArea->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::onComponentBeginOverlap);
	//skeltal->OnComponentHit.AddDynamic(this, &AEnemy::onComponentHit);
	//this->GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::onComponentBeginOverlap);

	silhouetteSkeltal = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SilhouetteSkeltal"));
	silhouetteSkeltal->bRenderInMainPass = false;
	silhouetteSkeltal->bRenderInDepthPass = false;
	silhouetteSkeltal->bRenderCustomDepth = true;
	silhouetteSkeltal->CustomDepthStencilValue = 0;
	silhouetteSkeltal->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	//reflection = 1;
	//thirstSpeed = 10000;
	lastSearch = GetActorLocation();

	auto actor = UGameplayStatics::GetActorOfClass(GetWorld(), APlayerCharacter::StaticClass());
	player = (actor == nullptr) ? nullptr : actor;

	auto timer = UGameplayStatics::GetActorOfClass(GetWorld(), ALimitTimer::StaticClass());
	limitTimer = (timer == nullptr) ? nullptr : Cast<ALimitTimer>(timer);

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemy::StaticClass(), enemys);
}

void AEnemy::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	FTimerManager& TimerManager = GetWorldTimerManager();
	TimerManager.ClearTimer(ReturnStencilValueWhenPutOnWaterHandle);
	TimerManager.ClearTimer(ReturnStencilValueWhenWalkOnPuddle);
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (UMyGameInstance::GetInstance()->getClear())
	{
		return;
	}

	InLocker();
	DebugDraw();
	SetMaterial(DeltaTime);
	if (IsKill(DeltaTime))
		return;

	chaseTimer = std::fmax(0.0f, chaseTimer - DeltaTime);
	TimerCheck(playerActiveType);
	SearchCourse(DeltaTime);
	Moving(DeltaTime);
	playWalkSound(DeltaTime);
}

bool AEnemy::IsKill(float DeltaTime)
{
	if (IsInLocker())
	{
		auto pos = VectorXY(player->GetActorLocation());
		if (Cast<APlayerCharacter>(player)->GetCurrentInLocker())
		{
			auto locker = Cast<APlayerCharacter>(player)->GetCurrentInLocker();
			pos = VectorXY(locker->GetActorLocation() + locker->GetActorForwardVector() * searchManager->GetRadius());
		}
		if (VectorXY(pos - VectorXY(GetActorLocation())).Size() <= searchManager->GetRadius() * 2)
		{
			if (moveType != EMoveType::Kill)
			{
				PlayerKill();
			}
		}
	}

	if (moveType == EMoveType::Kill)
	{
		// 初期値設定
		auto pos = GetActorLocation();

		switch (playerActiveType)
		{
		case EPlayerActionMode::GetOutOfLocker:
		case EPlayerActionMode::GoingIntoLocker:
			auto p = Cast<APlayerCharacter>(player);
			auto point = p->GetActorLocation();
			if (p->GetCurrentInLocker())
			{
				auto locker = p->GetCurrentInLocker();
				point = VectorXY(locker->GetActorLocation() + locker->GetActorForwardVector() * searchManager->GetRadius() * 2);
				point.Z = p->GetActorLocation().Z;
			}
			auto vector = VectorXY(point - pos);
			if (10 < vector.Size())
			{
				pos += vector.GetSafeNormal() * walkSpeed * DeltaTime;
				SetActorLocation(pos);
			}
		}

		auto vector = VectorXY(player->GetActorLocation() - pos);
		auto nor = vector.GetSafeNormal();

		// 回転
		auto r = GetActorForwardVector() + nor * DeltaTime * rotateSpeed;
		SetActorRotation(r.Rotation());
		return true;
	}

	if (Cast<APlayerCharacter>(player)->GetCurrentActionMode() == EPlayerActionMode::IsDying)
	{
		return true;
	}
	return false;
}

// 移動処理
void AEnemy::Moving(float DeltaTime)
{
	if (courses.Num() <= 0)
	{
		SetWait();
		return;
	}
	if (moveType == EMoveType::None)
	{
		courses.RemoveAll([](FVector) { return true; });
		chaseTimer = 0.0f;
		return;
	}
	if (moveType == EMoveType::Move)
	{
		if (0 < searchWaitRotateTimer)
		{
			searchWaitRotateTimer = FMath::Max(0.0f, searchWaitRotateTimer - DeltaTime);

			auto rotVec = (rotateType == ERotateType::Right) ?
			    GetActorRightVector() :
			    -GetActorRightVector();

			// 回転
			auto r = GetActorForwardVector() + rotVec * DeltaTime * 6.0f / FMath::Max(1.0f, searchWaitRotateTime);
			SetActorRotation(r.Rotation());
			if (0 < searchWaitRotateTimer)
			{
				return;
			}
		}
	}

	// 経路更新
	if ((VectorXY(courses[0] - GetActorLocation())).Size() <= searchManager->GetRadius())
	{
		if (0 < courses.Num())
		{
			lastSearch = courses[0];
			courses.RemoveAt(0);

			if ((moveType == EMoveType::Move) && (0 <= courses.Num()) && (FMath::FRandRange(0.0f, 100.0f) <= FMath::Clamp(searchWaitPercent, 0.0f, 100.0f)))
			{
				searchWaitRotateTimer = FMath::Max(1.0f, searchWaitRotateTime);

				rotateType = (FMath::FRandRange(0.0f, 100.0f) <= 50.0f) ?
				    ERotateType::Right :
				    ERotateType::Left;
			}
		}
	}
	else
	{
		HitMoved();

		// 初期値設定
		auto pos = (GetActorLocation());
		auto vector = VectorXY(courses[0] - pos);
		auto nor = vector.GetSafeNormal();

		//	移動値設定
		auto speed = ((moveType == EMoveType::Move) || (moveType == EMoveType::SE_Move)) ? walkSpeed : runSpeed;
		auto length = (speed < vector.Size()) ? speed : vector.Size();
		auto mov = nor * speed * DeltaTime;

		// 移動
		SetActorLocation(pos + mov);

		// 回転
		auto r = GetActorForwardVector() + nor * DeltaTime * rotateSpeed;
		SetActorRotation(r.Rotation());
	}

	if (courses.Num() <= 0)
	{
		if (moveType == EMoveType::PlayerChase)
		{
			if (IsInLocker())
			{
				auto p = Cast<APlayerCharacter>(player);
				auto pos = player->GetActorLocation();
				if (p->GetCurrentInLocker())
				{
					auto locker = p->GetCurrentInLocker();
					pos = VectorXY(locker->GetActorLocation() + locker->GetActorForwardVector() * searchManager->GetRadius());
				}

				courses = searchManager->ChaseCourse(GetActorLocation(), pos);
			}
			else
			{
				FHitResult hit;
				FCollisionQueryParams params;
				params.AddIgnoredActors(enemys);
				if (player != nullptr)
				{
					params.AddIgnoredActor(player);
				}

				auto start = GetActorLocation();
				auto end = player->GetActorLocation();
				start.Z = Height();
				end.Z = Height();

				if (!GetWorld()->LineTraceSingleByChannel(hit, start, end,
				        ECollisionChannel::ECC_Visibility, params))
				{
					courses = searchManager->ChaseCourse(start, end);
					return;
				}
				else if (0 < chaseTimer)
				{
					auto p = Cast<APlayerCharacter>(player);
					// ロッカーにいないときは普通に追跡
					if (p->GetCurrentInLocker() == nullptr)
					{
						courses = searchManager->ChaseCourse(start, end);
						return;
					}
					// ロッカーにいてロッカー時にも追跡してくる時間内なら開けに来る
					else if ((chaseTime * (1.0f - FMath::Clamp(chaseSearchTime, 0.0f, 1.0f))) <= chaseTimer)
					{
						auto locker = p->GetCurrentInLocker();
						end = VectorXY(locker->GetActorLocation() + locker->GetActorForwardVector() * searchManager->GetRadius());
						courses = searchManager->ChaseCourse(start, end);
						TimerCheck(EPlayerActionMode::GoingIntoLocker);
						return;
					}
					// ロッカーにいて追跡してくる時間外なら目の前まで
					else
					{
						auto locker = p->GetCurrentInLocker();
						end = VectorXY(locker->GetActorLocation() + locker->GetActorForwardVector() * searchManager->GetRadius());
						if (searchManager->GetRadius() < (end - start).Size())
						{
							courses = searchManager->ChaseCourse(start, end);
						}
						else
						{
							chaseTimer = 0.0f;
						}
					}
				}

				auto playSECount = 0;
				for (int i = 0; i < enemys.Num(); i++)
				{
					auto e = Cast<AEnemy>(enemys[i]);
					if (e->moveType == EMoveType::PlayerChase)
					{
						playSECount++;
					}
				}

				if (playSECount <= 1)
				{
					UMyGameInstance::GetInstance()->getSoundSystem()->StopBGM();
				}
			}
		}
		SetWait();
	}
}

void AEnemy::HitMoved()
{
	if (searchManager == nullptr)
	{
		return;
	}
	if (courses.Num() <= 0)
	{
		return;
	}
	if (IsInLocker())
	{
		return;
	}

	FHitResult hit;
	FCollisionQueryParams params;

	params.AddIgnoredActors(enemys);
	if (player != nullptr)
	{
		params.AddIgnoredActor(player);
	}
	if (IsInLocker() && (Cast<APlayerCharacter>(player)->GetCurrentInLocker() != nullptr))
	{
		params.AddIgnoredActor(Cast<APlayerCharacter>(player)->GetCurrentInLocker());
	}

	auto start = GetActorLocation();
	auto end = courses[0];
	start.Z = (player == nullptr) ? 100 : player->GetActorLocation().Z;
	end.Z = (player == nullptr) ? 100 : player->GetActorLocation().Z;

	if (GetWorld()->LineTraceSingleByChannel(hit, start, end,
	        ECollisionChannel::ECC_Visibility, params))
	{
		if (hit.GetActor() == nullptr)
		{
			return;
		}

		auto point = VectorXY(hit.ImpactPoint);
		auto vector = VectorXY(start - point);
		auto normal = VectorXY(vector).GetSafeNormal();

		auto n = hit.ImpactNormal;
		auto h = FVector::DotProduct(vector, n);

		auto near = VectorXY(point + vector.GetSafeNormal() + n * searchManager->GetRadius());
		//auto near = VectorXY(point + normal * searchManager->GetRadius());
		near.Z = GetActorLocation().Z;
		if (vector.Size() <= searchManager->GetRadius())
		{
			SetActorLocation(near);
			start = near;
		}

		//auto chase = searchManager->ChaseCourse(near, courses[courses.Num() - 1]);
		//for (int i = 0; i < chase.Num(); i++)
		//{
		//	courses.Insert(chase[i], i);
		//}
		courses.Insert(near, 0);
	}
}

// 待機時間設定
void AEnemy::SetWait()
{
	if (moveType == EMoveType::None)
	{
		return;
	}

	if (IsInLocker())
	{
		return;
	}

	searchWaitRotateTimer = FMath::Max(1.0f, searchWaitRotateTime);

	rotateType = (FMath::FRandRange(0.0f, 100.0f) <= 50.0f) ?
	    ERotateType::Right :
	    ERotateType::Left;

	waitTimer = waitTime * FMath::FRandRange(0.0f, 1.0f);
	moveType = EMoveType::None; //	moveType => None
}

// 経路探索
void AEnemy::SearchCourse(float DeltaTime)
{
	chasePlayer();

	if (moveType == EMoveType::None)
	{
		waitTimer -= DeltaTime;
		if (0 < waitTimer)
		{
			courses.RemoveAll([](FVector) { return true; });
			return;
		}
		waitTimer = 0;
	}

	if (searchManager == nullptr)
	{
		return;
	}
	if (0 < courses.Num())
	{
		return;
	}
	if (moveType != EMoveType::None)
	{
		return;
	}

	courses = searchManager->Course(this);
	if (courses.Contains(lastSearch))
	{
		courses.Remove(lastSearch);
	}
	moveType = EMoveType::Move; //	moveType => Move
}

// プレイヤー探索
void AEnemy::searchPlayer(AActor* OtherActor)
{
	if (searchManager == nullptr)
	{
		return;
	}
	if (moveType == EMoveType::PlayerChase)
	{
		return;
	}

	waitTimer = 0;
	searchWaitRotateTimer = 0;

	moveType = EMoveType::SE_Move; //	moveType => SE_Move
	courses = searchManager->ChaseCourse(this, OtherActor);
}

// プレイヤー追跡
void AEnemy::chasePlayer()
{
	if (player == nullptr)
	{
		return;
	}

	if (IsEyeArea())
	{
		if (moveType != EMoveType::PlayerChase)
		{
			//auto playSECount = 0;
			//for (int i = 0; i < enemys.Num(); i++)
			//{
			//	auto e = Cast<AEnemy>(enemys[i]);
			//	if (e->moveType == EMoveType::PlayerChase)
			//	{
			//		playSECount++;
			//	}
			//}
			//if (playSECount <= 0)
			{
				//コントローラの振動を追いかけられるBGM再生時に発生させる
				constexpr float VIBRATION_DURATION = 1.5f;
				UMyGameInstance::GetInstance()->GetControllerVibration()->StartVibration(VIBRATION_DURATION, 1.0f);
				UMyGameInstance::GetInstance()->getSoundSystem()->PlayBGM(ESoundType::Chase_BGM);
			}
		}
		waitTimer = 0;
		searchWaitRotateTimer = 0;
		chaseTimer = chaseTime;

		moveType = EMoveType::PlayerChase; //	moveType => PlayerChase
		courses.RemoveAll([](FVector) { return true; });
		auto vector = (VectorXY(player->GetActorLocation() - GetActorLocation())).GetSafeNormal();
		auto pos = VectorXY(player->GetActorLocation() + vector * searchManager->GetRadius());

		FHitResult hit;
		FCollisionQueryParams params;
		params.AddIgnoredActors(enemys);
		params.AddIgnoredActor(player);

		auto ePos = VectorXY(GetActorLocation());
		ePos.Z = 50;
		pos.Z = 50;

		//if (GetWorld()->LineTraceSingleByChannel(hit, ePos, pos,
		//        ECollisionChannel::ECC_Visibility, params))
		//{
		//	pos = VectorXY(hit.ImpactPoint + (ePos - pos).GetSafeNormal() * 10);
		//}
		if (IsInLocker())
		{
			auto p = Cast<APlayerCharacter>(player);
			if (p->GetCurrentInLocker())
			{
				auto locker = p->GetCurrentInLocker();
				pos = VectorXY(locker->GetActorLocation() + locker->GetActorForwardVector() * searchManager->GetRadius());
			}
		}

		courses.Add(pos);
	}
	else if (moveType == EMoveType::PlayerChase)
	{
		if (player != nullptr)
		{
			if (chaseTimer <= 0)
			{
				courses.RemoveAll([](FVector) { return true; });

				auto playSECount = 0;
				for (int i = 0; i < enemys.Num(); i++)
				{
					auto e = Cast<AEnemy>(enemys[i]);
					if (e->moveType == EMoveType::PlayerChase)
					{
						playSECount++;
					}
				}

				if (playSECount <= 1)
				{
					UMyGameInstance::GetInstance()->getSoundSystem()->StopBGM();
				}

				SetWait();
			}
			//if (courses.Num() <= 1)
			{
				FHitResult hit;
				FCollisionQueryParams params;

				params.AddIgnoredActors(enemys);
				params.AddIgnoredActor(player);

				auto start = GetActorLocation();
				auto end = player->GetActorLocation();
				start = (courses.Num() <= 0) ? start : courses[0];
				start.Z = Height();
				end.Z = Height();

				if (!GetWorld()->LineTraceSingleByChannel(hit, start, end,
				        ECollisionChannel::ECC_Visibility, params))
				{
					courses = searchManager->ChaseCourse(start, end);
				}
				else if (IsInLocker())
				{
					auto p = Cast<APlayerCharacter>(player);
					if (p->GetCurrentInLocker())
					{
						auto locker = p->GetCurrentInLocker();
						end = VectorXY(locker->GetActorLocation() + locker->GetActorForwardVector() * searchManager->GetRadius());
					}
					courses = searchManager->ChaseCourse(start, end);
				}
			}
		}
	}
}

// マテリアル
void AEnemy::SetMaterial(float DeltaTime)
{
	overBathing();

	float thirst = (thirstSpeed <= 1.0f) ? DeltaTime : DeltaTime / thirstSpeed;
	if (moveType == EMoveType::Kill)
	{
		reflection += DeltaTime;
	}
	else
	{
		reflection -= thirst;
	}

	reflection = (reflection < 0) ? 0 : (1 < reflection) ? 1 : reflection;
	skeltal->SetScalarParameterValueOnMaterials("reflection", reflection);
}

// 透明化設定
void AEnemy::AddReflection(float add)
{
	reflection += add;
	reflection = (reflection < 0) ? 0 : (1 < reflection) ? 1 : reflection;
}

void AEnemy::DebugDraw()
{
	if (debugDraw == 0)
	{
		return;
	}

	// ----- デバッグ文字描画 -----------------------------------------------------------------------------------------
	auto mov = TMap<EMoveType, FString>{
	    {EMoveType::None, "None"},
	    {EMoveType::Move, "Move"},
	    {EMoveType::SE_Move, "SE_Move"},
	    {EMoveType::PlayerChase, "PlayerChase"},
	    {EMoveType::Kill, "Kill"},
	};
	auto m = mov[moveType];
	auto s = "[ " + std::to_string(courses.Num()) + " ]";
	auto str = FString::FString(s.c_str()) + m;

	str += FString::FString(("\n" + std::to_string(GetDeg_XY(GetActorForwardVector()))).c_str());

	str += FString::FString("\ncurrent: ");
	switch (Cast<APlayerCharacter>(player)->GetCurrentActionMode())
	{
	case EPlayerActionMode::IsInLocker:
		str += FString::FString("IsInLocker >> ");
		break;
	case EPlayerActionMode::GetOutOfLocker:
		str += FString::FString("GetOutOfLocker >> ");
		break;
	case EPlayerActionMode::GoingIntoLocker:
		str += FString::FString("GoingIntoLocker >> ");
		break;
	default:
		str += FString::FString("Default >> ");
		break;
	}
	str += FString::FString("active: ");
	switch (playerActiveType)
	{
	case EPlayerActionMode::IsInLocker:
		str += FString::FString("IsInLocker\n");
		break;
	case EPlayerActionMode::GetOutOfLocker:
		str += FString::FString("GetOutOfLocker\n");
		break;
	case EPlayerActionMode::GoingIntoLocker:
		str += FString::FString("GoingIntoLocker\n");
		break;
	default:
		str += FString::FString("Default\n");
		break;
	}
	str += FString::FString(IsEyeArea() ? ">>>>>  IsEyeArea_IN  <<<<<\n" : ">>>>>  IsEyeArea_OUT  <<<<<\n");
	str += FString::FString(IsInLocker() ? ">>>>>  IsInLocker_IN  <<<<<\n" : ">>>>>  IsInLocker_OUT  <<<<<\n");

	for (int i = 0; i < courses.Num(); i++)
	{
		auto num = "[ " + std::to_string(i) + " ]";
		auto pos = "( " + std::to_string(courses[i].X) + ", ";
		pos += std::to_string(courses[i].Y) + ", ";
		pos += std::to_string(courses[i].Z) + ") ";

		auto c = ("\n" + FString::FString((num + pos).c_str()));
		str += c;
	}

	str += "\nChaseTime: " + FString::FString((std::to_string(chaseTimer)).c_str());
	str += " / " + FString::FString((std::to_string(chaseTime)).c_str());
	UKismetSystemLibrary::DrawDebugString(GetWorld(), GetActorLocation(), str, nullptr, FLinearColor::Blue, 0);
	// ----------------------------------------------------------------------------------------------------------------
}

// ロッカー処理
void AEnemy::InLocker()
{
	auto start = GetActorLocation();
	auto end = player->GetActorLocation();
	start.Z = Height();
	end.Z = Height();

	if (eyeLength < (end - start).Size())
	{
		TimerCheck(EPlayerActionMode::Default);
		return;
	}

	FHitResult hit;
	FCollisionQueryParams params;

	params.AddIgnoredActors(enemys);
	if (player != nullptr)
	{
		params.AddIgnoredActor(player);
		if (Cast<APlayerCharacter>(player))
		{
			auto p = Cast<APlayerCharacter>(player);
			auto action = p->GetCurrentActionMode();
			switch (action)
			{
			case EPlayerActionMode::IsInLocker:
			case EPlayerActionMode::GetOutOfLocker:
			case EPlayerActionMode::GoingIntoLocker:

				if (p->GetCurrentInLocker())
				{
					params.AddIgnoredActor(p->GetCurrentInLocker());
				}
			}
		}
	}

	if (GetWorld()->LineTraceSingleByChannel(hit, start, end,
	        ECollisionChannel::ECC_Visibility, params))
	{
		return;
	}

	// ロッカーIN
	if (Cast<APlayerCharacter>(player))
	{
		auto p = Cast<APlayerCharacter>(player);
		auto action = Cast<APlayerCharacter>(player)->GetCurrentActionMode();
		switch (action)
		{
		case EPlayerActionMode::GetOutOfLocker:
		case EPlayerActionMode::GoingIntoLocker:

			//if (playerActiveType != p->GetCurrentActionMode())
			//{
			//	courses = searchManager->ChaseCourse(GetActorLocation(), player->GetActorLocation());
			//}
			TimerCheck(p->GetCurrentActionMode());
			break;
		}
	}
}

//	視界に入っているかどうか
bool AEnemy::IsEyeArea()
{
	if (player == nullptr)
	{
		TimerCheck(EPlayerActionMode::Default);
		return false;
	}

	// ベクトルと角度の代入
	auto vector = VectorXY(player->GetActorLocation() - GetActorLocation());
	auto e_forward_deg = GetDeg_XY(GetActorForwardVector());
	auto ep_vector_deg = GetDeg_XY(vector);

	// 視野距離にいるか判定
	auto length = vector.Size();
	if (eyeLength < length)
	{
		TimerCheck(EPlayerActionMode::Default);
		return false;
	}

	// -360°～0°以下を0°～360°に変更
	e_forward_deg = (e_forward_deg < 0) ? (e_forward_deg + 360.0f) : (e_forward_deg);
	ep_vector_deg = (ep_vector_deg < 0) ? (ep_vector_deg + 360.0f) : (ep_vector_deg);

	auto deg = FMath::Abs(ep_vector_deg - e_forward_deg);
	deg = (180.0f < deg) ? (FMath::Abs(deg - 360.0f)) : (deg);

	FHitResult hit;
	FCollisionQueryParams params;
	params.AddIgnoredActors(enemys);
	if (player != nullptr)
	{
		params.AddIgnoredActor(player);
		if (IsInLocker())
		{
			if (Cast<APlayerCharacter>(player))
			{
				auto p = Cast<APlayerCharacter>(player);
				if (p->GetCurrentInLocker())
				{
					params.AddIgnoredActor(p->GetCurrentInLocker());
				}
			}
		}
	}

	if ((length < 500) || (deg <= FMath::Abs(eyeDeg / 2.0f)))
	{
		// プレイヤー、敵の二点間に障害物があるか判定
		auto start = GetActorLocation();
		auto end = player->GetActorLocation();
		start.Z = Height();
		end.Z = Height();

		if (GetWorld()->LineTraceSingleByChannel(hit, start, end,
		        ECollisionChannel::ECC_Visibility, params))
		{
			return false;
		}

		return true;
	}

	auto action = Cast<APlayerCharacter>(player)->GetCurrentActionMode();
	switch (action)
	{
	case EPlayerActionMode::IsInLocker:
	case EPlayerActionMode::GetOutOfLocker:
	case EPlayerActionMode::GoingIntoLocker:
		return IsInLocker();
		break;
	default:
		TimerCheck(EPlayerActionMode::Default);
		break;
	}
	return false;
}

// 衝突開始時に呼ばれる
void AEnemy::onComponentBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//音オブジェクトなら音が聞こえる範囲内に入ったことを表す
	if (Cast<ASoundObject>(OtherActor))
	{
		heardSound(Cast<ASoundObject>(OtherActor));
		return;
	}
}

// プレイヤー倒す処理
void AEnemy::PlayerKill()
{
	if (moveType == EMoveType::Kill)
	{
		return;
	}
	if (UMyGameInstance::GetInstance()->getClear())
	{
		return;
	}

	auto p = Cast<APlayerCharacter>(player);
	if (p->GetCurrentActionMode() == EPlayerActionMode::IsDying)
	{
		return;
	}

	auto pos = player->GetActorLocation() + (VectorXY(GetActorLocation() - player->GetActorLocation())).GetSafeNormal() * searchManager->GetRadius();
	pos.Z = 100;
	SetActorLocation(pos);

	p->ToDie(this);
	moveType = EMoveType::Kill;

	UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(ESoundType::Enemy_Shout, GetActorLocation(), this);
}

bool AEnemy::IsMove() const
{
	return ((moveType == EMoveType::Move) || (moveType == EMoveType::SE_Move) || (moveType == EMoveType::PlayerChase));
}
bool AEnemy::IsKill() const
{
	return (moveType == EMoveType::Kill);
}

bool AEnemy::IsInLocker()
{
	switch (playerActiveType)
	{
	//case EPlayerActionMode::IsInLocker:
	case EPlayerActionMode::GetOutOfLocker:
	case EPlayerActionMode::GoingIntoLocker:

		if (Cast<APlayerCharacter>(player))
		{
			auto p = Cast<APlayerCharacter>(player);
			auto action = p->GetCurrentActionMode();
			switch (action)
			{
			case EPlayerActionMode::IsInLocker:
			case EPlayerActionMode::GetOutOfLocker:
			case EPlayerActionMode::GoingIntoLocker:
				chaseTimer = chaseTime;
				return true; //(p->GetCurrentInLocker() != nullptr);
			}
		}
	}
	return false;
}

bool AEnemy::TimerCheck(EPlayerActionMode mode)
{
	// 時間設定がない、もしくは時間制限を迎えていなければそのまま代入
	if (limitTimer == nullptr || !limitTimer->IsTimeOver())
	{
		playerActiveType = mode;
		return false;
	}
	// 迎えていれば、プレイヤーを常に追跡させる
	auto action = Cast<APlayerCharacter>(player)->GetCurrentActionMode();
	switch (action)
	{
	case EPlayerActionMode::IsInLocker:
		playerActiveType = EPlayerActionMode::GoingIntoLocker;
		break;
	default:
		playerActiveType = action;
	}

	bool chaseStart = (moveType != EMoveType::PlayerChase);
	moveType = EMoveType::PlayerChase;
	chaseTimer = chaseTime;
	if (chaseStart)	
	{
		chasePlayer();
		constexpr float VIBRATION_DURATION = 1.5f;
		UMyGameInstance::GetInstance()->GetControllerVibration()->StartVibration(VIBRATION_DURATION, 1.0f);
		UMyGameInstance::GetInstance()->getSoundSystem()->PlayBGM(ESoundType::Chase_BGM);
	}
	return true;
}

//音が聞こえる範囲内に入った
void AEnemy::heardSound(ASoundObject* soundObject)
{
	if (!soundObject)
		return;
	switch (soundObject->getSoundType())
	{
		//バルブの音が聞こえた
	case ESoundType::Valve:
		//case ESoundType::Item_Get:
		//case ESoundType::Player_Walk_On_Puddle:
		searchPlayer(soundObject);
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("heard valve sound"));
		break;
	default:
		break;
	}
}

void AEnemy::playWalkSound(float deltaTime)
{
	//歩いているときに一定時間ごとに歩行音再生
	if (0 < courses.Num())
	{
		walkingSecond += deltaTime;

		//歩いている時間が一定量を超えたら再生する
		if (walkingSecond > WALKING_SOUND_PLAY_INTERVAL)
		{
			walkingSecond -= WALKING_SOUND_PLAY_INTERVAL;

			FHitResult hit;
			FCollisionQueryParams params;
			params.AddIgnoredActor(player);
			params.AddIgnoredActors(enemys);
			const FVector Start = GetActorLocation() + FVector(0, 0, 100);
			const FVector End = GetActorLocation() + FVector::DownVector * 1000.0f;
			if (!GetWorld()->LineTraceSingleByChannel(hit, Start, End,
			        ECollisionChannel::ECC_Visibility, params))
				return;
			const ESoundType sound = [&hit]() {
				//TODO:GamePlayTagで処理するのが望ましい
				//TODO:床と親クラスを一致させないと難しい
				if (hit.Actor->ActorHasTag(TEXT("Puddle")))
				{
					return ESoundType::Enemy_Walk_On_Puddle;
				}
				return ESoundType::Enemy_Walk;
			}();

			FVector seLocation = GetActorLocation();
			seLocation.Z = hit.Location.Z;
			UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(sound, seLocation, this);
		}
	}
	else
	{
		walkingSecond = 0.0f;
	}
}

// 水浴び処理
void AEnemy::overBathing()
{
	TArray<AActor*> actors;
	skeltal->GetOverlappingActors(actors);
	actors.RemoveAllSwap([](AActor* a) { return !a->ActorHasTag(TEXT("Sprinkler")); });

	for (int i = 0; i < actors.Num(); i++)
	{
		if (actors[i]->ActorHasTag(TEXT("Sprinkler")))
		{
			//extern ENGINE_API float GAverageFPS;
			AddReflection(1.0f /*/ GAverageFPS*/);
			ChangeStencilValueWhenPutOnWater();
		}
	}
}

//水をかぶった時のステンシル値の変更
void AEnemy::ChangeStencilValueWhenPutOnWater()
{
	{
		//ステンシル値を水をかぶった時用の値で和をとる
		const int32 Value = GetSilhouetteSkeltal()->CustomDepthStencilValue | static_cast<int32>(EStencilBitValue::SilhouetteWhenEnemyPutOnWater);
		GetSilhouetteSkeltal()->SetCustomDepthStencilValue(Value);
	}

	//最後に当たった時から有効にしたいので古いタイマーは破棄する
	FTimerManager& TimerManager = GetWorldTimerManager();
	TimerManager.ClearTimer(ReturnStencilValueWhenPutOnWaterHandle);
	TimerManager.SetTimer(ReturnStencilValueWhenPutOnWaterHandle, [&]() {
		const int32 Value = GetSilhouetteSkeltal()->CustomDepthStencilValue & ~static_cast<int32>(EStencilBitValue::SilhouetteWhenEnemyPutOnWater);
		GetSilhouetteSkeltal()->SetCustomDepthStencilValue(Value);
	},
	    VisibleTimeWhenEnemyPutOnWater, false);
}

void AEnemy::ChangeStencilValueWhenWalkOnPuddle()
{
	{
		const int32 Value = GetSilhouetteSkeltal()->CustomDepthStencilValue | static_cast<int32>(EStencilBitValue::SilhouetteWhenEnemyWalkOnPuddle);
		GetSilhouetteSkeltal()->SetCustomDepthStencilValue(Value);
	}

	//最後に当たった時から有効にしたいので古いタイマーは破棄する
	FTimerManager& TimerManager = GetWorldTimerManager();
	TimerManager.ClearTimer(ReturnStencilValueWhenWalkOnPuddle);
	TimerManager.SetTimer(ReturnStencilValueWhenWalkOnPuddle, [&]() {
		//ゲームが終了するなどしてスケルタルが参照できない場合に備えてチェックする
		const int32 Value = GetSilhouetteSkeltal()->CustomDepthStencilValue & ~static_cast<int32>(EStencilBitValue::SilhouetteWhenEnemyWalkOnPuddle);
		GetSilhouetteSkeltal()->SetCustomDepthStencilValue(Value);
	},
	    VisibleTimeWhenEnemyWalkOnPuddle, false);
}
