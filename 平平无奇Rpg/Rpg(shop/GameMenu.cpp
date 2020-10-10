#include "stdafx.h"
#include "GameMenu.h"
#include "GameMgr.h"

CGameMenu::CGameMenu()
:m_nState(E_MENU_START)
{
}


CGameMenu::~CGameMenu()
{
}

void CGameMenu::update()
{
	if (KEY_DOWN(VK_RETURN))
	{
		if (E_MENU_START == m_nState)
		{
			//cout << g_pGameMgr->getState() << endl;
			
// 			int nState = g_pGameMgr->getState();
// 			nState = E_STATE_MAP;//����
			CGameMgr::getInstance()->setState(E_STATE_ROLE);
			//g_pGameMgr->m_nState = E_STATE_MAP;
			//g_gameMgr.nGameState = E_GAME_SEL;
		}

	}
	else if (KEY_DOWN(VK_UP))
	{
		m_nState--;
		if (m_nState < E_MENU_START)
		{
			m_nState = E_MENU_EXIT;
		}
	}
	else if (KEY_DOWN(VK_DOWN))
	{
		m_nState++;
		if (m_nState > E_MENU_EXIT)
		{
			m_nState = E_MENU_START;
		}
	}
}

void CGameMenu::render()
{
	cout << "������������������������������" << endl;
	cout << "������������������������������" << endl;
	if (E_MENU_START == m_nState)
	{
		cout << "������    ->��Ϸ��ʼ    ������" << endl;
		cout << "������      ��Ϸ����    ������" << endl;
		cout << "������      ��Ϸ�˳�    ������" << endl;
	}
	else if (E_MENU_SETTING == m_nState)
	{
		cout << "������      ��Ϸ��ʼ    ������" << endl;
		cout << "������    ->��Ϸ����    ������" << endl;
		cout << "������      ��Ϸ�˳�    ������" << endl;
	}
	else
	{
		cout << "������      ��Ϸ��ʼ    ������" << endl;
		cout << "������      ��Ϸ����    ������" << endl;
		cout << "������    ->��Ϸ�˳�    ������" << endl;
	}
	cout << "������������������������������" << endl;
	cout << "������������������������������" << endl;
}
