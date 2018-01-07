﻿#ifndef __EQUIPMENT_MODULE_H__
#define __EQUIPMENT_MODULE_H__
#include "ModuleBase.h"
#include "../ServerData/EquipData.h"
#include "../ServerData/ServerDefine.h"
#include "../Message/Game_Define.pb.h"
struct EquipDataObject;
class CEquipModule  : public CModuleBase
{
public:
	CEquipModule(CPlayerObject* pOwner);

	~CEquipModule();

public:
	BOOL OnCreate(UINT64 u64RoleID);

	BOOL OnDestroy();

	BOOL OnLogin();

	BOOL OnLogout();

	BOOL OnNewDay();

	BOOL ReadFromDBLoginData(DBRoleLoginAck& Ack);

	BOOL SaveToClientLoginData(RoleLoginAck& Ack);

	BOOL CalcFightValue(INT32 nValue[PROPERTY_NUM], INT32 nPercent[PROPERTY_NUM], INT32& FightValue);

public:
	UINT64 AddEquip(UINT32 dwEquipID);

	BOOL NotifyChange();

	EquipDataObject* GetEquipByGuid(UINT64 uGuid);

	UINT32 SetDressEquip(UINT64 uGuid, BOOL bDress);

public:
	std::map<UINT64, EquipDataObject*>m_mapEquipData;
	EquipDataObject* m_vtDressEquip[EEP_MAX];

	std::set<UINT64> m_setChange;
	std::set<UINT64> m_setRemove;


};

#endif //__EQUIPMENT_MODULE_H__
