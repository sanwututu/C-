#include "stdafx.h"
#include "Enemy.h"


CEnemy::CEnemy()
{
	nRow = 0;
	nCol = 0;
	nSpeed = 0;
	nID = 0;
}
void CEnemy::init(SEnemyDt* config)
{
	m_nTimer = 0;
	nID = config->nID;
	nSpeed = config->nSpeed;
	nAck = config->nAck;
	nHp = config->nHp;
	strName = config->strName;
	strPic = config->strPic;
}
void CEnemy::update(){
	m_nTimer++;
	if (m_nTimer > nSpeed){
		m_nTimer = 0;
		nRow++;
	}
	
}

CEnemy::~CEnemy()
{
}
