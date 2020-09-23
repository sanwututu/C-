#pragma once
enum DIR
{
	E_DIR_UP,
	E_DIR_LEFT,
	E_DIR_DOWN,
	E_DIR_RIGHT
};
struct Vec2{
	int nRow;
	int nCol;
	int nRowBk;
	int nColBk;
};
struct SPlayer
{
public:

	
	SPlayer();
	~SPlayer();
	void revert();
	void setPosition(int nInRow, int nInCol);
	void update();
	void backup();
	void changeShape();
	void move(int nOffsetX,int nOffsetY);
	bool isExit(int nRow, int nCol);
	int nDir = E_DIR_UP;
	Vec2 arrPos[4];
};

