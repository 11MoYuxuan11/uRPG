// Fill out your copyright notice in the Description page of Project Settings.


#include "EntityBase.h"
#include "Engine/KBEngine.h"
#include "Engine/Entity.h"

// Sets default values
AEntityBase::AEntityBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	entityID = 0;
	moveSpeed = 0.f;
	isOnGround = false;

	if (isPlayer())
	{
		AutoPossessPlayer = EAutoReceiveInput::Player0;
	}

}

// Called when the game starts or when spawned
void AEntityBase::BeginPlay()
{
	Super::BeginPlay();

	// ����UE4���ӻ�ʵ�崴��Ҫ����KBE�Ĳ�����߼�ʵ�壬��KBE���ʵ����ǰ�����Ѿ�������һЩ���������¼�
	// ��˴�ʱ���ǿ����Ѿ������һЩ�¼�������ֻ���ڴ˲��ȱ�Ҫ�Ĵ����ˣ� ���磺���ƺ�Ѫ������ֵ
	KBEngine::Entity* pEntity = KBEngine::KBEngineApp::getSingleton().findEntity(entityID);
	if (pEntity) {
		pEntity->callPropertysSetMethods();
	}
}

// Called every frame
void AEntityBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!isPlayer())
	{
		updateLocation(DeltaTime);
	}

}

// Called to bind functionality to input
void AEntityBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEntityBase::updateLocation(float DeltaTime)
{
	const FVector& currLocation = GetActorLocation();

	//Direction from Self to targetPos
	FVector vectorDirection = targetLocation - currLocation;

	//���ڷ���˽ű�moveSpeed�ĵ�λ�����ף�������Ҫת��ΪUE4��λ����
	float deltaSpeed = (moveSpeed * 10.f ) * DeltaTime;
	if (vectorDirection.Size() > deltaSpeed)
	{
		//Normalize Vector so it is just a direction
		vectorDirection.Normalize();

		//Move moveSpeed units toward the player, per tick
		SetActorLocation(currLocation + (vectorDirection * deltaSpeed));
	}
	else
	{
		SetActorLocation(targetLocation);
	}

	FaceRotation(targetRotator, DeltaTime);
}

