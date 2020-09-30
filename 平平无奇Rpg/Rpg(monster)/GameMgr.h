#pragma once
#include "GameMenu.h"
#include "SelRole.h"
#include "GameMap.h"
#include "Shop.h"
#include "FightScene.h"
class CGameMgr
{
//公有的
public:
	//构造函数
	CGameMgr();
	//析构函数：当对象被delete时回调用该对象到析构函数
	~CGameMgr();

	void init();
	//修改用set,获取用get
	//set接口:供外部用于修改私有成员变量
	void setState(int nState);
	//get接口:获取私有成员变量到值
	int getState();
	CGameMap* getGameMap();
	CShop* getShop();
	CFightScene* getFightScene();
	void update();
	void render();
	//menber
//保护的:自己和子类对象能访问
//protected:
//私有的
private:
	int m_nState;
	CGameMenu* m_pGameMenu;
	CSelRole* m_pSelRole;
	CGameMap* m_pGameMap;
	CShop* m_pShop;
	CFightScene* m_pFightScene;
};

extern CGameMgr* g_pGameMgr;