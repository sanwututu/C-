#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "EndScene.h"
#include "GamePause.h"
#include "GameMenu.h""
using namespace CocosDenshion;

CGameScene* CGameScene::m_pInstance = nullptr;
CGameScene::CGameScene()
:m_nScore(0),m_nTime(0){

}
CGameScene::~CGameScene(){

}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool CGameScene::init(){
	if (!Scene::init()){
		return false;
	}//写要做的初始化操作
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	this->addRes();
	//背景图片
	m_pBg = Sprite::createWithSpriteFrameName("background.png");
	m_pBg->setScale(1.5);
	this->addChild(m_pBg);
	//菜单按钮
	this->createMenu();
	//云朵
	m_pItemMgr = CItemMgr::create();
	this->addChild(m_pItemMgr);
	//玻璃瓶
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Image/bottle.plist");
	m_pBottle = Sprite::createWithSpriteFrameName("bottle0.png");
	float fBottleX = visibleSize.width - (m_pBottle->getContentSize().width / 2) - 2;
	float fBottleY = visibleSize.height - (m_pBottle->getContentSize().height / 2) - 2;
	m_pBottle->setPosition(fBottleX, fBottleY);
	this->addChild(m_pBottle);
	//血条
	//创建血条背景
	m_pHp = Sprite::create("Image/bloodBg.png");
	m_pHp->setPosition(m_pHp->getContentSize().width,
		visibleSize.height/ 2);
	this->addChild(m_pHp);
	//一个ProgressTime类,能够设置其状态,百分比,显示类型等
	m_preal = ProgressTimer::create(Sprite::create("Image/blood.png"));
	m_preal->setType(ProgressTimer::Type::BAR);
	m_preal->setMidpoint(Point(0.5, 0));
	m_preal->setBarChangeRate(Point(0, 1));
	m_preal->setPosition(m_pHp->getContentSize() / 2);
	m_preal->setPercentage(100);
	m_pHp->addChild(m_preal);
	//分数标签，类型转换
	char temp[32];
	sprintf(temp, "%d", m_nScore, 10);
	std::string sScore = temp;
	m_pLabel = Label::createWithTTF(sScore, "fonts/Marker Felt.ttf", 24);
	if (m_pLabel == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		m_pLabel->setPosition(Vec2(fBottleX - 50, fBottleY));
		// add the label as a child to this layer
		this->addChild(m_pLabel, 1);
	}
	//月亮Moon
	m_pMoonMgr = CMoonMgr::create();
	this->addChild(m_pMoonMgr);
	//星星
	m_pStarMgr = CStarMgr::create();
	this->addChild(m_pStarMgr);
	//玩家
	m_pPlayer = CPlayer::create();
	this->addChild(m_pPlayer);

	//开启定时器
	this->scheduleUpdate();
	return true;
}
void CGameScene::createMenu(){

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//重新开始
	m_pReplayBtn = MenuItemImage::create(
		"",
		"",
		CC_CALLBACK_1(CGameScene::gameReplayCallback, this));
	m_pReplayBtn->setNormalImage(Sprite::createWithSpriteFrameName("ui_replay.png"));
	m_pReplayBtn->setSelectedImage(Sprite::createWithSpriteFrameName("ui_replay.png"));
	m_pReplayBtn->setScale(2);
	if (m_pReplayBtn == nullptr ||
		m_pReplayBtn->getContentSize().width <= 0 ||
		m_pReplayBtn->getContentSize().height <= 0)
	{
		problemLoading("'ui_replay.png' and 'ui_replay.png'");
	}
	else
	{
		float x = origin.x + 20;
		float y = visibleSize.height - 20;
		m_pReplayBtn->setPosition(Vec2(x, y));
	}

	//音乐
	m_pMusicBtn = MenuItemImage::create(
		"",
		"",
		CC_CALLBACK_1(CGameScene::gameMusicCallback, this));
	if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){

		m_pMusicBtn->setNormalImage(Sprite::createWithSpriteFrameName("ui_turnoff.png"));
	}
	else{
		m_pMusicBtn->setNormalImage(Sprite::createWithSpriteFrameName("ui_turnon.png"));
	}
	m_pMusicBtn->setScale(2);
	if (m_pMusicBtn == nullptr ||
		m_pMusicBtn->getContentSize().width <= 0 ||
		m_pMusicBtn->getContentSize().height <= 0)
	{
		problemLoading("'ui_turnoff.png' and 'ui_turnon.png'");
	}
	else
	{
		float x = origin.x + 60;
		float y = visibleSize.height - 20;
		m_pMusicBtn->setPosition(Vec2(x, y));
	}
	//暂停
	auto pauseItem = MenuItemImage::create(
		"",
		"",
		CC_CALLBACK_1(CGameScene::gamePauseCallback, this));
	pauseItem->setNormalImage(Sprite::createWithSpriteFrameName("ui_pause.png"));
	pauseItem->setSelectedImage(Sprite::createWithSpriteFrameName("ui_pause.png"));
	pauseItem->setScale(2);
	if (pauseItem == nullptr ||
		pauseItem->getContentSize().width <= 0 ||
		pauseItem->getContentSize().height <= 0)
	{
		problemLoading("'ui_pause.png' and 'ui_pause.png'");
	}
	else
	{
		float x = origin.x + 100;
		float y = visibleSize.height - 20;
		pauseItem->setPosition(Vec2(x, y));
	}
	auto menu = Menu::create(m_pReplayBtn, m_pMusicBtn, pauseItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
}
void CGameScene::addRes()
{//将plist文件解析到精灵帧缓存中
	SpriteFrameCache* pCache = SpriteFrameCache::getInstance();
	pCache->addSpriteFramesWithFile("Image/Bg.plist");
	pCache->addSpriteFramesWithFile("Image/Button.plist");
	pCache->addSpriteFramesWithFile("Image/Star.plist");
}
void CGameScene::update(float delta)
{
	//m_nTime++;
	//血条控制
	float fHp = m_preal->getPercentage()-0.1;
	m_preal->setPercentage(fHp);
	if (m_preal->getPercentage() <= 0){
		CEndScene* pEndScene = CEndScene::creatWithScore(m_nScore);
		Director::getInstance()->replaceScene(pEndScene);
	}
	if (m_nTime > 40){
		m_nScore++;
		m_nTime = 0;
	}
	//分数控制
	if (m_nScore <0){
		m_nScore = 0;
	}
	else if (50 > m_nScore >30){
		m_pStarMgr->setSpeed(3.5);
		m_pStarMgr->setTimeControl(90);
	}
	else if (80 >m_nScore > 50){
		m_pStarMgr->setSpeed(3);
		m_pStarMgr->setTimeControl(95);
		m_pMoonMgr->setSpeed(35);
	}
	else if ( 100 > m_nScore > 80){
		m_pStarMgr->setSpeed(2.5);
		m_pStarMgr->setTimeControl(100);
		m_pMoonMgr->setSpeed(40);
	}
	else if (m_nScore > 100){
		m_pStarMgr->setSpeed(2.3);
		m_pStarMgr->setTimeControl(60);
		m_pMoonMgr->setSpeed(45);
	}
	char temp[32];
	sprintf(temp, "%d", m_nScore, 10);
	std::string sScore = temp;
	m_pLabel->setString(sScore);

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Image/bottle.plist");
	if (m_nScore > 0){
		CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("bottle1.png");
		m_pBottle->setDisplayFrame(frame);
	}
	else{
		CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("bottle0.png");
		m_pBottle->setDisplayFrame(frame);
	}
	this->collicStar();

}
void CGameScene::collicStar(){
	Vector<Node*> VecStar = m_pStarMgr->getChildren();
	for (Node*& pSNode : VecStar){
		CStar* pStar = static_cast<CStar*>(pSNode);
		Rect rcStar = pStar->getBoundingBoxToWorld();
		Rect rcPlayer = m_pPlayer->getBoundingBoxToWorld();
		if (rcStar.intersectsRect(rcPlayer)){
			pStar->removeFromParent();
			m_nScore += pStar->getScore();
			m_preal->setPercentage(m_preal->getPercentage() + pStar->getScore()*10);
			if (pStar->getScore() > 0){
				if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){
					SimpleAudioEngine::sharedEngine()->playEffect("Music/Bonus.mp3", false);
				}
			}
			else{
				if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){

					SimpleAudioEngine::sharedEngine()->playEffect("Music/hurt.mp3", false);
				}
			}
		}
	}
}
void CGameScene::gameReplayCallback(Ref* pSender)
{
	CCLOG("rePlay");
	if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){
		SimpleAudioEngine::sharedEngine()->playEffect("Music/button.mp3", false);
	}
	CGameScene::destroy();
	CGameScene* pGameScene = CGameScene::getInstance();
	Director::getInstance()->replaceScene(pGameScene);
}
void CGameScene::gamePauseCallback(Ref* pSender)
{
	CCLOG("pause");
	if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){
		SimpleAudioEngine::sharedEngine()->playEffect("Music/button.mp3", false);
	}
	//得到窗口的大小
	auto visibleSize = Director::getInstance()->getVisibleSize();
	CCRenderTexture *renderTexture = CCRenderTexture::create(visibleSize.width, visibleSize.height);

	//遍历当前类的所有子节点信息，画入renderTexture中。
	//这里类似截图。
	renderTexture->begin();
	this->visit();
	renderTexture->end();

	//将游戏界面暂停，压入场景堆栈。并切换到GamePause界面
	CCDirector::sharedDirector()->pushScene(CGamePause::scene(renderTexture));

}
void CGameScene::gameMusicCallback(Ref* pSender)
{
	CCLOG("music");
	if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){
		SimpleAudioEngine::sharedEngine()->playEffect("Music/button.mp3", false);
		m_pMusicBtn->setNormalImage(Sprite::createWithSpriteFrameName("ui_turnon.png"));
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	}
	else{
		m_pMusicBtn->setNormalImage(Sprite::createWithSpriteFrameName("ui_turnoff.png"));
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound/game_music.mp3", true);
	}
}
CGameScene* CGameScene::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = CGameScene::create();
	}
	return m_pInstance;
}

void CGameScene::destroy()
{
	m_pInstance = nullptr;
}