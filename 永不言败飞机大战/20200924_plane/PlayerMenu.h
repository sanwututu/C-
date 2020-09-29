#pragma once
class CPlayerMenu
{
public:
	CPlayerMenu();
	~CPlayerMenu();
	int nPlayerState;
	int nHp;
	int nAck;
	void init();
	void update();
	void render();
	void getValue(int nInHp, int nInAck);
};

