// PlaneWar.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "GameMgr.h"
#include "ConfigMgr.h"

using namespace std;


SConfigMgr g_configMgr;
SGameMgr g_gameMgr;
int _tmain(int argc, _TCHAR* argv[])
{
	while (true)
	{
		g_gameMgr.update();
		g_gameMgr.render();
		system("cls");
	}
	return 0;
}

