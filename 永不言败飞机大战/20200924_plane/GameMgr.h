#pragma once
#include "GameMenu.h"
#include "GameMap.h"
#include "PlayerMenu.h"

struct SGameMgr
{
public:
	SGameMgr();
	//~SGameMgr();
	//函数到声明在头文件中，函数到实现在cpp中
	//成员函数
	void update();
	void render();
	int nGameState;
	SGameMenu gameMenu;
	SGameMap gameMap;
	SPlayerMenu playerMenu;
};
extern SGameMgr g_gameMgr;