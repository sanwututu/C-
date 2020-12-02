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
	//���Ӳ��֣�ʹ��Game�����н�ͼ��sqr����ͼƬ����Sprite
	//����Sprite��ӵ�GamePause��������
	//�õ����ڵĴ�С
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCSprite *back_spr = CCSprite::createWithTexture(sqr->getSprite()->getTexture());
	back_spr->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2)); //����λ��,������������λ�á�
	back_spr->setFlipY(true);            //��ת����ΪUI�����OpenGL���겻ͬ
	//back_spr->setColor(cocos2d::ccGRAY); //ͼƬ��ɫ���ɫ
	scene->addChild(back_spr);

	return scene;

}

bool CGamePause::init(){
	if (!Scene::init()){
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//��Ӱ�͸������
	Sprite* m_pMask = Sprite::create("Image/mask.png");
	m_pMask->setScale(1.5);
	this->addChild(m_pMask);
	//��ʼ
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
