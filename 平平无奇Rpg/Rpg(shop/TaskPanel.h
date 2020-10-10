#pragma once
#include "DataClass.h"
class CTaskPanel
{
public:
	CTaskPanel();
	~CTaskPanel();
	void update();
	void render();
	void refresh(int nNpcID);
private:
		int m_nState;
		vector<STaskDt*> m_VecData;
};

