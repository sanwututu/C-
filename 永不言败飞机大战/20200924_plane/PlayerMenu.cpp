#include "stdafx.h"
#include "PlayerMenu.h"
#include "GameMgr.h"


CPlayerMenu::CPlayerMenu()
:nPlayerState(E_MENU_START)
{
}
CPlayerMenu::~CPlayerMenu()
{
}
void CPlayerMenu::getValue(int nInHp,int nInAck){
	nHp = nInHp;
	nAck = nInAck;
}
void CPlayerMenu::update()
{
	SPlayerDt* config = new SPlayerDt();
	config = g_pConfigMgr->m_pPlayerDtMgr->getDataByID(nPlayerState+1);
	getValue(config->nHp,config->nAck);
	if (KEY_DOWN(VK_SPACE))
	{
		g_pGameMgr->setState(E_STATE_MAP);
		g_pGameMgr->m_pGameMap->g_Player->init(config);
		
	}
	else if (KEY_DOWN(VK_RIGHT))
	{
		nPlayerState--;
		if (nPlayerState < E_MENU_START)
		{
			nPlayerState = E_MENU_EXIT;
		}
	}
	else if (KEY_DOWN(VK_LEFT))
	{
		nPlayerState++;
		if (nPlayerState > E_MENU_EXIT)
		{
			nPlayerState = E_MENU_START;
		}
	}
}
void CPlayerMenu::render(){

		cout << "■■■■■■■■■■■■■■■■" << endl;
		cout << "■                            ■" << endl;
	if (E_MENU_START == nPlayerState)
	{
		cout << "■  □        战         法   ■" << endl;
		cout << "■□□□    战战战     法法法 ■" << endl;
		cout << "■ 白块      战士       法师  ■" << endl;
		cout << "■  ↑                        ■" << endl;
		
	}
	else if (E_MENU_SETTING == nPlayerState)
	{
		cout << "■  □        战         法   ■" << endl;
		cout << "■□□□    战战战     法法法 ■" << endl;
		cout << "■ 白块      战士       法师  ■" << endl;
		cout << "■            ↑              ■" << endl;
		
	}
	else
	{
		cout << "■  □        战         法   ■" << endl;
		cout << "■□□□    战战战     法法法 ■" << endl;
		cout << "■ 白块      战士       法师  ■" << endl;
		cout << "■                      ↑    ■" << endl;
		
	}
	
		cout << "■         HP  "<<nHp  <<"            ■" << endl;
		cout << "■        ACK  " <<nAck<<"             ■" << endl;
		cout << "■         按Space确认        ■" << endl;
		cout << "■                            ■" << endl;
		cout << "■■■■■■■■■■■■■■■■" << endl;

}