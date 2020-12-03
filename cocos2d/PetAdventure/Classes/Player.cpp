#include"Player.h"
#include "GameScene.h"
#include "GameOver.h"
#include "LevelMgr.h"
#include "RoleMgr.h"

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
CPlayer::CPlayer()
:m_fAccel(-1000)
, m_nDirX(0)
, m_fMaxX(0)
, nLadder(0)
, m_nCoin(0)
, m_nLive(0)
, m_bResetFollow(false)
, m_bLevitate(false)
, m_bAttack(false)
, m_bKey(false)
, m_sPet()
, m_nState(E_STATE_NONE)
{

}
CPlayer::~CPlayer()
{
	
}
bool CPlayer::init()
{
	if (!Node::init()){
		return false;
	}
	SRoleDt* pRoleDt = CRoleMgr::getInstance()->getRoleDt();
	m_sPet = pRoleDt->strPet;
	m_nLive = pRoleDt->nLive;
	m_pImage = Sprite::createWithSpriteFrameName(m_sPet + "02.png");
	m_pImage->setScale(1.4);
	this->addChild(m_pImage);

	m_vVelocity.x = 180;

	this->createAnims();
	this->addKeyboardEvent();
	this->scheduleUpdate();
	return true;
}

void CPlayer::update(float delta)
{
	//y轴方向处理
	string strCollicY = this->checkCollicY();
	if ("none" != strCollicY){
		m_bLevitate = false;
	}
	if ("none" == strCollicY)
	{
		if (0 == nLadder)
		{
			//速度都要增加
			m_vVelocity.y += m_fAccel*delta;
			float fY = this->getPositionY();
			fY += m_vVelocity.y*delta;
			this->setPositionY(fY);
		}
		else{
			m_bLevitate = false;
		}
	}
	if ("river" == strCollicY)
	{
		this->hurt();
	}
	//x轴方向处理
	string strCollicX = this->checkCollicX();
	if ("none" == strCollicX)
	{
		float fX = this->getPositionX();
		if (fX < 0){
			this->setPositionX(fX + 2);
			return;
		}
		if (fX >= 2775){
			this->setPositionX(fX - 2);
			return;
		}
		fX += m_vVelocity.x * m_nDirX * delta;
		this->setPositionX(fX);
		if (fX > m_fMaxX)
		{
			m_fMaxX = fX;
			m_bResetFollow = true;
		}
	}
	//物品处理
	string strCollicItem = this->checkCollicItem();
	if ("ladder" == strCollicItem){
		if (E_STATE_JUMP == m_nState){
			nLadder = 1;
		}
	}
	else {
		nLadder = 0;
	}
	if ("live" == strCollicItem)
	{
		SRoleDt* pRoleDt = CRoleMgr::getInstance()->getRoleDt();
		if (m_nLive < pRoleDt->nLive){

			m_nLive++;
			CGameScene::getInstance()->getLive()[m_nLive-1]->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("live.png"));
		}
	}
	if ("coin" == strCollicItem)
	{
		m_nCoin++;
		SimpleAudioEngine::sharedEngine()->playEffect("Music/Bonus.mp3", false);
	}
	if ("key" == strCollicItem)
	{
		m_bKey = true;
		SimpleAudioEngine::sharedEngine()->playEffect("Music/key.mp3", false);

	}
	if ("door" == strCollicItem)
	{
		SLevelDt* pLevelDt = CLevelMgr::getInstance()->getLevelDt();
		int nCoinLimit = pLevelDt->nCoinLimit;
		if (m_bKey && m_nCoin >= nCoinLimit)
		{
			CLevelMgr::getInstance()->nextScene();
			
		}
	}
	

	//箱子处理
	string strColliicBox = this->checkCollicBox();
	if ("box" == strColliicBox)
	{
		float fY = this->getPositionY() - 8;
		this->setPositionY(fY);
		m_vVelocity.y += m_fAccel*delta;
	}
}

void CPlayer::hurt()
{
	m_nLive--;
	if (m_nLive < 0){
		CGameOver* pGameOver = CGameOver::create();
		Director::getInstance()->replaceScene(pGameOver);
		CGameScene::destroy();
		return;
	}
	CGameScene::getInstance()->getLive()[m_nLive]->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("no_live.png"));
	//声音
	SimpleAudioEngine::sharedEngine()->playEffect("Music/hurt.mp3", false);
	//检查点
	vector<Vec2> v_CheckPos = CGameScene::getInstance()->getTiledMapCtrl()->getCheckPos();
	for (int i = v_CheckPos.size(); i > 0; i--)
	{
		int nPlayerX = this->getPositionX();
		Vec2 vPos = v_CheckPos[i-1];
		if (nPlayerX > vPos.x){
			this->setPosition(vPos);
			return;
		}
	}
}
string CPlayer::checkCollicX()
{
	Vec2 collicPos = this->getCollicPos(Vec2(m_nDirX, 0));
	//转化为格子坐标
	CTiledMapCtrl* pTiledMapCtrl = CGameScene::getInstance()->getTiledMapCtrl();
	Vec2 collicTile = pTiledMapCtrl->getTileByPos(collicPos);
	string strCollic = pTiledMapCtrl->checkColliX(collicTile);
	return strCollic;
}

string CPlayer::checkCollicY()
{
	//碰地板
	//获取碰撞点
	Vec2 collicPos = this->getCollicPos(Vec2(0, -1));
	//转化为格子坐标
	CTiledMapCtrl* pTiledMapCtrl = CGameScene::getInstance()->getTiledMapCtrl();
	Vec2 collicTile = pTiledMapCtrl->getTileByPos(collicPos);
	string strCollic = pTiledMapCtrl->checkColliY(collicTile);
	return strCollic;
}
string CPlayer::checkCollicItem(){
	//碰梯子
	Vec2 collicPos = this->getCollicPos(Vec2(m_nDirX, 0));
	//转化为格子坐标
	CTiledMapCtrl* pTiledMapCtrl = CGameScene::getInstance()->getTiledMapCtrl();
	Vec2 collicTile = pTiledMapCtrl->getTileByPos(collicPos);
	string strCollic = pTiledMapCtrl->checkColliItem(collicTile);
	return strCollic;
}
string CPlayer::checkCollicBox()
{
	//获取碰撞点
	Vec2 collicPos = this->getCollicPos(Vec2(0, 1));
	//转化为格子坐标
	CTiledMapCtrl* pTiledMapCtrl = CGameScene::getInstance()->getTiledMapCtrl();
	Vec2 collicTile = pTiledMapCtrl->getTileByPos(collicPos);
	string strCollic = pTiledMapCtrl->checkColliBox(collicTile);
	return strCollic;
}
Rect CPlayer::getBoundingBoxToWorld()
{
	Rect rcImg = m_pImage->getBoundingBox();
	Rect rc;
	rc.size = rcImg.size;
	rc.origin = this->convertToWorldSpaceAR(rcImg.origin);
	return rc;
}
cocos2d::Vec2 CPlayer::getCollicPos(const Vec2& dir)
{
	Vec2 pos = this->getPosition();
	Size size = m_pImage->getContentSize();
	pos.x += (dir.x * size.width / 2);
	pos.y += (dir.y * size.height / 2);
	return pos;
}

void CPlayer::createAnims()
{
	SpriteFrameCache* pCache = SpriteFrameCache::getInstance();
	//移动动画
	m_pWalkAnim = Animation::create();
	char szName[32] = {};
	for (int i = 1; i <= 3; i++)
	{
		sprintf_s(szName, "0%d.png", i);
		SpriteFrame* pFrame = pCache->getSpriteFrameByName(m_sPet + szName);
		m_pWalkAnim->addSpriteFrame(pFrame);
	}

	m_pWalkAnim->setDelayPerUnit(0.1);
	m_pWalkAnim->retain();

	//攀爬动画
	m_pClimbAnim = Animation::create();
	for (int j = 4; j <= 6; j++)
	{
		sprintf_s(szName, "0%d.png", j);
		SpriteFrame* pFrame = pCache->getSpriteFrameByName(m_sPet + szName);
		m_pClimbAnim->addSpriteFrame(pFrame);
	}
	m_pClimbAnim->setDelayPerUnit(0.1);
	m_pClimbAnim->retain();

	
}
void CPlayer::changeState(int nState)
{
	auto action2 = RotateBy::create(0.5, 720);
	if (m_nState == nState)
	{
		return;
	}
	m_nState = nState;
	m_pImage->stopAllActions();
	if (E_STATE_WALK == m_nState)
	{
		if (m_bAttack)
		{
			m_pImage->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(m_sPet + "07.png"));
			m_pImage->runAction(RepeatForever::create(action2));
		}
		else{
			Animate* pWalkAnim = Animate::create(m_pWalkAnim);
			m_pImage->runAction(RepeatForever::create(pWalkAnim));
		}
	}
	else if (E_STATE_IDLE == m_nState)
	{
		m_bAttack = false;

		if (1 == nLadder){
			m_pImage->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(m_sPet + "05.png"));
			m_pImage->setRotation(0);
		}
		else{
			m_pImage->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(m_sPet + "02.png"));
			m_pImage->setRotation(0);
		}
	}
	else if (E_STATE_JUMP == m_nState)
	{
		float fY = this->getPositionY();
		fY += 20;
		this->setPositionY(fY);
		if (1 == nLadder){
			Animate* pClimbAnim = Animate::create(m_pClimbAnim);
			m_pImage->runAction(RepeatForever::create(pClimbAnim));
		}
		else if (m_bAttack){
			m_pImage->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(m_sPet + "07.png"));
			m_pImage->runAction(RepeatForever::create(action2));
		}
		else{
			m_pImage->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(m_sPet + "03.png"));
		}
	}
	else if (E_STATE_ATTACK == m_nState)
	{
		m_pImage->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(m_sPet + "07.png"));
		m_pImage->runAction(RepeatForever::create(action2));
	}

}
void CPlayer::onJumpCtrl(){

		SimpleAudioEngine::sharedEngine()->playEffect("Music/click.mp3", false);
		m_bLevitate = true;
		m_vVelocity.y = 220;
}
void CPlayer::addKeyboardEvent()
{
	EventListenerKeyboard* pListener = EventListenerKeyboard::create();
	pListener->onKeyPressed = CC_CALLBACK_2(CPlayer::onKeyPressed, this);
	pListener->onKeyReleased = CC_CALLBACK_2(CPlayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(pListener, this);
}

void CPlayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* pEvent)
{
	if (EventKeyboard::KeyCode::KEY_UP_ARROW == keyCode)
	{
		if (!m_bLevitate){
			this->onJumpCtrl();
			this->changeState(E_STATE_JUMP);
		}
	}
	if (EventKeyboard::KeyCode::KEY_K == keyCode)
	{
		m_bAttack = true;
		this->changeState(E_STATE_ATTACK);
	}
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		if (m_bResetFollow)
		{
			CTiledMapCtrl* pTiledMapCtrl = CGameScene::getInstance()->getTiledMapCtrl();
			pTiledMapCtrl->follow(this);
			m_bResetFollow = false;
		}
		m_pImage->setFlippedX(true);
		m_nDirX = -1;
		this->changeState(E_STATE_WALK);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		m_nDirX = 1;
		m_pImage->setFlippedX(false);
		this->changeState(E_STATE_WALK);
		break;
	default:
		break;
	}
}

void CPlayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* pEvent)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		m_nDirX = 0;
		this->changeState(E_STATE_IDLE);
		break;
	case EventKeyboard::KeyCode::KEY_K:
		m_bAttack = false;
		this->changeState(E_STATE_IDLE);
		break;
	default:
		break;
	}
}