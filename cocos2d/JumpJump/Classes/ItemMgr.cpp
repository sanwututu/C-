#include "ItemMgr.h"

CItemMgr::CItemMgr()
:m_nTime(0){

}
CItemMgr::~CItemMgr(){

}

bool CItemMgr::init(){
	if (!Node::init()){
		return false;
	}
	this->schedule(CC_CALLBACK_1(CItemMgr::addCloud, this), "addCloud");
	return true;
}
void CItemMgr::addCloud(float fDelta){
	//
	m_nTime++;
	if (m_nTime > 120){
			CCloud* pCloud = CCloud::createCloud();
			this->addChild(pCloud);
			float fX = random() % 200+ 1000;
			float fY = random() % 100 + 380;
			pCloud->setPosition(fX, fY);
			pCloud->move();
			m_nTime = 0;
	}
	//float fX = Director::getInstance()->getWinSize().width;


}