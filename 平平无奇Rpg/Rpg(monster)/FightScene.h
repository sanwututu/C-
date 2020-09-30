#pragma once
#include "DataClass.h"
#include "Player.h"
#include "Monster.h"
class CFightScene
{
public:
	CFightScene();
	~CFightScene();

	CMonster* getMonster();
	CPlayer* getPlayer();
	void update();
	void refresh(int nMonsterID);
	void render();
private:
	int m_nState;
	int m_nFightState;
	CMonster* pMonster;
	CPlayer* pPlayer;
};

