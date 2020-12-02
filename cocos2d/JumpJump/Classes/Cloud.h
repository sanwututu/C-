#ifndef __Cloud_H__
#define __Cloud_H__

#include "cocos2d.h"
USING_NS_CC;
class CCloud :public Node{
public:
	CCloud();
	~CCloud();
	static CCloud* createCloud();
	virtual bool init();
	void move();
private:
	Sprite* m_pCloud;
};
#endif