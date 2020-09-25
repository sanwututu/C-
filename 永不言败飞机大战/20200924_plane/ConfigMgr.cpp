#include "stdafx.h"
#include "ConfigMgr.h"


SConfigMgr::SConfigMgr()
{
	levelDtMgr.loadFile("Configs/LevelDt.txt");
	bulletDtMgr.loadFile("Configs/BulletDt.txt");
	enemyDtMgr.loadFile("Configs/EnemyDt.txt");
	playerDtMgr.loadFile("Configs/PlayerDt.txt");
}


SConfigMgr::~SConfigMgr()
{
}
