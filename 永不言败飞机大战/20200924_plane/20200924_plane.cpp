// 20200924_plane.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "GameMgr.h"
#include "ConfigMgr.h"

using namespace std;

CConfigMgr* g_pConfigMgr = new CConfigMgr();
CGameMgr* g_pGameMgr = new CGameMgr();

int _tmain(int argc, _TCHAR* argv[])
{
	while (true){
		g_pGameMgr->update();
		g_pGameMgr->render();

		system ("cls");
	}
	return 0;
}

