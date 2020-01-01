// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPGGameModeBase.h"
#include "MainGameModeBase.generated.h"

class AEntityBase;

/**
 * 
 */
UCLASS()
class CLIENT_API AMainGameModeBase : public ARPGGameModeBase
{
	GENERATED_UCLASS_BODY()

public:
	virtual void BeginPlay() override;

	/*
		��װ��½ʱ��Ҫ������KBE�¼�
	*/
	virtual void installEvents() override;

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
		void addSpaceGeometryMapping(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
		void onEnterWorld(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
		void onEnterSpace(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
		void onLeaveWorld(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
		void onLeaveSpace(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
		void set_position(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
		void set_direction(const UKBEventData* pEventData);

	/* KBE�¼�
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "KBEngine")
		void updatePosition(const UKBEventData* pEventData);


	//UFUNCTION(BlueprintCallable, Category = "KBEngine")
	//	AEntityBase* findGameEntity(int entityID);


};
