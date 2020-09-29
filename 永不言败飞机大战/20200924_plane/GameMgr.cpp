#include "stdafx.h"
#include "GameMgr.h"


CGameMgr::CGameMgr()
:nGameState(E_STATE_MENU)
{	
	m_pGameMenu = new CGameMenu();
	m_pGameMap = new CGameMap();
	m_pPlayerMenu = new CPlayerMenu();
}
CGameMgr::~CGameMgr()
{
	SAFE_DEL(m_pGameMenu);
	SAFE_DEL(m_pGameMap);
	SAFE_DEL(m_pPlayerMenu);
}
//::×÷ÓÃÓò·û
void CGameMgr::update()
{
	if (E_STATE_MENU == nGameState)
	{
		m_pGameMenu->update();
	}
	else if (E_STATE_ROLE == nGameState){

		m_pPlayerMenu->update();
	}
	else if (E_STATE_MAP == nGameState)
	{
		m_pGameMap->update();
	}
}

void CGameMgr::render()
{
	if (E_STATE_MENU == nGameState)
	{
		m_pGameMenu->render();
	}
	else if (E_STATE_ROLE == nGameState){

		m_pPlayerMenu->render();
	}
	else if (E_STATE_MAP == nGameState)
	{
		m_pGameMap->render();
	}
}
void CGameMgr::setState(int nState)
{
	nGameState = nState;
}

int CGameMgr::getState()
{
	return nGameState;
}
