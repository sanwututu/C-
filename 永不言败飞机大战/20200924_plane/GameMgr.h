#pragma once
#include "GameMenu.h"
#include "GameMap.h"
#include "PlayerMenu.h"

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
	SPlayerMenu playerMenu;
};
extern SGameMgr g_gameMgr;