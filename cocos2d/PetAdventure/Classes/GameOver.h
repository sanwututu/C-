#ifndef __GameOver_H__
#define __GameOver_H__
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
class CGameOver : public Scene
{
public:
	CGameOver();
	~CGameOver();
	virtual bool init();
	CREATE_FUNC(CGameOver);
private:
	void onBtnClick(Ref* pSender);
private:

};
#endif