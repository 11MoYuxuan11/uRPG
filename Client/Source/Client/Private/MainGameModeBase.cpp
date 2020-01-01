// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameModeBase.h"
#include "Engine/KBEngine.h"
#include "Engine/Entity.h"
#include "EntityBase.h"

AMainGameModeBase::AMainGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AMainGameModeBase::installEvents()
{
	Super::installEvents();

	// in world
	// ����¼�����ʱ������Ҫ�л���ͼ����Ϸ�����ͼ
	KBENGINE_REGISTER_EVENT(KBEngine::KBEventTypes::addSpaceGeometryMapping, addSpaceGeometryMapping);
	KBENGINE_REGISTER_EVENT(KBEngine::KBEventTypes::onEnterWorld, onEnterWorld);
	KBENGINE_REGISTER_EVENT(KBEngine::KBEventTypes::onLeaveWorld, onLeaveWorld);
	KBENGINE_REGISTER_EVENT(KBEngine::KBEventTypes::onEnterSpace, onEnterSpace);
	KBENGINE_REGISTER_EVENT(KBEngine::KBEventTypes::onLeaveSpace, onLeaveSpace);
	KBENGINE_REGISTER_EVENT(KBEngine::KBEventTypes::set_position, set_position);
	KBENGINE_REGISTER_EVENT(KBEngine::KBEventTypes::set_direction, set_direction);
	KBENGINE_REGISTER_EVENT(KBEngine::KBEventTypes::updatePosition, updatePosition);
	//KBENGINE_REGISTER_EVENT(KBEngine::KBEventTypes::onControlled, onControlled);

	// in world(register by scripts)
	//KBENGINE_REGISTER_EVENT("set_HP", set_HP);
	//KBENGINE_REGISTER_EVENT("set_MP", set_MP);
	//KBENGINE_REGISTER_EVENT("set_HP_Max", set_HP_Max);
	//KBENGINE_REGISTER_EVENT("set_MP_Max", set_MP_Max);
	//KBENGINE_REGISTER_EVENT("set_level", set_level);
	//KBENGINE_REGISTER_EVENT("set_name", set_name);
	//KBENGINE_REGISTER_EVENT("set_moveSpeed", set_moveSpeed);
	//KBENGINE_REGISTER_EVENT("set_modelScale", set_modelScale);
	//KBENGINE_REGISTER_EVENT("set_modelID", set_modelID);
	//KBENGINE_REGISTER_EVENT("set_entityNO", set_entityNO);
	//KBENGINE_REGISTER_EVENT("set_flags", set_flags);
	//KBENGINE_REGISTER_EVENT("set_state", set_state);
	//KBENGINE_REGISTER_EVENT("set_subState", set_subState);
	//KBENGINE_REGISTER_EVENT("set_forbids", set_forbids);
	//KBENGINE_REGISTER_EVENT("recvDamage", recvDamage);
	//KBENGINE_REGISTER_EVENT("otherAvatarOnJump", otherAvatarOnJump);
	//KBENGINE_REGISTER_EVENT("onAddSkill", onAddSkill);
}

void AMainGameModeBase::BeginPlay() {
	Super::BeginPlay();
	check(KBEngine::KBEngineApp::getSingleton().isInitialized());

	// ����Ѿ��б�������ʵ�壬˵����������һ������δ���ü���ת֮ǰ�Ѿ�֪ͨ������
	// ���������ǵ�world������û�����ü��������ⲿ��ʵ����������¼��Ѿ�©��
	// ��ʱ������Ҫ�ٴδ���һ��onEnterWorld���ñ��ֲ��ܹ�����Ϸ�����д��������е�ʵ��
	KBEngine::KBEngineApp::ENTITIES_MAP& entities = KBEngine::KBEngineApp::getSingleton().entities();
	for (auto& item : entities)
	{
		KBEngine::Entity* pEntity = item.Value;

		UKBEventData_onEnterWorld* pEventData = NewObject<UKBEventData_onEnterWorld>();
		pEventData->entityID = pEntity->id();
		pEventData->spaceID = KBEngine::KBEngineApp::getSingleton().spaceID();
		KBPos2UE4Pos(pEventData->position, pEntity->position);
		pEventData->direction = pEntity->direction;
		pEventData->moveSpeed = pEntity->velocity();
		pEventData->isOnGround = pEntity->isOnGround();
		pEventData->isPlayer = pEntity->isPlayer();
		pEventData->entityClassName = pEntity->className();
		pEventData->res = TEXT("");
		KBENGINE_EVENT_FIRE(KBEngine::KBEventTypes::onEnterWorld, pEventData);
	}
}

void AMainGameModeBase::addSpaceGeometryMapping_Implementation(const UKBEventData* pEventData)
{

}

void AMainGameModeBase::onEnterWorld_Implementation(const UKBEventData* pEventData)
{

}

void AMainGameModeBase::onLeaveWorld_Implementation(const UKBEventData* pEventData)
{

}

void AMainGameModeBase::onEnterSpace_Implementation(const UKBEventData* pEventData)
{

}

void AMainGameModeBase::onLeaveSpace_Implementation(const UKBEventData* pEventData)
{

}

void AMainGameModeBase::updatePosition_Implementation(const UKBEventData* pEventData)
{

}

void AMainGameModeBase::set_position_Implementation(const UKBEventData* pEventData)
{

}

void AMainGameModeBase::set_direction_Implementation(const UKBEventData* pEventData)
{

}


//AEntityBase* AMainGameModeBase::findGameEntity(int entityID)
//{
//	AEntityBase** pGameEntity = gameEntities.Find(entityID);
//	if (pGameEntity)
//		return *pGameEntity;
//
//	return NULL;
//}