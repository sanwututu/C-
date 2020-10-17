#pragma once
#include "Scene.h"
class CDirector
{
public:
	~CDirector();
	static CDirector* getInstance();
	void run();
	void update();
	void render();
	//修改当前场景指针指向
	void replaceScene(CScene* pScene);
	//获取当前执行的场景
	CScene* getRunningScene()
	{
		return m_pCurScene;
	}
private:
	CDirector();
	static CDirector* m_spInstance;
	//管理场景，当前要运行的场景
	CScene* m_pCurScene;
};

