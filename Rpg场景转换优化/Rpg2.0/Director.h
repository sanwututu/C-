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
	//�޸ĵ�ǰ����ָ��ָ��
	void replaceScene(CScene* pScene);
	//��ȡ��ǰִ�еĳ���
	CScene* getRunningScene()
	{
		return m_pCurScene;
	}
private:
	CDirector();
	static CDirector* m_spInstance;
	//����������ǰҪ���еĳ���
	CScene* m_pCurScene;
};

