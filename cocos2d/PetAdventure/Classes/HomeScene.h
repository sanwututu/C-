#ifndef __HomeScene_H__
#define __HomeScene_H__
#include "cocos2d.h"
#include "TiledMapCtrl.h"
#include "Player.h"
USING_NS_CC;
using namespace std;

class CHomeScene :public Scene
{
public:
	CHomeScene();
	~CHomeScene();
	virtual bool init();
	void createAnims();
	string fontToUtf8(string str);
	virtual void update(float delta);
	CREATE_FUNC(CHomeScene);
	CC_SYNTHESIZE_READONLY(CTiledMapCtrl*, m_pTiledMapCtrl, TiledMapCtrl);
private:
	void actionCallBack();
	void endCallBack();
private:
	int m_nTime;
	Sprite* m_pPlayer;
	Sprite* m_pMaster;
	string m_sPet;
	Label* m_lTalk;
};
#endif