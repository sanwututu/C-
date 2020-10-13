#pragma once
#include "DataStruct.h"
struct SRoleSel
{
public:
	SRoleSel();
	~SRoleSel();

	void update();
	void render();

	int nState;
	vector<SRoleDt> VecData;
};

