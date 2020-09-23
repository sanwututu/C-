#include "stdafx.h"
#include "GameMgr.h"


SGameMgr::SGameMgr()
{	
	nGameState = 0;
}

//::×÷ÓÃÓò·û
void SGameMgr::update()
{
	if (0 == nGameState)
	{
		gameMenu.update();
	}
	else if (1 == nGameState)
	{
		gameMap.update();
	}
}

void SGameMgr::render()
{
	if (0 == nGameState)
	{
		gameMenu.render();
	}
	else if (1 == nGameState)
	{
		gameMap.render();
	}
}

