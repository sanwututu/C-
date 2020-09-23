#pragma once
#include"Player.h"

struct SLevelDt
{
	string strName;
	int nID;
	int nRowSize;
	int nColSize;
	int nBirthRow;
	int nBirthCol;
	int arrMap[50][50];
};
struct SGameMap
{
public:
	SGameMap();
	//~SGameMap();
	void loadFile(string strPath);
	void update();
	void render();
	void transfer();
	SPlayer g_Player;
	SLevelDt levelDt;
	vector<SLevelDt> VecLevelDt;

};

