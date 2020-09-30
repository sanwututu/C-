#pragma once
#include "ConfigMgr.h"
#include "Player.h"
#include "NpcMgr.h"
#include "MonsterMgr.h"

class CGameMap
{
public:
	CGameMap();
	~CGameMap();
	CPlayer* getPlayer();
	CMonsterMgr* getMonsterMgr();
	void update();
	void render();

private:
	CPlayer* m_pPlayer;
	CNpcMgr* m_pNpcMgr;
	CMonsterMgr* m_pMonsterMgr;
	SLevelDt* m_pLevelDt;
};

