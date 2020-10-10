#pragma once
class CGameMenu
{
public:
	CGameMenu();
	~CGameMenu();

	int m_nState;
	void update();
	void render();
};

