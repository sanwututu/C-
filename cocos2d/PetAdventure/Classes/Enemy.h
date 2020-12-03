#ifndef __Enemy_H__
#define __Enemy_H__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;
class CEnemy :public Node
{
public:
	CEnemy();
	~CEnemy();

	static CEnemy* createWithData();
	bool initWithData();
	virtual void update(float delta);
	//bool isCollic(const Vec2& worldPos);
	Rect getBoundingBoxToWorld();
	CC_SYNTHESIZE_READONLY(Sprite*, m_pImage, Image);
private:
	string checkCollicX();
	string checkCollicAir();
	Vec2 getCollicPos(const Vec2& dir);
	void createAnim();
	void move();
private:
	int m_nDir;
	int m_nSpeed;
	Animation* pAnimation;

};
#endif