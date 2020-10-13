#pragma once
#include "Player.h"
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
	SPlayer player;
	SBulletMgr bulletMgr;
	SEnemyMgr enemyMgr;
};

