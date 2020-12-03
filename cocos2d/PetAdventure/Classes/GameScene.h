#ifndef __GameScene_H__
#define __GameScene_H__
#include "cocos2d.h"
#include "TiledMapCtrl.h"
#include "Player.h"
#include "EnemyMgr.h"
USING_NS_CC;
using namespace std;
class CGameScene :public Scene
{
public:
	CGameScene();
	~CGameScene();
	virtual bool init();
	virtual void update(float delta);
	static CGameScene* getInstance();
	static void destroy();
	CREATE_FUNC(CGameScene);
	CC_SYNTHESIZE_READONLY(CTiledMapCtrl*, m_pTiledMapCtrl, TiledMapCtrl);
	CC_SYNTHESIZE_READONLY(CPlayer*, m_pPlayer, Player);
	CC_SYNTHESIZE_READONLY(CEnemyMgr*, m_pEnemyMgr, EnemyMgr);
	CC_SYNTHESIZE_READONLY(vector<Sprite*>, m_vLive, Live);

private:
	void collicEnemy();
private:
	static CGameScene* m_pInstance;
	Sprite* m_pKey;
	Sprite* m_pCoin;
	string m_sPet;
	Label* m_pLabel;
};
#endif