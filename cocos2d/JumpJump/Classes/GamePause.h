#ifndef __GamePause__H__
#define __GamePause__H__
#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class CGamePause :public Scene{
public:
	CGamePause();
	~CGamePause();
	virtual bool init();
	static CCScene* scene(CCRenderTexture* sqr);
	CREATE_FUNC(CGamePause);

	CC_SYNTHESIZE_READONLY(MenuItemImage*, m_pStartBtn, StartBtn);
	void menuContinueCallback(CCObject* pSender);
private:

};
#endif

