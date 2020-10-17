// Rpg2.0.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Director.h"
#include "GameMenu.h"
#include "MenuNode.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//菜单场景
	CGameMenu* pGameMenu = CGameMenu::create();
	//菜单优先要显示的节点
	CMenuNode* pMenuNode = CMenuNode::create();
	//菜单的显示节点要放到菜单场景里面
	pGameMenu->addChild(pMenuNode);
	CDirector::getInstance()->replaceScene(pGameMenu);
	//导演在要把游戏运行起来之前，需要知道第一场景是什么。
	CDirector::getInstance()->run();
	return 0;
}

