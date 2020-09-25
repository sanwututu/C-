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
	SPlayerDtMgr playerDtMgr;
};

extern SConfigMgr g_configMgr;