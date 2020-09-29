#pragma once
#include "DataStruct.h"

class CConfigMgr
{
public:
	CConfigMgr();
	~CConfigMgr();

	CLevelDtMgr* m_pLevelDtMgr;
	CBulletDtMgr* m_pBulletDtMgr;
	CEnemyDtMgr* m_pEnemyDtMgr;
	CPlayerDtMgr* m_pPlayerDtMgr;
};

extern CConfigMgr* g_pConfigMgr;