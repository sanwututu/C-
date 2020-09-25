#pragma once
struct SPlayerMenu
{
public:
	SPlayerMenu();
	~SPlayerMenu();
	int nPlayerState;
	int nPlayerID;
	void update();
	void render();
};

