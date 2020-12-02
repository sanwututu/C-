#ifndef __GameScene_H__
#define __GameScene_H__
#include "cocos2d.h"
#include "Player.h"
#include "MoonMgr.h"
#include "StarMgr.h"
#include "ItemMgr.h"

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;

using namespace std;
class CGameScene :public Scene{
public:
	CGameScene();
	~CGameScene();

	static CGameScene* getInstance();
	virtual void update(float delta);
	static void destroy();
	void createMenu();
	void gamePauseCallback(CCObject* pSender);
	void gameReplayCallback(cocos2d::Ref* pSender);
	void gameMusicCallback(cocos2d::Ref* pSender);
	virtual bool init();

	CREATE_FUNC(CGameScene);
	CC_SYNTHESIZE_READONLY(Sprite*, m_pBottle, Bottle);
	CC_SYNTHESIZE_READONLY(MenuItemImage*, m_pPauseBtn, PauseBtn);
	CC_SYNTHESIZE_READONLY(MenuItemImage*, m_pMusicBtn, MusicBtn);
	CC_SYNTHESIZE_READONLY(MenuItemImage*, m_pReplayBtn, Replay);
	CC_SYNTHESIZE_READONLY(CPlayer*, m_pPlayer, Player);
	CC_SYNTHESIZE_READONLY(CMoonMgr*, m_pMoonMgr, MoonMgr);
	CC_SYNTHESIZE_READONLY(CStarMgr*, m_pStarMgr, StarMgr);
	CC_SYNTHESIZE_READONLY(CItemMgr*, m_pItemMgr, ItemMgr);
private:
	void createAnims();
	void addRes();
	void collicStar();
private:
	int m_nScore;
	int m_nTime;
	Label* m_pLabel;
	Sprite* m_pBg;
	Sprite* m_pHp;
	ProgressTimer* m_preal;
	static CGameScene* m_pInstance;

};
#endif