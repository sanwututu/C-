#include "stdafx.h"
#include "GameMenu.h"
#include "GameMgr.h"

//
enum
{
	E_MENU_START,
	E_MENU_SETTING,
	E_MENU_EXIT
};

SGameMenu::SGameMenu()
{
	nMenuState = E_MENU_START;
}

void SGameMenu::update()
{
	if (KEY_DOWN(VK_RETURN))
	{
		if (E_MENU_START == nMenuState)
		{
			g_gameMgr.nGameState = E_GAME_SEL;
		}

	}
	else if (KEY_DOWN(VK_UP))
	{
		nMenuState--;
		if (nMenuState < E_MENU_START)
		{
			nMenuState = E_MENU_EXIT;
		}
	}
	else if (KEY_DOWN(VK_DOWN))
	{
		nMenuState++;
		if (nMenuState > E_MENU_EXIT)
		{
			nMenuState = E_MENU_START;
		}
	}
}

void SGameMenu::render()
{
	cout << "������������������������������" << endl;
	cout << "������������������������������" << endl;
	if (E_MENU_START == nMenuState)
	{
		cout << "������    ->��Ϸ��ʼ    ������" << endl;
		cout << "������      ��Ϸ����    ������" << endl;
		cout << "������      ��Ϸ�˳�    ������" << endl;
	}
	else if (E_MENU_SETTING == nMenuState)
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
