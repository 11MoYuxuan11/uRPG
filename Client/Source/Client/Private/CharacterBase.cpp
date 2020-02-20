// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<URPGAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	// �������Լ�
	AttributeSet = CreateDefaultSubobject<UCoreAttributeSet>(TEXT("AttributeSet"));

	bAbilitiesInitialized = false;
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacterBase::AddStartupGameplayAbilities()
{
	check(AbilitySystemComponent);

	if (Role == ROLE_Authority && !bAbilitiesInitialized)
	{
		//TODO ��ʼ��Ability��Effect
	}
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//TODO ������س�ʼ��

	//���ܳ�ʼ��
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		AddStartupGameplayAbilities();
	}
}

void ACharacterBase::UnPossessed()
{
}

void ACharacterBase::OnRep_Controller()
{
	Super::OnRep_Controller();

	// ������Ϊ�������ı��ˣ����뽫AS����ϵ�ActorInfo����һ��
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->RefreshAbilityActorInfo();
	}
}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

float ACharacterBase::GetHealth() const
{
	return AttributeSet->GetHealth();
}

float ACharacterBase::GetMaxHealth() const
{
	return AttributeSet->GetMaxHealth();
}

