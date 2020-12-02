#include "MoonMgr.h"

CMoonMgr::CMoonMgr()
:m_fSpeed(30){

}
CMoonMgr::~CMoonMgr(){

}
bool CMoonMgr::init(){
	if (!Node::init()){
		return false;
	}
	//
	this->createMoon();
	this->scheduleUpdate();
	return true;
}
void CMoonMgr::createMoon(){
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	m_pMoon = Sprite::create("Image/moon.png");
	m_pMoon->setAnchorPoint(Vec2(0.5, 0.5));
	m_pMoon->setPosition(origin.x + visibleSize.width/2, -270);
	m_pMoon->setScale(2);
	this->addChild(m_pMoon);
	//»Ò³¾
	
}
void CMoonMgr::update(float delta){

	auto visibleSize = Director::getInstance()->getVisibleSize();
	float fRotation = m_pMoon->getRotation();
	fRotation -= m_fSpeed*delta;
	m_pMoon->setRotation(fRotation);

	if (fRotation > 360){
		m_pMoon->setRotation(0);
	}
}
void CMoonMgr::setSpeed(float fSpeed){
	m_fSpeed = fSpeed;
}