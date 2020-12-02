#include "GamePause.h"
#include "CCColorUtil.h"
CGamePause::CGamePause(){

}
CGamePause::~CGamePause(){
	   
}
CCScene* CGamePause::scene(CCRenderTexture* sqr){
	CCScene *scene = CCScene::create();
	CGamePause *layer = CGamePause::create();
	scene->addChild(layer, 1);
	//增加部分：使用Game界面中截图的sqr纹理图片创建Sprite
	//并将Sprite添加到GamePause场景层中
	//得到窗口的大小
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCSprite *back_spr = CCSprite::createWithTexture(sqr->getSprite()->getTexture());
	back_spr->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2)); //放置位置,这个相对于中心位置。
	back_spr->setFlipY(true);            //翻转，因为UI坐标和OpenGL坐标不同
	//back_spr->setColor(cocos2d::ccGRAY); //图片颜色变灰色
	scene->addChild(back_spr);

	return scene;

}

bool CGamePause::init(){
	if (!Scene::init()){
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//添加半透明遮罩
	Sprite* m_pMask = Sprite::create("Image/mask.png");
	m_pMask->setScale(1.5);
	this->addChild(m_pMask);
	//开始
	m_pStartBtn = MenuItemImage::create(
		"",
		"",
		CC_CALLBACK_1(CGamePause::menuContinueCallback, this));
	m_pStartBtn->setNormalImage(Sprite::createWithSpriteFrameName("ui_resume.png"));
	m_pStartBtn->setSelectedImage(Sprite::createWithSpriteFrameName("ui_resume.png"));
	m_pStartBtn->setScale(2.2);
	
	float x = visibleSize.width / 2;
		float y = visibleSize.height/2;
		m_pStartBtn->setPosition(Vec2(x, y));

		auto menu = Menu::create(m_pStartBtn, NULL);
		menu->setPosition(Vec2::ZERO);
		this->addChild(menu, 1);
	return true;
}
void CGamePause::menuContinueCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();

}
