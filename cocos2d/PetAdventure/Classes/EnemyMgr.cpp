#include "EnemyMgr.h"
#include "GameScene.h"

CEnemyMgr::CEnemyMgr()
{

}
CEnemyMgr::~CEnemyMgr()
{

}

bool CEnemyMgr::init()
{
	if (!Node::init())
	{
		return false;
	}
	return true;
}

void CEnemyMgr::addEnemy(vector<Vec2> vEnemy)
{
	vector<Vec2> vEnemyPos = vEnemy;
	for (Vec2 vPos : vEnemyPos){
		CEnemy* pEnemy = CEnemy::createWithData();
		pEnemy->setPosition(vPos);
		this->addChild(pEnemy);
	}
}
