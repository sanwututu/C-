#include "stdafx.h"
#include "ConfigMgr.h"

CConfigMgr* CConfigMgr::m_pInstance = nullptr;
CConfigMgr* CConfigMgr::getInstance(){
	if (!m_pInstance){

		m_pInstance = new CConfigMgr();
	}
	return m_pInstance;
}
CConfigMgr::CConfigMgr()
{
	m_pLevelDtMgr = new CLevelDtMgr();
	m_pLevelDtMgr->loadFile("Configs/LevelDt.txt");
	m_pRoleDtMgr = new CRoleDtMgr();
	m_pRoleDtMgr->loadFile("Configs/RoleDt.txt");
	m_pNpcDtMgr = new CNpcDtMgr();
	m_pNpcDtMgr->loadFile("Configs/NpcDt.txt");
	m_pGoodsDtMgr = new CGoodsDtMgr();
	m_pGoodsDtMgr->loadFile("Configs/GoodsDt.txt");
	m_pMonsterDtMgr = new CMonsterDtMgr();
	m_pMonsterDtMgr->loadFile("Configs/MonsterDt.txt");
	m_pTaskDtMgr = new CTaskDtMgr();
	m_pTaskDtMgr->loadFile("Configs/TaskDt.txt");
}


CConfigMgr::~CConfigMgr()
{
	SAFE_DEL(m_pLevelDtMgr);
	SAFE_DEL(m_pRoleDtMgr);
	SAFE_DEL(m_pNpcDtMgr);
	SAFE_DEL(m_pGoodsDtMgr);
	SAFE_DEL(m_pMonsterDtMgr);
	SAFE_DEL(m_pTaskDtMgr);
}
void CConfigMgr::destroy(){
	SAFE_DEL(m_pInstance);
}
