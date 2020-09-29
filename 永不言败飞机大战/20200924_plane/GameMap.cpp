#include "stdafx.h"
#include "GameMap.h"
#include "ConfigMgr.h"
#include "GameMgr.h"


CGameMap::CGameMap()
{
	g_Player = new CPlayer();
	g_bulletMgr = new CBulletMgr();
	g_enemyMgr = new CEnemyMgr();
	m_pLevelDt = g_pConfigMgr->m_pLevelDtMgr->getDataByID(1001);
	g_Player->setPosition(m_pLevelDt->nBirthRow, m_pLevelDt->nBirthCol);

}
CGameMap::~CGameMap()
{

		SAFE_DEL(g_Player);
		SAFE_DEL(g_bulletMgr);
		SAFE_DEL(g_enemyMgr);
}
void CGameMap::update()
{

	g_Player->update();
	g_bulletMgr->update();
	g_enemyMgr->update();

	for (int i = 0; i < 4; i++){
		int nValue = m_pLevelDt->pArrMap[g_Player->arrPos[i].nRow][g_Player->arrPos[i].nCol];
		//判断是否撞墙了
		if (1 == nValue)
		{
			g_Player->revert();
		}
		else if (nValue > 1000)
		{
			m_pLevelDt = g_pConfigMgr->m_pLevelDtMgr->getDataByID(nValue);
			g_Player->setPosition(m_pLevelDt->nBirthRow, m_pLevelDt->nBirthCol);
			break;
		}
	}
	
	//子弹与敌人消除效果
	for (int i = 0; i < g_bulletMgr->VecBullet.size(); i++)
	{
		CBullet* bullet = new CBullet();
		bullet = g_bulletMgr->VecBullet[i];

		/*CBullet& bullet = g_bulletMgr->VecBullet[i];*/
		for (int j = 0; j <g_enemyMgr->VecEnemy.size(); j++){
			CEnemy* enemy = new CEnemy();
			enemy = g_enemyMgr->VecEnemy[j];
			if (bullet->nRow == enemy->nRow && bullet->nCol == enemy->nCol){
				enemy->nHp -= bullet->nAck;
				if (enemy->nHp <= 0){
					//移除敌人
					g_enemyMgr->VecEnemy.erase(g_enemyMgr->VecEnemy.begin() + j);

				}
				//移除子弹
				g_bulletMgr->VecBullet.erase(g_bulletMgr->VecBullet.begin() + i);
				break;
			}
		}
		
	}
	
}

void CGameMap::render()
{
	cout << m_pLevelDt->strName << endl;
	for (int i = 0; i < m_pLevelDt->nRowSize; i++)
	{
		for (int j = 0; j < m_pLevelDt->nColSize; j++)
		{
			
			int nValue = m_pLevelDt->pArrMap[i][j];
			CBullet* bullet = new CBullet();
			bullet = g_bulletMgr->getBullet(i, j);
			CEnemy* enemy = new CEnemy();
			enemy = g_enemyMgr->getEnemy(i, j);


			if (1 == nValue)
			{
				cout << "■";
			}
			else if (g_Player->isExit(i, j))
			{
				cout << g_Player->strPic;
			}
			else if (nValue > 1000)
			{
				cout << "◎";
			}
			else if (bullet->nID > 2000)
			{
				cout << bullet->strPic;
			}
			else if (enemy->nID > 3000)
			{
				cout << enemy->strPic;
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}


// SGameMap::~SGameMap()
// {
// }
