#include "Player.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

CPlayer::CPlayer()
:m_fHight(100), m_nDir(E_DIR_NONE)
{
}
CPlayer::~CPlayer(){

}
bool CPlayer::init(){
	if (!Node::init()){
		return false;
	}
	//
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Image/Player.plist");

	//玩家图片
	m_pImage = Sprite::createWithSpriteFrameName("a1.png");
	m_pImage->setPosition(origin.x + visibleSize.width / 2,205);
	m_pImage->setScale(1.5);
	this->addChild(m_pImage);

	//
	//this->createAnims();
	this->addTouchEvent();
	this->scheduleUpdate();
	return true;
}
void CPlayer::update(float delta)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Image/Player.plist");
	float fY = m_pImage->getPositionY();
	if (E_DIR_UP == m_nDir){
		if (fY < 450){
			fY += m_fHight * 2 * delta;
			m_pImage->setPositionY(fY);
		}
		CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("a1.png");
		m_pImage->setDisplayFrame(frame);
	}
	if (E_DIR_DOWN == m_nDir){
		if (fY > 200){
			fY -= (m_fHight*delta)+2;
			m_pImage->setPositionY(fY);
			CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("a0.png");
			m_pImage->setDisplayFrame(frame);
		}
	}
}
void CPlayer::createAnims(){
	//跳跃
	//创建动画信息
	m_pAnimJump = Animation::create();
	SpriteFrameCache* pCache = SpriteFrameCache::getInstance();
	char szName[32] = {};
	for (int i = 0; i < 2; i++){
		sprintf_s(szName, "a%d.png", i);
		SpriteFrame* pFrame = pCache->getSpriteFrameByName(szName);
		m_pAnimJump->addSpriteFrame(pFrame);
	}
	m_pAnimJump->setDelayPerUnit(0.4);
	Animate* pAnimJ = Animate::create(m_pAnimJump);
	RepeatForever* pRepeat = RepeatForever::create(pAnimJ);
	m_pImage->runAction(pRepeat);
}
void CPlayer::addTouchEvent(){
	//注册触摸事件
	//创建触摸监听事件
	EventListenerTouchOneByOne* pListener = EventListenerTouchOneByOne::create();
	pListener->onTouchBegan = CC_CALLBACK_2(CPlayer::onTouchBegan, this);
	pListener->onTouchEnded = CC_CALLBACK_2(CPlayer::onTouchEnded, this);
	//设置是否吞噬事件
	pListener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(pListener, this);
}
bool CPlayer::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	CCLOG("onTouchBegan");
	m_nDir = E_DIR_UP;
	if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){
		SimpleAudioEngine::sharedEngine()->playEffect("Music/click.mp3", false);
	}
	return true;
}
void CPlayer::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	m_nDir = E_DIR_DOWN;
	SimpleAudioEngine::sharedEngine()->stopEffect(0);
}
Rect CPlayer::getBoundingBoxToWorld()
{
	Rect rcImg = m_pImage->getBoundingBox();
	Rect rc;
	rc.size =Vec2(30,30);
	Vec2 vOrigin = rcImg.origin;
	rcImg.origin = vOrigin + Vec2(60, 60);
	rc.origin = this->convertToWorldSpaceAR(rcImg.origin);
	return rc;
}