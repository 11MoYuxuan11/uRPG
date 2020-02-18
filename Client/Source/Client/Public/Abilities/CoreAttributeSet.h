// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "CoreAttributeSet.generated.h"

/**
 * �������Լ�
 */
UCLASS()
class CLIENT_API UCoreAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UCoreAttributeSet();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Attributes")
	FGameplayAttributeData Health;
};
