#include "StarMgr.h"
#include "ConfigMgr.h"

CStarMgr::CStarMgr()
:m_nTime(0), m_nTimeControl(80), m_nSpeed(4)
{
}
CStarMgr::~CStarMgr(){

}

bool CStarMgr::init(){
	if (!Node::init()){
		return false;
	}
	this->schedule(CC_CALLBACK_1(CStarMgr::addStar, this), "addStar");

	return true;
}
void CStarMgr::addStar(float fDelta){
	//
	m_nTime++;
	if (m_nTime > m_nTimeControl){
			int nID = random() % 4 + 2001;
			SStarDt* pConfig = static_cast<SStarDt*>(CConfigMgr::getInstance()->getData("StarDtMgr")->getDataByID(nID));
			CStar* pStar = CStar::createWithData(pConfig);
			this->addChild(pStar);
			float fX = Director::getInstance()->getWinSize().width + 30;
			float fY = 200;
			pStar->setPosition(fX, fY);
			pStar->setAnchorPoint(Vec2(0.5, 0.5));
			pStar->move(m_nSpeed);
			m_nTime = 0;
	}
	//float fX = Director::getInstance()->getWinSize().width;
	
	
}