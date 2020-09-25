#include "stdafx.h"
#include "PlayerMenu.h"
#include "GameMgr.h"


SPlayerMenu::SPlayerMenu()
{
	nPlayerState = E_MENU_START;
}
SPlayerMenu::~SPlayerMenu()
{
}

void SPlayerMenu::update()
{

	SPlayerDt config = g_configMgr.playerDtMgr.getDataByID(nPlayerID);
	if (KEY_DOWN(VK_SPACE))
	{
		if (E_MENU_START == nPlayerState){
			g_gameMgr.nGameState = 2;
			g_gameMgr.gameMap.g_Player.init(config);
		}
		else if (E_MENU_SETTING == nPlayerState){
			g_gameMgr.nGameState = 2;
			g_gameMgr.gameMap.g_Player.init(config);
		}
		else if (E_MENU_EXIT == nPlayerState){
			g_gameMgr.nGameState = 2;
			g_gameMgr.gameMap.g_Player.init(config);
		}
			
		
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
void SPlayerMenu::render(){

	SPlayerDt config = g_configMgr.playerDtMgr.getDataByID(nPlayerID);
		cout << "��������������������������������" << endl;
		cout << "��                            ��" << endl;
	if (E_MENU_START == nPlayerState)
	{
		cout << "��  ��        ս         ��   ��" << endl;
		cout << "��������    սսս     ������ ��" << endl;
		cout << "�� �׿�      սʿ       ��ʦ  ��" << endl;
		cout << "��  ��                        ��" << endl;
		nPlayerID = 1;
	}
	else if (E_MENU_SETTING == nPlayerState)
	{
		cout << "��  ��        ս         ��   ��" << endl;
		cout << "��������    սսս     ������ ��" << endl;
		cout << "�� �׿�      սʿ       ��ʦ  ��" << endl;
		cout << "��            ��              ��" << endl;
		nPlayerID =2;
	}
	else
	{
		cout << "��  ��        ս         ��   ��" << endl;
		cout << "��������    սսս     ������ ��" << endl;
		cout << "�� �׿�      սʿ       ��ʦ  ��" << endl;
		cout << "��                      ��    ��" << endl;
		nPlayerID = 3;
	}
	
		cout << "��         HP  "<<config.nHp  <<"            ��" << endl;
		cout << "��        ACK  " <<config.nAck<<"             ��" << endl;
		cout << "��         ��Spaceȷ��        ��" << endl;
		cout << "��                            ��" << endl;
		cout << "��������������������������������" << endl;

}