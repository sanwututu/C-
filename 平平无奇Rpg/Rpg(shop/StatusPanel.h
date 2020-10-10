#pragma once
#include "Player.h"
class CStatusPanel
{
public:
	CStatusPanel();
	~CStatusPanel();
	void update();
	void render();
private:
	int m_nState;
	vector<SGoodsDt*> m_VecItem;
	vector<STaskDt*> m_VecTask;
};

