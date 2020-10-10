// Rpg.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "GameMgr.h"
#include "ConfigMgr.h"

int _tmain(int argc, _TCHAR* argv[])
{
	while (true)
	{
		CGameMgr::getInstance()->update();
		CGameMgr::getInstance()->render();
		system("cls");
	}
	CGameMgr::destroy();
	CConfigMgr::destroy();
}

