#include "Cloud.h"

CCloud::CCloud(){

}
CCloud::~CCloud(){

}
CCloud* CCloud::createCloud(){
	CCloud* pCloud = new CCloud();
	if (pCloud&&pCloud->init()){
		pCloud->autorelease();
		return pCloud;
	}
	CC_SAFE_DELETE(pCloud);
	return nullptr;
}
bool CCloud::init(){
	if (!Node::init()){
		return false;
	}
	//ÔÆ¶ä
	m_pCloud = Sprite::create("Image/cloud1.png");
	this->addChild(m_pCloud);

	return true;
}
void CCloud::move(){
	Vec2 offset;
	offset.x = -(Director::getInstance()->getWinSize().width + 500);
	MoveBy* pMoveBy = MoveBy::create(15, offset);
	Sequence* pSeq = Sequence::create(pMoveBy, RemoveSelf::create(), nullptr);
	this->runAction(pSeq);
}