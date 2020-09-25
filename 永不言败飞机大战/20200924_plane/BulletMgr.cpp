#include "stdafx.h"
#include "BulletMgr.h"
#include "GameMgr.h"
#include "ConfigMgr.h"


SBulletMgr::SBulletMgr()
{
}
SBulletMgr::~SBulletMgr()
{
}
void SBulletMgr::addBullet(int nID, int nRow, int nCol)
{
	SBullet bullet;
	bullet.nRow = nRow;
	bullet.nCol = nCol;
	bullet.nID = nID;
	SBulletDt  bulletDt = g_configMgr.bulletDtMgr.getDataByID(nID);
	
	bullet.nSpeed = bulletDt.nSpeed;
	bullet.strName = bulletDt.strName;
	bullet.strPic = bulletDt.strPic;
	bullet.nAck = bulletDt.nAck;

	VecBullet.push_back(bullet);
	VecBullet[VecBullet.size() - 1].nDir = g_gameMgr.gameMap.g_Player.nDir;
} 
SBullet SBulletMgr::getBullet(int nRow, int nCol)
{
	for (int i = 0; i < VecBullet.size(); i++)
	{
		if (VecBullet[i].nRow == nRow && VecBullet[i].nCol == nCol)
		{
			return VecBullet[i];
		}
	}
	SBullet bullet;
	return bullet;
}
void SBulletMgr::update(){
	//�����ӵ����������ӵ���update�������ݸ���
	for (int i = 0; i < VecBullet.size(); i++)
	{
		VecBullet[i].update();
	}
	//�Ƴ��ӵ�
	for (int i = VecBullet.size() - 1; i >= 0; i--)
	{
		if (VecBullet[i].nRow < 0 || VecBullet[i].nCol < 0 || VecBullet[i].nRow > g_gameMgr.gameMap.levelDt.nRowSize || VecBullet[i].nCol > g_gameMgr.gameMap.levelDt.nColSize)
		{
			VecBullet.erase(VecBullet.begin() + i);
		}
	}
}

