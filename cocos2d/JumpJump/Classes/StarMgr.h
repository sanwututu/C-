#ifndef __StarMgr_H__
#define __StarMgr_H__
#include "cocos2d.h"
#include "DataClass.h"
#include "Star.h"
USING_NS_CC;
using namespace std;
class CStarMgr :public Node{
public:
	CStarMgr();
	~CStarMgr();

	virtual bool init();
	CREATE_FUNC(CStarMgr);
	CC_SYNTHESIZE(int, m_nSpeed,Speed);
	CC_SYNTHESIZE(int, m_nTimeControl, TimeControl);
private:
	void addStar(float fDelta);
private:
	SStarDt* m_pStarDt;
	int m_nTime;
};

#endif