#ifndef __GameMenu_H__
#define __GameMenu_H__
#include "cocos2d.h"
#include "Player.h"
#include "MoonMgr.h"
#include "UI/CocosGUI.h"
USING_NS_CC;

static int m_nMusicState;
using namespace std;
using namespace ui;
class CGameMenu :public Scene{
public:
	CGameMenu();
	~CGameMenu();

	virtual void update(float delta);
	virtual bool init();
	void createMenu();
	void gameMusicCallback(cocos2d::Ref* pSender);
	void gameExplainCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(CGameMenu);

	CC_SYNTHESIZE_READONLY(Sprite*, m_pBg, Bg);
	CC_SYNTHESIZE_READONLY(Sprite*, m_pTitle, Title);
	CC_SYNTHESIZE_READONLY(MenuItemImage*, m_pMusicBtn, MusicBtn);
	CC_SYNTHESIZE_READONLY(MenuItemImage*, m_pExplainBtn, Explain);
	CC_SYNTHESIZE_READONLY(CPlayer*, m_pPlayer, Player);
	CC_SYNTHESIZE_READONLY(CMoonMgr*, m_pMoonMgr, MoonMgr);
private:
	void onBtnClick(Ref* pSender);
private:
	int nTime;
	Button* m_pBtnStart;
	void createAnims();

};

#endif