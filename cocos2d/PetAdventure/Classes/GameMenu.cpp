#include "GameMenu.h"
#include "GameScene.h"
#include "LoadingScene.h"
#include "LevelMgr.h"
#include "RoleMgr.h"
CGameMenu::CGameMenu()
{
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Music/The Good Life.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("Music/click.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("Music/Bonus.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("Music/button.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("Music/hurt.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("Music/attack.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("Music/key.mp3");
}

CGameMenu::~CGameMenu()
{

}

bool CGameMenu::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CRoleMgr::getInstance()->setRoleID(2001);
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image/menu.plist");
	//背景图片
	m_pBg = Sprite::createWithSpriteFrameName("pet_bg1.png");
	m_pBg->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(m_pBg);
	//标题
	m_pTitle = Sprite::createWithSpriteFrameName("title.png");
	m_pTitle->setPosition(origin.x + visibleSize.width / 2,visibleSize.height -120);
	this->addChild(m_pTitle);
	//向左
	m_pLeft = Button::create("left.png", "left.png", "", Widget::TextureResType::PLIST);
	m_pLeft->setPosition(Vec2(origin.x + 50, origin.y + visibleSize.height / 2 + 10));
	m_pLeft->setVisible(false);
	this->addChild(m_pLeft);
	m_pLeft
		->addClickEventListener(CC_CALLBACK_1(CGameMenu::onLeftBtnClick, this));
	//向右
	m_pRight = Button::create("right.png", "right.png", "", Widget::TextureResType::PLIST);
	m_pRight->setPosition(Vec2(origin.x + visibleSize.width - 50, origin.y + visibleSize.height / 2 + 10));
	this->addChild(m_pRight);
	m_pRight->addClickEventListener(CC_CALLBACK_1(CGameMenu::onRightBtnClick, this));
	//开始按钮
	m_pBtnStart = Button::create("claw.png", "claw.png", "", Widget::TextureResType::PLIST);
	m_pBtnStart->setPosition(Vec2(origin.x + visibleSize.width / 2 - 100, origin.y + visibleSize.height / 2));
	this->addChild(m_pBtnStart);
	m_pBtnStart->addClickEventListener(CC_CALLBACK_1(CGameMenu::onStartClick, this));

	Label* pStart = Label::createWithTTF("Start", "fonts/01digit.ttf", 36);
	MenuItemLabel* m_pStart = MenuItemLabel::create(pStart, CC_CALLBACK_1(CGameMenu::onStartClick, this));
	m_pStart->setColor(Color3B(58,25,25));
	m_pStart->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

	Menu* newmenu = Menu::create(m_pStart, NULL);
	newmenu->setPosition(Vec2::ZERO);
	this->addChild(newmenu, 1);

	//播放背景音乐
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Music/The Good Life.mp3", true);

	return true;
}
void CGameMenu::onStartClick(Ref* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("Music/button.mp3", false);
	CGameScene::destroy();
	CLevelMgr::getInstance()->setLevelID(1001);
	
	CLoadingScene* pScene = CLoadingScene::createWithData("Game");
	Director::getInstance()->replaceScene(pScene);
}
void CGameMenu::onLeftBtnClick(Ref* pSender)
{
	m_pRight->setVisible(true);
	m_pLeft->setVisible(false);
	CRoleMgr::getInstance()->setRoleID(2001);
	m_pBg->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("pet_bg1.png"));
}
void CGameMenu::onRightBtnClick(Ref* pSender)
{
	m_pLeft->setVisible(true);
	m_pRight->setVisible(false);
	CRoleMgr::getInstance()->setRoleID(200);
	m_pBg->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("pet_bg2.png"));
}