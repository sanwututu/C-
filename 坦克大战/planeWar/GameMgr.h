#pragma once
#include "GameMenu.h"
#include "GameMap.h"
#include "RoleSel.h"

struct SGameMgr
{
public:
	SGameMgr();
	//~SGameMgr();
	//������������ͷ�ļ��У�������ʵ����cpp��
	//��Ա����
	void update();
	void render();
	int nGameState;
	SGameMenu gameMenu;
	SGameMap gameMap;
	SRoleSel roleSel;
};
extern SGameMgr g_gameMgr;