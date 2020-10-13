#include "stdafx.h"
#include "Bullet.h"


SBullet::SBullet()
{
	nID = 0;
	nRow = 0;
	nCol = 0;
	nSpeed = 0;
	nAck = 0;
}

SBullet::SBullet(SBulletDt config)
{
	isPlayer = true;
	nID = config.nID;
	nSpeed = config.nSpeed;
	strName = config.strName;
	strPic = config.strPic;
}


SBullet::~SBullet()
{
}

void SBullet::update()
{
	if (isPlayer)
	{
		if (E_DIR_UP == nDir)
		{
			nRow--;
		}
		else if (E_DIR_DOWN == nDir){
			nRow++;
		}
		else if (E_DIR_LEFT == nDir){

			nCol--;
		}
		else if (E_DIR_RIGHT == nDir)
		{
			nCol++;
		}
	} 
	else
	{
		if (E_DIR_UP == nDir)
		{
			nRow++;
		}
		else if (E_DIR_DOWN == nDir){

			nRow--;
		}
		else if (E_DIR_LEFT == nDir){

			nCol--;
		}
		else if (E_DIR_RIGHT == nDir)
		{
			nCol++;
		}
	}
}
