#ifndef __ItemMgr_H__
#define __ItemMgr_H__
#include "cocos2d.h"
#include "Cloud.h"
USING_NS_CC;
using namespace std;
class CItemMgr :public Node{
public:
	CItemMgr();
	~CItemMgr();

	virtual bool init();
	CREATE_FUNC(CItemMgr);
private:
	void addCloud(float fDelta);
private:
	int m_nTime;
};

#endif