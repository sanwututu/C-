#ifndef __MoonMgr_H__
#define __MoonMgr_H__
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
class CMoonMgr :public Node{
public:
	CMoonMgr();
	~CMoonMgr();
	virtual bool init();
	virtual void setSpeed(float fSpeed);
	virtual void update(float delta);
	CREATE_FUNC(CMoonMgr);


private:
	void createMoon();
	float m_fSpeed;
	Sprite* m_pMoon;
	Sprite* m_pDust;
};

#endif