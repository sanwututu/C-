#ifndef __GameMenu_H__
#define __GameMenu_H__

#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "UI/CocosGUI.h"
USING_NS_CC;
using namespace std;
using namespace ui;
using namespace CocosDenshion;
class CGameMenu : public Scene
{
public:
	CGameMenu();
	~CGameMenu();
	virtual bool init();
	CREATE_FUNC(CGameMenu);


private:
	void onStartClick(Ref* pSender);
	void onLeftBtnClick(Ref* pSender);
	void onRightBtnClick(Ref* pSender);
private:
	Sprite* m_pBg;
	Sprite* m_pTitle;
	Button* m_pLeft;
	Button* m_pRight;
	Button* m_pBtnStart;
};
#endif