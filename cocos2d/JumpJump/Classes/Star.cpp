#include "Star.h"

CStar::CStar()
:m_nScore(0)
{

}
CStar::~CStar(){

}
CStar* CStar::createWithData(SStarDt* pConfig){
	CStar* pStar = new CStar();
	if (pStar&&pStar->initWithData(pConfig)){
		pStar->autorelease();
		return pStar;
	}
	CC_SAFE_DELETE(pStar);
	return nullptr;
}

bool CStar::initWithData(SStarDt* pData){
	if (!Node::init())
	{
		return false;
	}
		m_pImage = Sprite::createWithSpriteFrameName(pData->VecImg[0]);
		m_pImage->setScale(0.3);
		m_nScore = pData->nScore;
		this->addChild(m_pImage);
		return true;
}

void CStar::move(int nSpeed){

		float fX = random() % 60 + 450;
		float fY = random() % 200 + 600;
		//贝塞尔曲线
		ccBezierConfig bezierCon;
	    bezierCon.controlPoint_1=CCPointMake(1000,200);//控制点1
		bezierCon.controlPoint_2 = CCPointMake(fX, fY);//控制点2
		bezierCon.endPosition = CCPointMake(-100, 100);// 结束位置
		ActionInterval * action1 = CCBezierTo::create(nSpeed, bezierCon);

		Sequence* pSeq = Sequence::create(action1, RemoveSelf::create(), nullptr);
		this->runAction(pSeq); 
	// CCBezierTo
	/*Vec2 offset;
	offset.x = -Director::getInstance()->getWinSize().width - 200;
	MoveBy* pMoveBy = MoveBy::create(nSpeed, offset);
	Sequence* pSeq = Sequence::create(pMoveBy, RemoveSelf::create(), nullptr);
	this->runAction(pSeq);*/
	auto action2 = RotateBy::create(2, -360);
	this->runAction(RepeatForever::create(action2));
	
}
Rect CStar::getBoundingBoxToWorld()
{
	Rect rcImg = m_pImage->getBoundingBox();
	Rect rc;
	rc.size = rcImg.size;
	rc.origin = this->convertToWorldSpaceAR(rcImg.origin);
	return rc;
}