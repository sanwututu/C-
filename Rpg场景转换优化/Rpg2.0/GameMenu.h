#pragma once
#include "Scene.h"
class CGameMenu: public CScene
{
public:
	CGameMenu();
	~CGameMenu();

	void render();
	void update();
	static CGameMenu* create();
private:
};

