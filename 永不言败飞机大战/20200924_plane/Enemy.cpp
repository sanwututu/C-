#include "stdafx.h"
#include "Enemy.h"


SEnemy::SEnemy()
{
	nRow = 0;
	nCol = 0;
	nSpeed = 0;
	nID = 0;
}
SEnemy::SEnemy(SEnemyDt config)
{
	m_nTimer = 0;
	nID = config.nID;
	nSpeed = config.nSpeed;
	strName = config.strName;
	strPic = config.strPic;
}
void SEnemy::update(){
	m_nTimer++;
	if (m_nTimer > nSpeed){
		m_nTimer = 0;
		nRow++;
	}
	
}

SEnemy::~SEnemy()
{
}
