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

void SBulletMgr::addBullet(int nID, int nAck, bool isPlayer, int nRow, int nCol,int nDir)
{
	SBulletDt bulletDt = g_configMgr.bulletDtMgr.getDataByID(nID);
	SBullet bullet(bulletDt);
	bullet.nRow = nRow;
	bullet.nCol = nCol;
	bullet.nAck = nAck;
	bullet.isPlayer = isPlayer;
	bullet.nDir = nDir;

	VecBullet.push_back(bullet);
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

void SBulletMgr::update()
{
	//遍历子弹，并调用子弹到update进行数据更新
	for (int i = 0; i < VecBullet.size(); i++)
	{
		VecBullet[i].update();
	}

	for (int i = VecBullet.size()-1; i >=0; i--)
	{
		if (VecBullet[i].nRow < 0)
		{
			VecBullet.erase(VecBullet.begin() + i);
		}
	}
}
