#include "HomeScene.h"
#include "GameMenu.h"
#include "RoleMgr.h"

CHomeScene::CHomeScene()
:m_sPet()
, m_nTime(0)
{

}

CHomeScene::~CHomeScene()
{

}

bool CHomeScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	TMXTiledMap* pTiledMap = TMXTiledMap::create("Game/Tiles/map3.tmx");
	this->addChild(pTiledMap);

	//玩家
	SRoleDt* pRoleDt = CRoleMgr::getInstance()->getRoleDt();
	m_sPet = pRoleDt->strPet;

	m_pPlayer = Sprite::createWithSpriteFrameName(m_sPet + "02.png");
	m_pPlayer->setPosition(Vec2(350,115));
	this->addChild(m_pPlayer);
	
	//
	//主人
	m_pMaster = Sprite::createWithSpriteFrameName("master_01.png");
	m_pMaster->setScale(1.2);
	m_pMaster->setPosition(Vec2(680,120));
	this->addChild(m_pMaster);

	//
	m_lTalk = Label::createWithTTF(this->fontToUtf8("你去哪里啦？").c_str(), "fonts/DFPShaoNvW5-GB.ttf", 24);
	m_lTalk->setPosition(Vec2(visibleSize.width / 2, 60));
	this->addChild(m_lTalk, 1);

	this->scheduleUpdate();
	this->createAnims();
	return true;
}
void CHomeScene::update(float delta)
{
	m_nTime++;
	if (m_nTime > 450){

		CGameMenu* pGameMenu = CGameMenu::create();
		Director::getInstance()->replaceScene(pGameMenu);

	}
}
void CHomeScene::createAnims()
{
	SpriteFrameCache* pCache = SpriteFrameCache::getInstance();
	//移动动画
	Animation* m_pWalkAnim = Animation::create();
	char szName[32] = {};
	for (int i = 1; i <= 3; i++)
	{
		sprintf_s(szName, "0%d.png", i);
		SpriteFrame* pFrame = pCache->getSpriteFrameByName(m_sPet + szName);
		m_pWalkAnim->addSpriteFrame(pFrame);
	}
	m_pWalkAnim->setDelayPerUnit(0.1);
	m_pWalkAnim->retain();


	Animate* pWalkAnim = Animate::create(m_pWalkAnim);
	RepeatForever* pRep = RepeatForever::create(pWalkAnim);
	m_pPlayer->runAction(pRep);
	pRep->setTag(1);

	MoveBy* pMoveBy = MoveBy::create(3.0f, Vec2(300, 0));

	CallFunc* pCall1 = CallFunc::create(CC_CALLBACK_0(CHomeScene::actionCallBack, this));
	CallFunc* pCall2 = CallFunc::create(CC_CALLBACK_0(CHomeScene::endCallBack, this));

	
	Sequence* pSeq = Sequence::create(pMoveBy, pCall1, DelayTime::create(2.0f), pCall2, nullptr);
	m_pPlayer->runAction(pSeq);
}

string CHomeScene::fontToUtf8(string str)
{
	string strOutUTF8 = "";
	WCHAR* str1;
	int n = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
	str1 = new WCHAR[n];
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, str1, n);
	n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
	char * str2 = new char[n];
	WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
	strOutUTF8 = str2;
	delete[]str1;
	str1 = NULL;
	delete[]str2;
	str2 = NULL;
	return strOutUTF8;
}
void CHomeScene::actionCallBack(){

	m_pPlayer->stopActionByTag(1);
	m_pPlayer->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(m_sPet + "01.png"));
	m_lTalk->setString(this->fontToUtf8("下次可别乱跑啦！"));
}
void CHomeScene::endCallBack()
{
	m_lTalk->setString(this->fontToUtf8("快跟我回家吧！"));
}