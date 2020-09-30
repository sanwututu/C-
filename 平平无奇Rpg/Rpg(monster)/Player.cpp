#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
	m_nRow = 0;
	m_nCol = 0;
	m_nID = 0;
	m_nHp = 0;
	m_nAck = 0;
}


CPlayer::~CPlayer()
{
}

void CPlayer::update()
{
	backup();
	if (KEY_DOWN(VK_UP))
	{
		m_nRow--;
	}
	else if (KEY_DOWN(VK_DOWN))
	{
		m_nRow++;
	}
	else if (KEY_DOWN(VK_LEFT))
	{
		m_nCol--;
	}
	else if (KEY_DOWN(VK_RIGHT))
	{
		m_nCol++;
	}
}

int CPlayer::getRow()
{
	return m_nRow;
}

int CPlayer::getCol()
{
	return m_nCol;
}

void CPlayer::render()
{
	cout << m_strPic;
}

void CPlayer::setRow(int nRow)
{
	m_nRow = nRow;
}

void CPlayer::setCol(int nCol)
{
	m_nCol = nCol;
}
void CPlayer::backup(){
	//备份坐标
	m_nRowBk = m_nRow;
	m_nColBk = m_nCol;

}
void CPlayer::revert(){
	//返回备份坐标
		m_nRow = m_nRowBk;
		m_nCol = m_nColBk;
	
}
void CPlayer::initConfig(SRoleDt* pConfig)
{
	m_nID = pConfig->nID;
	m_nAck = pConfig->nAck;
	m_nHp = pConfig->nHp;
	m_strName = pConfig->strName;
	m_strPic = pConfig->strPic;
}
