#ifndef __Player_H__
#define __Player_H__

#include "cocos2d.h"
USING_NS_CC;
enum
{
	E_DIR_NONE,
	E_DIR_UP,
	E_DIR_DOWN
};
class CPlayer : public Node{
public:
	CPlayer();
	~CPlayer();
	virtual bool init();
	virtual void update(float delta);
	Rect getBoundingBoxToWorld();
	CREATE_FUNC(CPlayer);
	CC_SYNTHESIZE_READONLY(Sprite*, m_pImage, Image);
private:
	void createAnims();
	void addTouchEvent();
	bool onTouchBegan(Touch* pTouch, Event* pEvent);
	void onTouchEnded(Touch* pTouch, Event* pEvent);
private:
	int m_nState;
	int m_nDir;
	float m_fHight;
	Animation* m_pAnimJump;

};
#endif