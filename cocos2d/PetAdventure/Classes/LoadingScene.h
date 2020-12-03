#ifndef __LoadingScene_H__
#define __LoadingScene_H__

#include "cocos2d.h"
#include "ResDtMgr.h"

USING_NS_CC;

class CLoadingScene : public Scene
{
public:
	CLoadingScene();
	~CLoadingScene();

	bool initWithData(string strSceneName);
	static CLoadingScene* createWithData(string strSceneName);
	virtual void update(float delta);
	//CREATE_FUNC(CLoadingScene);

private:
	void loadRes(SResDt* pDt);
private:
	string m_strSceneName;
	bool m_bCommonFinish;
	int m_nState;
	int m_nCount;
	int m_nTotalSize;
	int m_nCurIndex;
	SResDt* m_pComDt;
	SResDt* m_pSceneDt;
	ProgressTimer* m_pProgress;
};


#endif