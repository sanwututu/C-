#ifndef __EndScene_H__
#define __EndScene_H__
#include "cocos2d.h"
#include "ItemMgr.h"
USING_NS_CC;
using namespace std;
class CEndScene :public Scene{
public:
	CEndScene();
	~CEndScene();
	static CEndScene* creatWithScore(int nScore);
	virtual bool initWithScore(int nScore);
	void gameReplayCallback(cocos2d::Ref* pSender);
private:
	Sprite* m_pBg;
	Label* m_pScore;
	/*int m_nScore;*/
};
#endif