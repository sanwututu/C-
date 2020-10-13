#pragma once
#include "DataStruct.h"

struct SConfigMgr
{
public:
	SConfigMgr();
	~SConfigMgr();


	SLevelDtMgr levelDtMgr;
	SBulletDtMgr bulletDtMgr;
	SEnemyDtMgr enemyDtMgr;
	SRoleDtMgr roleDtMgr;
};

extern SConfigMgr g_configMgr;