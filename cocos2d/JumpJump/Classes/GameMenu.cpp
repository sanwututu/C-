#include "GameMenu.h"
#include "GameScene.h"
#include "PopScene.h"

CGameMenu::CGameMenu()
:nTime(0)
{
	SimpleAudioEngine::sharedEngine()->preloadEffect("Music/click.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("Music/Bonus.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("Music/button.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("Music/hurt.mp3");
}
CGameMenu::~CGameMenu(){

}
bool CGameMenu::init(){
	if (!Scene::init()){
		return false;
	}
	//写要做的初始化操作
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//将plist文件解析到精灵帧缓存中
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Image/Bg.plist");

	
	//背景图片
	m_pBg = Sprite::createWithSpriteFrameName("background.png");
	m_pBg->setScale(1.5);
	this->addChild(m_pBg);
	//月亮Moon
	m_pMoonMgr = CMoonMgr::create();
	m_pMoonMgr->setSpeed(10);
	this->addChild(m_pMoonMgr);
	//标题
	m_pTitle = Sprite::createWithSpriteFrameName("title_0000_cn.png");
	m_pTitle->setPosition(480, 370);
	this->addChild(m_pTitle);
	//开关按钮
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Image/Button.plist");
	m_pBtnStart = Button::create("ui_resume.png", "ui_resume.png", "", Widget::TextureResType::PLIST);
	m_pBtnStart->setPosition(Vec2(480, 280));
	this->addChild(m_pBtnStart);
	m_pBtnStart->addClickEventListener(CC_CALLBACK_1(CGameMenu::onBtnClick, this));
	this->createMenu();
	//播放背景音乐
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Music/Sweet.mp3", true);
	this->scheduleUpdate();

	return true;
}
void CGameMenu::update(float delta)
{
	nTime +=10;
	m_pTitle->setScale(1);
	m_pBtnStart->setScale(1);
	if (nTime > 100){
		m_pTitle->setScale(1.1);
		m_pBtnStart->setScale(1.1);
	}
	if (nTime > 200){
		m_pTitle->setScale(1.2);
		m_pBtnStart->setScale(1.2);
	}
	if (nTime > 300){
		m_pTitle->setScale(1.3);
		m_pBtnStart->setScale(1.3);
	}
	if (nTime > 400){
		m_pTitle->setScale(1.4);
		m_pBtnStart->setScale(1.4);
	}
	if (nTime > 500){
		m_pTitle->setScale(1.5);
		m_pBtnStart->setScale(1.5);
		nTime = 0;
	}
}
void CGameMenu::createMenu(){
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//音乐
	m_pMusicBtn = MenuItemImage::create(
		"",
		"",
		CC_CALLBACK_1(CGameMenu::gameMusicCallback, this));
	m_pMusicBtn->setNormalImage(Sprite::createWithSpriteFrameName("ui_turnoff.png"));
	m_pMusicBtn->setScale(2);
	float x = origin.x + 20;
	float y = visibleSize.height - 20;
	m_pMusicBtn->setPosition(Vec2(x +40, y));
	//说明

	//游戏说明
	m_pExplainBtn = MenuItemImage::create(
		"",
		"",
		CC_CALLBACK_1(CGameMenu::gameExplainCallback, this));
	m_pExplainBtn->setNormalImage(Sprite::create("Image/ui_explain.png"));
	m_pExplainBtn->setSelectedImage(Sprite::create("Image/ui_explain.png"));
	m_pExplainBtn->setScale(2);
	m_pExplainBtn->setPosition(Vec2(x, y));
	auto menu = Menu::create(m_pMusicBtn, m_pExplainBtn, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

}
void CGameMenu::onBtnClick(Ref* pSender)
{
	if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){
		SimpleAudioEngine::sharedEngine()->playEffect("Music/button.mp3", false);
	}
	CGameScene* pGameScene = CGameScene::create();
	Director::getInstance()->replaceScene(pGameScene);
}
void CGameMenu::gameMusicCallback(Ref* pSender)
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
void CGameMenu::gameExplainCallback(Ref* pSender)
{
	if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){
		SimpleAudioEngine::sharedEngine()->playEffect("Music/button.mp3", false);
	}
	CPopScene* popLayer = CPopScene::create();
	this->addChild(popLayer);
}