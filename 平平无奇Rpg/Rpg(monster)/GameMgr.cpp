#include "stdafx.h"
#include "GameMgr.h"


CGameMgr::CGameMgr()
:m_nState(E_STATE_MENU)
{

}


void CGameMgr::init()
{
	m_pGameMenu = new CGameMenu();
	m_pSelRole = new CSelRole();
	m_pGameMap = new CGameMap();
	m_pShop = new CShop();
	m_pFightScene = new CFightScene();
}

CGameMgr::~CGameMgr()
{
	SAFE_DEL(m_pGameMenu);
	SAFE_DEL(m_pGameMap);
	SAFE_DEL(m_pSelRole);
	SAFE_DEL(m_pShop);
	SAFE_DEL(m_pFightScene);
}

void CGameMgr::update()
{
	if (E_STATE_MENU == m_nState)
	{
		m_pGameMenu->update();
	}
	else if (E_STATE_ROLE == m_nState)
	{
		m_pSelRole->update();
	}
	else if (E_STATE_MAP == m_nState)
	{
		m_pGameMap->update();
	}
	else if (E_STATE_SHOP == m_nState)
	{
		m_pShop->update();
	}
	else if (E_STATE_FIGHT == m_nState)
	{
		m_pFightScene->update();
	}
}

void CGameMgr::render()
{
	if (E_STATE_MENU == m_nState)
	{
		m_pGameMenu->render();
	}
	else if (E_STATE_ROLE == m_nState)
	{
		m_pSelRole->render();
	}
	else if (E_STATE_MAP == m_nState)
	{
		m_pGameMap->render();
	}
	else if (E_STATE_SHOP == m_nState){
		m_pShop->render();
	}
	else if (E_STATE_FIGHT == m_nState)
	{
		m_pFightScene->render();
	}
}

void CGameMgr::setState(int nState)
{
	m_nState = nState;
}

int CGameMgr::getState()
{
	return m_nState;
}
CGameMap* CGameMgr::getGameMap()
{
	return m_pGameMap;
}
CShop* CGameMgr::getShop()
{
	return m_pShop;
}
CFightScene* CGameMgr::getFightScene()
{
	return m_pFightScene;
}