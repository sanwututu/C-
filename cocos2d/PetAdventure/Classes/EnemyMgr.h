#ifndef __EnemyMgr_H__
#define __EnemyMgr_H__

#include "cocos2d.h"
#include "Enemy.h"
USING_NS_CC;
class CEnemyMgr : public Node
{
public:
	CEnemyMgr();
	~CEnemyMgr();

	virtual bool init();
	CREATE_FUNC(CEnemyMgr);
	void addEnemy(vector<Vec2> vEnemy);
	//CEnemy* checkCollicEnemy(const Vec2& worldPos);
private:
private:
};
#endif