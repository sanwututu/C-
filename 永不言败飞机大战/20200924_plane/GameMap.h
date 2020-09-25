#pragma once
#include"Player.h"
#include "BulletMgr.h"
#include "ConfigMgr.h"
#include "EnemyMgr.h"

struct SGameMap
{
public:  
	SGameMap();
	//~SGameMap();
	void update();
	void render();
	SLevelDt levelDt;
	SEnemyDt enemyDt;
	SPlayer g_Player;
	SBulletMgr g_bulletMgr;
	SEnemyMgr g_enemyMgr;

};

