#include "stdafx.h"
#include "GameMgr.h"

CGameMgr* CGameMgr::m_pInstance = nullptr;
CGameMgr::CGameMgr()
:m_nState(E_STATE_MENU)
{

}
CGameMgr* CGameMgr::getInstance(){
	if (!m_pInstance){

		m_pInstance = new CGameMgr();
		m_pInstance->init();

	}
	return m_pInstance;
}
void CGameMgr::destroy(){

	SAFE_DEL(m_pInstance);
}
void CGameMgr::init()
{
	m_pGameMenu = new CGameMenu();
	m_pSelRole = new CSelRole();
	m_pGameMap = new CGameMap();
	m_pShop = new CShop();
	m_pFightScene = new CFightScene();
	m_pBackPack = new CBackPack();
	m_pStatusPanel = new CStatusPanel();
	m_pTaskPanel = new CTaskPanel();
}

CGameMgr::~CGameMgr()
{
	SAFE_DEL(m_pGameMenu);
	SAFE_DEL(m_pGameMap);
	SAFE_DEL(m_pSelRole);
	SAFE_DEL(m_pShop);
	SAFE_DEL(m_pFightScene);
	SAFE_DEL(m_pBackPack);
	SAFE_DEL(m_pStatusPanel);
	SAFE_DEL(m_pTaskPanel);
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
	else if (E_STATE_BACKPACK == m_nState)
	{
		m_pBackPack->update();
	}
	else if (E_STATE_STATUSPANEL == m_nState)
	{
		m_pStatusPanel->update();
	}
	else if (E_STATE_TASK == m_nState)
	{
		m_pTaskPanel->update();
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
	else if (E_STATE_BACKPACK == m_nState)
	{
		m_pBackPack->render();
	}
	else if (E_STATE_STATUSPANEL == m_nState)
	{
		m_pStatusPanel->render();
	}
	else if (E_STATE_TASK == m_nState)
	{
		m_pTaskPanel->render();
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
CBackPack*  CGameMgr::getBackPack(){
	return m_pBackPack;
}
CStatusPanel* CGameMgr::getStatusPanel(){
	return m_pStatusPanel;
}
CTaskPanel* CGameMgr::getTaskPanel(){
	return m_pTaskPanel;
}