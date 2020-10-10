#pragma once
#include "DataClass.h"
class CSelRole
{
public:
	CSelRole();
	~CSelRole();

	void update();
	void render();
private:
	int m_nState;
	vector<SRoleDt*> m_VecData;
};