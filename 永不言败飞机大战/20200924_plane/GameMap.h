#pragma once
#include"Player.h"
#include "BulletMgr.h"
#include "ConfigMgr.h"
#include "EnemyMgr.h"

class CGameMap
{
public:  
	CGameMap();
	~CGameMap();
	void update();
	void render();
	SLevelDt* m_pLevelDt;
	SEnemyDt* enemyDt;
	CPlayer* g_Player;
	CBulletMgr* g_bulletMgr;
	CEnemyMgr* g_enemyMgr;

};

