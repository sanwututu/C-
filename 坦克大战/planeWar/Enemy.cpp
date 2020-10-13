#include "stdafx.h"
#include "Enemy.h"
#include "ConfigMgr.h"
#include "GameMgr.h"

SEnemy::SEnemy()
{
	m_nTimer = 0;
	m_nTimer1 = 0;
	nDir = 0;
	nID = 0;
	nHp = 0;
	nAck = 0;
	nSpeed = 0;
	nBulletID = 0;
}

void SEnemy::init(SEnemyDt config)
{
	m_nTimer = 0;
	m_nTimer1 = 0;
	nID = config.nID;
	nHp = config.nHp;
	nAck = config.nAck;
	nSpeed = config.nSpeed;
	nAckSpeed = config.nAckSpeed;
	nBulletID = config.nBulletID;
	strName = config.strName;
	strPic = config.strPic;
}


SEnemy::~SEnemy()
{
}

void SEnemy::setPosition(int nRow, int nCol)
{
	arrPos[0].nRow = nRow;
	arrPos[0].nCol = nCol - 1;
	arrPos[1].nRow = nRow;
	arrPos[1].nCol = nCol;
	arrPos[2].nRow = nRow;
	arrPos[2].nCol = nCol + 1;
	arrPos[3].nRow = nRow + 1;
	arrPos[3].nCol = nCol;
}

void SEnemy::move()
{
	m_nTimer++;
	if (m_nTimer > nSpeed)
	{
		m_nTimer = 0;
		for (int i = 0; i < 4; i++)
		{
			if (E_DIR_UP == nDir)
			{
				arrPos[i].nRow++;

			}
			else if (E_DIR_DOWN == nDir)
			{
				arrPos[i].nRow--;
			}
			else if (E_DIR_LEFT == nDir)
			{
				arrPos[i].nCol--;
			}
			else if (E_DIR_RIGHT == nDir)
			{
				arrPos[i].nCol++;
			}

		}
	}

}
void SEnemy::backup()
{
	for (int i = 0; i < 4; i++)
	{
		arrPos[i].nRowBk = arrPos[i].nRow;
		arrPos[i].nColBk = arrPos[i].nCol;
	}
}
void SEnemy::revert()
{
	for (int i = 0; i < 4; i++)
	{
		arrPos[i].nRow = arrPos[i].nRowBk;
		arrPos[i].nCol = arrPos[i].nColBk;
	}
}
void SEnemy::changeshape(){

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
		arrPos[3].nRow = arrPos[1].nRow + 1;
		arrPos[3].nCol = arrPos[1].nCol;
	}
	else if (E_DIR_DOWN == nDir)
	{
		arrPos[0].nRow = arrPos[1].nRow;
		arrPos[0].nCol = arrPos[1].nCol + 1;
		arrPos[2].nRow = arrPos[1].nRow;
		arrPos[2].nCol = arrPos[1].nCol - 1;
		arrPos[3].nRow = arrPos[1].nRow - 1;
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
bool SEnemy::isExit(int nRow, int nCol)
{
	//判断第nRow行nCol列是否有敌人
	for (int i = 0; i < 4; i++)
	{
		if (arrPos[i].nRow == nRow && arrPos[i].nCol == nCol)
		{
			return true;
		}
	}
	return false;
}



void SEnemy::update()
{
	backup();
	move();
	changeshape();
	fire();
}

void SEnemy::fire()
{
	m_nTimer1++;
	if (m_nTimer1 > nAckSpeed)
	{
		m_nTimer1 = 0;
		g_gameMgr.gameMap.bulletMgr.addBullet(nBulletID, nAck, false, arrPos[1].nRow, arrPos[1].nCol,nDir);
	}
}
