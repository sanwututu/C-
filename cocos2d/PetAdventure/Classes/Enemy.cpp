#include "Enemy.h"
#include "GameScene.h"

CEnemy::CEnemy()
:m_nDir(-1)
, m_nSpeed(1)
{

}

CEnemy::~CEnemy()
{

}

CEnemy* CEnemy::createWithData()
{
	CEnemy* pEnemy = new CEnemy();
	if (pEnemy&&pEnemy->initWithData())
	{
		pEnemy->autorelease();
		return pEnemy;
	}
	CC_SAFE_DELETE(pEnemy);
	return nullptr;
}

bool CEnemy::initWithData()
{
	if (!Node::init())
	{
		return false;
	}
	m_pImage = Sprite::createWithSpriteFrameName("enemy01.png");
	this->addChild(m_pImage);

	this->createAnim();
	this->scheduleUpdate();
	return true;
}
void CEnemy::update(float delta)
{
	//x轴方向处理
	string strCollicX = this->checkCollicX();
	if ("block" == strCollicX)
	{
		m_nDir *= -1;
		if (1 == m_nDir)
		{
			m_pImage->setFlippedX(true);
		}
		else
		{
			m_pImage->setFlippedX(false);
		}
	}
	//x轴方向处理
	string strCollicAir = this->checkCollicAir();
	if ("air" == strCollicAir)
	{
		m_nDir *= -1;
		if (1 == m_nDir)
		{
			m_pImage->setFlippedX(true);
		}
		else
		{
			m_pImage->setFlippedX(false);
		}
	}

	this->move();
}
void CEnemy::createAnim()
{
	SpriteFrameCache* pCache = SpriteFrameCache::getInstance();
	pAnimation = Animation::create();
	char szName[32] = {};
	for (int i = 1; i <= 3; i++)
	{
		sprintf_s(szName, "enemy0%d.png", i);
		SpriteFrame* pFrame = pCache->getSpriteFrameByName(szName);
		pAnimation->addSpriteFrame(pFrame);
	}
	pAnimation->setDelayPerUnit(0.4);
	pAnimation->retain();

	Animate* pAnimate = Animate::create(pAnimation);
	m_pImage->runAction(RepeatForever::create(pAnimate));
}
string CEnemy::checkCollicX()
{
	Vec2 collicPos = this->getCollicPos(Vec2(m_nDir, 0));
	//转化为格子坐标
	CTiledMapCtrl* pTiledMapCtrl = CGameScene::getInstance()->getTiledMapCtrl();
	Vec2 collicTile = pTiledMapCtrl->getTileByPos(collicPos);
	string strCollic = pTiledMapCtrl->checkColliX(collicTile);
	return strCollic;
}
string CEnemy::checkCollicAir()
{
	Vec2 collicPos = this->getCollicPos(Vec2(m_nDir, 0));
	//转化为格子坐标
	CTiledMapCtrl* pTiledMapCtrl = CGameScene::getInstance()->getTiledMapCtrl();
	Vec2 collicTile = pTiledMapCtrl->getTileByPos(collicPos);
	string strCollic = pTiledMapCtrl->checkColliAir(collicTile);
	return strCollic;
}
cocos2d::Vec2 CEnemy::getCollicPos(const Vec2& dir)
{
	Vec2 pos = this->getPosition();
	Size size = m_pImage->getContentSize();
	pos.x += (dir.x * size.width / 2);
	pos.y += (dir.y * size.height / 2);
	return pos;
}
void CEnemy::move()
{
	float fX = this->getPositionX();
	this->setPositionX(fX + m_nDir*m_nSpeed);
	int i = 1;
} 
Rect CEnemy::getBoundingBoxToWorld()
{
	Rect rcImg = m_pImage->getBoundingBox();
	Rect rc;
	rc.size = rcImg.size;
	rc.origin = this->convertToWorldSpaceAR(rcImg.origin);
	return rc;
}