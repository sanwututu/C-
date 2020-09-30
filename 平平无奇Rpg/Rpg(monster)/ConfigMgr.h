#pragma once
#include "DataClass.h"

class CConfigMgr
{
public:
	CConfigMgr();
	~CConfigMgr();

	CLevelDtMgr* m_pLevelDtMgr;
	CRoleDtMgr* m_pRoleDtMgr;
	CNpcDtMgr* m_pNpcDtMgr;
	CGoodsDtMgr* m_pGoodsDtMgr;
	CMonsterDtMgr* m_pMonsterDtMgr;

};

extern CConfigMgr* g_pConfigMgr;