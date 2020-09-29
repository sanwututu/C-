#include "stdafx.h"
#include "BulletMgr.h"
#include "GameMgr.h"
#include "ConfigMgr.h"


CBulletMgr::CBulletMgr()
{
}

void CBulletMgr::addBullet(int nID, int nRow, int nCol)
{
	CBullet* bullet = new CBullet();
	bullet->nRow = nRow;
	bullet->nCol = nCol;
	bullet->nID = nID;
	SBulletDt* bulletDt = new SBulletDt();
	bulletDt = g_pConfigMgr->m_pBulletDtMgr->getDataByID(nID);
	
	bullet->nSpeed = bulletDt->nSpeed;
	bullet->strName = bulletDt->strName;
	bullet->strPic = bulletDt->strPic;
	bullet->nAck = bulletDt->nAck;

	VecBullet.push_back(bullet);
	VecBullet[VecBullet.size() - 1]->nDir = g_pGameMgr->m_pGameMap->g_Player->nDir;
} 
CBullet* CBulletMgr::getBullet(int nRow, int nCol)
{
	for (int i = 0; i < VecBullet.size(); i++)
	{
		if (VecBullet[i]->nRow == nRow && VecBullet[i]->nCol == nCol)
		{
			return VecBullet[i];
		}
	}
	CBullet* bullet = new CBullet();
	return bullet;
}
void CBulletMgr::update(){
	//遍历子弹，并调用子弹到update进行数据更新
	for (int i = 0; i < VecBullet.size(); i++)
	{
		VecBullet[i]->update();
	}
	//移除子弹
	for (int i = VecBullet.size() - 1; i >= 0; i--)
	{
		if (VecBullet[i]->nRow < 0 || VecBullet[i]->nCol < 0 || VecBullet[i]->nRow > g_pGameMgr->m_pGameMap->m_pLevelDt->nRowSize || VecBullet[i]->nCol > g_pGameMgr->m_pGameMap->m_pLevelDt->nColSize)
		{
			VecBullet.erase(VecBullet.begin() + i);
		}
	}
}
CBulletMgr::~CBulletMgr()
{
}
