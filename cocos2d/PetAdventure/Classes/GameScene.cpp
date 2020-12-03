#include "GameScene.h"
#include "GameOver.h"
#include "RoleMgr.h"
#include "LevelMgr.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
CGameScene* CGameScene::m_pInstance = nullptr;
CGameScene::CGameScene()
{

}
CGameScene::~CGameScene()
{

}
CGameScene* CGameScene::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = CGameScene::create();
	}
	return m_pInstance;
}
bool CGameScene::init()
{
	if (!Scene::init()){
		return false;
	}

	//初始
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//
	m_pTiledMapCtrl = CTiledMapCtrl::create();
	this->addChild(m_pTiledMapCtrl);

	//怪物
	vector<Vec2> vEnemy = m_pTiledMapCtrl->getEnemyPos();
	m_pEnemyMgr = CEnemyMgr::create();
	m_pTiledMapCtrl->addChild(m_pEnemyMgr);
	m_pEnemyMgr->addEnemy(vEnemy);
	//玩家
	m_pPlayer = CPlayer::create();
	m_pTiledMapCtrl->addChild(m_pPlayer);
	Vec2 birthPos = m_pTiledMapCtrl->getBirthPos();
	m_pPlayer->setPosition(birthPos);

	m_pTiledMapCtrl->follow(m_pPlayer);
	//钥匙
	m_pKey = Sprite::createWithSpriteFrameName("no_key.png");
	m_pKey->setScale(2);
	m_pKey->setPosition(origin.x + visibleSize.width - 60, origin.y + visibleSize.height - 40);
	this->addChild(m_pKey);
	//金币
	m_pCoin = Sprite::createWithSpriteFrameName("coin_01.png");
	m_pCoin->setPosition(origin.x + visibleSize.width - 200, origin.y + visibleSize.height - 35);
	this->addChild(m_pCoin);
	//
	float fX = origin.x + visibleSize.width - 160;
	float fY = origin.y + visibleSize.height - 35;
	int nCoin = m_pPlayer->getCoin();
	char temp[32];
	sprintf(temp, "%d", nCoin, 10);
	string sCoin = temp;
	SLevelDt* pLevelDt = CLevelMgr::getInstance()->getLevelDt();
	
	m_pLabel = Label::createWithTTF(sCoin, "fonts/01digit.ttf", 25);
	m_pLabel->setPosition(Vec2(fX, fY));
		// add the label as a child to this layer
	this->addChild(m_pLabel, 1);

	int nCoinLimit = pLevelDt->nCoinLimit;
	sprintf(temp, "%d", nCoinLimit, 10);
	string sCoinLimit = temp;
	Label* pLimit = Label::createWithTTF("/" + sCoinLimit, "fonts/01digit.ttf", 25);
	pLimit->setPosition(Vec2(fX + 40, fY));
	this->addChild(pLimit, 1);

	//
	int nLive = m_pPlayer->getLive();
	for (int i = 0; i < nLive; i++){
		Sprite* pLive = Sprite::createWithSpriteFrameName("live.png");
		pLive->setPosition(origin.x +40 +(40 * i) , origin.y + visibleSize.height - 40);
		m_vLive.push_back(pLive);
		this->addChild(pLive);
	}
	this->scheduleUpdate();
	return true;
}
void CGameScene::update(float delta)
{
	this->collicEnemy();
	if (m_pPlayer->getKey()){
		m_pKey->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("key.png"));
	}
	//金币数
	char temp[32];
	int nCoin = m_pPlayer->getCoin();
	sprintf(temp, "%d", nCoin, 10); 
	std::string sCoin = temp;
	SLevelDt* pLevelDt = CLevelMgr::getInstance()->getLevelDt();
	m_pLabel->setString(sCoin);
	int nCoinLimit = pLevelDt->nCoinLimit;
	if (nCoin >= nCoinLimit){
		m_pLabel->setColor(Color3B(0,255,0));
	}
}
void CGameScene::collicEnemy()
{
	Vector<Node*> VecEnemy = m_pEnemyMgr->getChildren();
	for (Node* pNode : VecEnemy)
	{
		CEnemy* pEnemy = static_cast<CEnemy*>(pNode);
		Rect rcPlayer = m_pPlayer->getBoundingBoxToWorld();
		Rect rcEnemy = pEnemy->getBoundingBoxToWorld();
		if (rcEnemy.intersectsRect(rcPlayer))
		{
			if (m_pPlayer->getAttack())
			{
				//声音
				SimpleAudioEngine::sharedEngine()->playEffect("Music/attack.mp3", false);
				m_pEnemyMgr->removeChild(pEnemy);
				m_pPlayer->setCoin(m_pPlayer->getCoin()+1);
			}
			else
			{
				m_pPlayer->hurt();
			}
		}
	}
}
void CGameScene::destroy()
{
	m_pInstance = nullptr;
}