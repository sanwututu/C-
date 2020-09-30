// Rpg.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "GameMgr.h"
#include "ConfigMgr.h"

CConfigMgr* g_pConfigMgr = new CConfigMgr();
CGameMgr* g_pGameMgr = new CGameMgr();
int _tmain(int argc, _TCHAR* argv[])
{
	g_pGameMgr->init();
	while (true)
	{
		g_pGameMgr->update();
		g_pGameMgr->render();
		system("cls");
	}
	SAFE_DEL(g_pGameMgr);
	SAFE_DEL(g_pConfigMgr);
// 	if (g_pConfigMgr)
// 	{
// 		delete g_pConfigMgr;
// 		g_pConfigMgr = nullptr;
// 	}
	if (g_pGameMgr)
	{
		delete g_pGameMgr;
		g_pGameMgr = nullptr;
	}
	return 0;
}

