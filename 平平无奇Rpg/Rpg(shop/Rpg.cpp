// Rpg.cpp : �������̨Ӧ�ó������ڵ㡣
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

