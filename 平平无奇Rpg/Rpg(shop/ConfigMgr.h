#pragma once
#include "DataClass.h"

class CConfigMgr
{
public:
	~CConfigMgr();

	static CConfigMgr* getInstance();
	static void destroy();
	CLevelDtMgr* m_pLevelDtMgr;
	CRoleDtMgr* m_pRoleDtMgr;
	CNpcDtMgr* m_pNpcDtMgr;
	CGoodsDtMgr* m_pGoodsDtMgr;
	CMonsterDtMgr* m_pMonsterDtMgr;
	CTaskDtMgr* m_pTaskDtMgr;
private:
	CConfigMgr();
	static CConfigMgr* m_pInstance;

};
