#pragma once
#include "Scene.h"
class CGameMap: public CScene
{
public:
	CGameMap();
	~CGameMap();
	void render();
	void update();
	static CGameMap* create();
};

