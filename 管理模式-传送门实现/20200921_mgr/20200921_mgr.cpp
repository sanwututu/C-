// 20200921_mgr.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "GameMgr.h"
#include "GameMap.h"

extern SGameMap g_Player;
using namespace std;
SGameMgr g_gameMgr;
int _tmain(int argc, _TCHAR* argv[])
{
	while (true){
		g_gameMgr.update();
		g_gameMgr.render();

		system ("cls");
	}
	return 0;
}

