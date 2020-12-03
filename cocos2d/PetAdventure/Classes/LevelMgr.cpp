#include "LevelMgr.h"
#include "ConfigMgr.h"
#include "GameScene.h"
#include "HomeScene.h"

CLevelMgr* CLevelMgr::m_pInstance = nullptr;
CLevelMgr::CLevelMgr()
:m_nLevelID(0)
, m_pLevelDt(nullptr)
{

}

CLevelMgr::~CLevelMgr()
{

}

CLevelMgr* CLevelMgr::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new CLevelMgr();
	}
	return m_pInstance;
}

void CLevelMgr::changScene()
{
	m_pLevelDt = static_cast<SLevelDt*>(CConfigMgr::getInstance()->getData("LevelDtMgr")->getDataByID(m_nLevelID));
	CGameScene::destroy();
	Director::getInstance()->replaceScene(CGameScene::getInstance());
}

void CLevelMgr::nextScene()
{
	int nSize = CConfigMgr::getInstance()->getData("LevelDtMgr")->getSize();

	if (m_nLevelID >= 1000 + nSize){
		CGameScene::destroy();
		Director::getInstance()->replaceScene(CHomeScene::create());
		return;
	}
	m_nLevelID++;
	m_pLevelDt = static_cast<SLevelDt*>(CConfigMgr::getInstance()->getData("LevelDtMgr")->getDataByID(m_nLevelID));
	
	
	
	CGameScene::destroy();
	Director::getInstance()->replaceScene(CGameScene::getInstance());
}
void CLevelMgr::setLevelID(int nLevel)
{
	m_nLevelID = nLevel;
	m_pLevelDt = static_cast<SLevelDt*>(CConfigMgr::getInstance()->getData("LevelDtMgr")->getDataByID(m_nLevelID));
}
