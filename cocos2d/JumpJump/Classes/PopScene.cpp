#include "PopScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

CPopScene::CPopScene(){


}
CPopScene::~CPopScene(){

}
CCScene * CPopScene::scene()
{
	CCScene * scene = NULL;
	do
	{
		scene = CCScene::create();
		CPopScene * layer = CPopScene::create();
		scene->addChild(layer);
	} while (0);

	return scene;
}

bool CPopScene::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!CCLayer::init());

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

		//设置这个层的背景图片，并且设置其位置为整个屏幕的中点
		CCSprite * background = CCSprite::create("common_panel.png");
		m_bgSprite = background;
		background->setPosition(ccp(winSize.width / 2, winSize.height / 2));
		this->addChild(background);

		//获得背景图片的大小
		CCSize contentSize = background->getContentSize();
		m_size = contentSize;

		//添加俩个菜单在这个层中
		CCMenuItemImage * item1 = CCMenuItemImage::create("success_continue.png",
			"success_continue_slecte.png", "",
			this, menu_selector(CPopScene::yesButton));

		CCMenu * menu = CCMenu::create(item1, NULL);
		menu->alignItemsHorizontallyWithPadding(5);
		menu->setPosition(ccp(contentSize.width / 2, contentSize.height /5));
		//kCCMenuHandlerPriority的值为-128，代表的是菜单按钮的触摸优先级
		//设置menu优先级，这里设置为普通menu的二倍减一，原因看下边
		//menu->setTouchPriority(kCCMenuHandlerPriority * 2 - 1);
		
		background->addChild(menu);

		//设置题目和文本内容
		//this->setTitle();
		//this->setContent();
		this->addTouchEvent();
		this->setTouchEnabled(true);
		bRet = true;
	} while (0);
	
	return bRet;
}

void CPopScene::addTouchEvent(){
	//注册触摸事件
	//创建触摸监听事件
	EventListenerTouchOneByOne* pListener = EventListenerTouchOneByOne::create();
	pListener->onTouchBegan = CC_CALLBACK_2(CPopScene::onTouchBegan, this);
	pListener->onTouchEnded = CC_CALLBACK_2(CPopScene::onTouchEnded, this);
	//设置是否吞噬事件
	pListener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(pListener, this);
}
bool CPopScene::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	CCLOG("onTouchBegan");

	return true;
}
void CPopScene::onTouchEnded(Touch* pTouch, Event* pEvent)
{
}
//点击菜单按钮的时候调用的事件处理函数
void CPopScene::yesButton(CCObject * object)
{
	if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){
		SimpleAudioEngine::sharedEngine()->playEffect("Music/button.mp3", false);
	}
	this->removeFromParentAndCleanup(true);
}
//设置这个层的题目
void CPopScene::setTitle()
{
	//CCLabelTTF * title = CCLabelTTF::create("Tips","",24);
	CCLabelBMFont * title = CCLabelBMFont::create("How to Play", "fonts/Marker Felt.ttf");
	title->setPosition(ccp(m_size.width / 2, m_size.height - title->getContentSize().height / 2));
	m_bgSprite->addChild(title);
}

//设置层的内容
void CPopScene::setContent()
{
	CCLabelTTF * content = CCLabelTTF::create("JumpJump","", 24);
	content->setPosition(ccp(m_size.width / 2, m_size.height / 2));
	//设置ttf的文本域
	content->setDimensions(CCSize(this->m_size.width - 60, this->m_size.height - 100));
	//设置ttf的水平对齐方式
	content->setHorizontalAlignment(kCCTextAlignmentLeft);

	m_bgSprite->addChild(content);
}