#include "stdafx.h"
#include "RoleSel.h"
#include "ConfigMgr.h"
#include "GameMgr.h"

SRoleSel::SRoleSel()
:nState(0)
{
	VecData = g_configMgr.roleDtMgr.VecData;
}


SRoleSel::~SRoleSel()
{
}

void SRoleSel::update()
{
	if (KEY_DOWN(VK_UP))
	{
		nState--;
		if (nState < 0)
		{
			nState = VecData.size() - 1;
		}
	}
	else if (KEY_DOWN(VK_DOWN))
	{
		nState++;
		if (nState > VecData.size() - 1)
		{
			nState = 0;
		}
	}
	else if (KEY_DOWN(VK_SPACE))
	{
		//将角色数据设置到玩家中
		g_gameMgr.gameMap.player.init(VecData[nState]);
		g_gameMgr.nGameState = E_GAME;
	}
}

void SRoleSel::render()
{
	cout << "  id\thp\tack\tBID\tname\tpic" << endl;
	for (int i = 0; i < VecData.size(); i++)
	{
		if (nState == i)
		{
			cout << "->";
		}
		else
		{
			cout << "  ";
		}
		SRoleDt data = VecData[i];
		cout << data.nID << "\t" << data.nHp << "\t" << data.nAck << "\t"
			<< data.nBulletID << "\t" << data.strName << "\t" << data.strPic << endl;
	}
}
