#include "stdafx.h"
#include "GameMgr.h"


SGameMgr::SGameMgr()
{
	nGameState = 0;
}

//::×÷ÓÃÓò·û
void SGameMgr::update()
{
	if (E_GAME_MENU == nGameState)
	{
		gameMenu.update(); 
	}
	else if (E_GAME_SEL == nGameState)
	{
		roleSel.update();
	}
	else if (E_GAME == nGameState)
	{
		gameMap.update();
		
	}
}

void SGameMgr::render()
{
	if (E_GAME_MENU == nGameState)
	{
		gameMenu.render();
	}
	else if (E_GAME_SEL == nGameState)
	{
		roleSel.render();
	}
	else if (E_GAME == nGameState)
	{
		gameMap.render();
	}
}


//SGameMgr::~SGameMgr()
//{
//}
