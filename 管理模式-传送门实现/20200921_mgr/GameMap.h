#pragma once

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
struct SPlayer
{
	SPlayer(){
		nRow = 5;
		nCol = 5;
		nRowBk = 5;
		nColBk = 5;
	}

	int nRow;
	int nCol;
	int nRowBk;
	int nColBk;
};

struct SGameMap
{
public:
	SGameMap();
	//~SGameMap();
	void loadFile(string strPath);
	void update();
	void render();
	void colli();
	void transfer();
	int nCurLevelID;
	vector<SLevelDt> VecLevelDt;
	SPlayer g_Player;
	SLevelDt levelDt;

};

