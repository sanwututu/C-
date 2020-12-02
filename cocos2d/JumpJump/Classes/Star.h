#ifndef __Star_H__
#define __Star_H__

#include "cocos2d.h"
#include "DataClass.h"
USING_NS_CC;
class CStar :public Node{
public:
	CStar();
	~CStar();
	virtual bool initWithData(SStarDt* pData);
	static CStar* createWithData(SStarDt* pConfig);
	void move(int nSpeed);
	Rect getBoundingBoxToWorld();
	CC_SYNTHESIZE_READONLY(Sprite*, m_pImage, Image);
	CC_SYNTHESIZE(int, m_nScore, Score);
private:
};

#endif