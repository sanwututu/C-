#ifndef __LevelMgr_H__
#define __LevelMgr_H__

#include "cocos2d.h"
#include "DataClass.h"
USING_NS_CC;
using namespace std;
class CLevelMgr{
public:
	CLevelMgr();
	~CLevelMgr();
	static CLevelMgr* getInstance();
	void changScene();
	void nextScene();
	void setLevelID(int nLevelID);
	CC_SYNTHESIZE_READONLY(int, m_nLevelID, LevelID);
	CC_SYNTHESIZE_READONLY(SLevelDt*, m_pLevelDt, LevelDt);
private:
	static CLevelMgr* m_pInstance;
};
#endif