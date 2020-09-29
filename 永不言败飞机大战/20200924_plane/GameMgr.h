#pragma once
#include "GameMenu.h"
#include "GameMap.h"
#include "PlayerMenu.h"

class CGameMgr
{
public:
	CGameMgr();
	//析构函数：当对象被delete时回调用该对象到析构函数
	~CGameMgr();
	//函数到声明在头文件中，函数到实现在cpp中
	//成员函数
	void setState(int nGameState);
	//get接口:获取私有成员变量到值
	int getState();
	void update();
	void render();
	CGameMenu* m_pGameMenu;
	CGameMap* m_pGameMap;
	CPlayerMenu* m_pPlayerMenu;

private:
	int nGameState;
	
	
};
extern CGameMgr* g_pGameMgr;