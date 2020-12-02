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

		//���������ı���ͼƬ������������λ��Ϊ������Ļ���е�
		CCSprite * background = CCSprite::create("common_panel.png");
		m_bgSprite = background;
		background->setPosition(ccp(winSize.width / 2, winSize.height / 2));
		this->addChild(background);

		//��ñ���ͼƬ�Ĵ�С
		CCSize contentSize = background->getContentSize();
		m_size = contentSize;

		//��������˵����������
		CCMenuItemImage * item1 = CCMenuItemImage::create("success_continue.png",
			"success_continue_slecte.png", "",
			this, menu_selector(CPopScene::yesButton));

		CCMenu * menu = CCMenu::create(item1, NULL);
		menu->alignItemsHorizontallyWithPadding(5);
		menu->setPosition(ccp(contentSize.width / 2, contentSize.height /5));
		//kCCMenuHandlerPriority��ֵΪ-128��������ǲ˵���ť�Ĵ������ȼ�
		//����menu���ȼ�����������Ϊ��ͨmenu�Ķ�����һ��ԭ���±�
		//menu->setTouchPriority(kCCMenuHandlerPriority * 2 - 1);
		
		background->addChild(menu);

		//������Ŀ���ı�����
		//this->setTitle();
		//this->setContent();
		this->addTouchEvent();
		this->setTouchEnabled(true);
		bRet = true;
	} while (0);
	
	return bRet;
}

void CPopScene::addTouchEvent(){
	//ע�ᴥ���¼�
	//�������������¼�
	EventListenerTouchOneByOne* pListener = EventListenerTouchOneByOne::create();
	pListener->onTouchBegan = CC_CALLBACK_2(CPopScene::onTouchBegan, this);
	pListener->onTouchEnded = CC_CALLBACK_2(CPopScene::onTouchEnded, this);
	//�����Ƿ������¼�
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
//����˵���ť��ʱ����õ��¼�������
void CPopScene::yesButton(CCObject * object)
{
	if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){
		SimpleAudioEngine::sharedEngine()->playEffect("Music/button.mp3", false);
	}
	this->removeFromParentAndCleanup(true);
}
//������������Ŀ
void CPopScene::setTitle()
{
	//CCLabelTTF * title = CCLabelTTF::create("Tips","",24);
	CCLabelBMFont * title = CCLabelBMFont::create("How to Play", "fonts/Marker Felt.ttf");
	title->setPosition(ccp(m_size.width / 2, m_size.height - title->getContentSize().height / 2));
	m_bgSprite->addChild(title);
}

//���ò������
void CPopScene::setContent()
{
	CCLabelTTF * content = CCLabelTTF::create("JumpJump","", 24);
	content->setPosition(ccp(m_size.width / 2, m_size.height / 2));
	//����ttf���ı���
	content->setDimensions(CCSize(this->m_size.width - 60, this->m_size.height - 100));
	//����ttf��ˮƽ���뷽ʽ
	content->setHorizontalAlignment(kCCTextAlignmentLeft);

	m_bgSprite->addChild(content);
}