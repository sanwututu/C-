#include "stdafx.h"
#include "Player.h"
#include "GameMgr.h"


SPlayer::SPlayer()
{
}


SPlayer::~SPlayer()
{
}

void SPlayer::init(SRoleDt config)
{
	nID = config.nID;
	nHp = config.nHp;
	nAck = config.nAck;
	nBulletID = config.nBulletID;
	strName = config.strName;
	strPic = config.strPic;
}

void SPlayer::update()
{
	backup();
	if (KEY_DOWN(VK_UP))
	{
		move(-1, 0);
	}
	else if (KEY_DOWN(VK_DOWN))
	{
		move(1, 0);
	}
	else if (KEY_DOWN(VK_LEFT))
	{
		move(0, -1);
	}
	else if (KEY_DOWN(VK_RIGHT))
	{
		move(0, 1);
	}
	else if (KEY_DOWN(VK_SPACE))
	{
		//addBullet
		g_gameMgr.gameMap.bulletMgr.addBullet(nBulletID, nAck, true, arrPos[3].nRow, arrPos[3].nCol,nDir);
	}
	else if (KEY_DOWN(VK_SHIFT)){
		changeShape();
	}
}

void SPlayer::revert()
{
	for (int i = 0; i < 4; i++)
	{
		arrPos[i].nRow = arrPos[i].nRowBk;
		arrPos[i].nCol = arrPos[i].nColBk;
	}
}

void SPlayer::backup()
{
	for (int i = 0; i < 4; i++)
	{
		arrPos[i].nRowBk = arrPos[i].nRow;
		arrPos[i].nColBk = arrPos[i].nCol;
	}
}

void SPlayer::setPosition(int nInRow, int nInCol)
{
	arrPos[0].nRow = nInRow;
	arrPos[0].nCol = nInCol - 1;
	arrPos[1].nRow = nInRow;
	arrPos[1].nCol = nInCol;
	arrPos[2].nRow = nInRow;
	arrPos[2].nCol = nInCol + 1;
	arrPos[3].nRow = nInRow - 1;
	arrPos[3].nCol = nInCol;
}

void SPlayer::move(int nOffsetX, int nOffsetY)
{
	for (int i = 0; i < 4; i++)
	{
		arrPos[i].nRow += nOffsetX;
		arrPos[i].nCol += nOffsetY;
	}
}

void SPlayer::changeShape(){

	nDir++;

	if (nDir > E_DIR_RIGHT)
	{
		nDir = E_DIR_UP;
	}
	if (E_DIR_UP == nDir)
	{
		arrPos[0].nRow = arrPos[1].nRow;
		arrPos[0].nCol = arrPos[1].nCol - 1;
		arrPos[2].nRow = arrPos[1].nRow;
		arrPos[2].nCol = arrPos[1].nCol + 1;
		arrPos[3].nRow = arrPos[1].nRow - 1;
		arrPos[3].nCol = arrPos[1].nCol;
	}
	else if (E_DIR_DOWN == nDir)
	{
		arrPos[0].nRow = arrPos[1].nRow;
		arrPos[0].nCol = arrPos[1].nCol + 1;
		arrPos[2].nRow = arrPos[1].nRow;
		arrPos[2].nCol = arrPos[1].nCol - 1;
		arrPos[3].nRow = arrPos[1].nRow + 1;
		arrPos[3].nCol = arrPos[1].nCol;
	}
	else if (E_DIR_LEFT == nDir)
	{
		arrPos[0].nRow = arrPos[1].nRow + 1;
		arrPos[0].nCol = arrPos[1].nCol;
		arrPos[2].nRow = arrPos[1].nRow - 1;
		arrPos[2].nCol = arrPos[1].nCol;
		arrPos[3].nRow = arrPos[1].nRow;
		arrPos[3].nCol = arrPos[1].nCol - 1;
	}
	else if (E_DIR_RIGHT == nDir)
	{
		arrPos[0].nRow = arrPos[1].nRow - 1;
		arrPos[0].nCol = arrPos[1].nCol;
		arrPos[2].nRow = arrPos[1].nRow + 1;
		arrPos[2].nCol = arrPos[1].nCol;
		arrPos[3].nRow = arrPos[1].nRow;
		arrPos[3].nCol = arrPos[1].nCol + 1;
	}
}
//判断第i行第j列是否有玩家格子
bool SPlayer::isExit(int nRow, int nCol)
{
	for (int m = 0; m < 4; m++)
	{
		if (arrPos[m].nRow == nRow && arrPos[m].nCol == nCol)
		{
			return true;
		}
	}
	return false;
}
