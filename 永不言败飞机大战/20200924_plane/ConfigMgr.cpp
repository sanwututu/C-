#include "stdafx.h"
#include "ConfigMgr.h"


CConfigMgr::CConfigMgr()
{
	m_pLevelDtMgr = new CLevelDtMgr();
	m_pLevelDtMgr->loadFile("Configs/LevelDt.txt");
	m_pBulletDtMgr = new CBulletDtMgr();
	m_pBulletDtMgr->loadFile("Configs/BulletDt.txt");
	m_pEnemyDtMgr = new CEnemyDtMgr();
	m_pEnemyDtMgr->loadFile("Configs/EnemyDt.txt");
	m_pPlayerDtMgr = new CPlayerDtMgr();
	m_pPlayerDtMgr->loadFile("Configs/PlayerDt.txt");
}


CConfigMgr::~CConfigMgr()
{
	SAFE_DEL(m_pLevelDtMgr);
	SAFE_DEL(m_pBulletDtMgr);
	SAFE_DEL(m_pEnemyDtMgr);
	SAFE_DEL(m_pPlayerDtMgr);

}
