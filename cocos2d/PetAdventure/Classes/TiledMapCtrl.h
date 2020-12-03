#ifndef __TiledMapCtrl_H__
#define __TiledMapCtrl_H__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;
class CTiledMapCtrl : public Node
{
public:
	CTiledMapCtrl();
	~CTiledMapCtrl();
	virtual bool init();
	void follow(Node* pTarget);
	Vec2 getTileByPos(const Vec2& pos);
	Vec2 getPosByTile(const Vec2& tile);
	string checkColliX(const Vec2& tile);
	string checkColliY(const Vec2& tile);
	string checkColliItem(const Vec2& tile);
	string checkColliBox(const Vec2& tile);
	string checkColliAir(const Vec2& tile);
	string checkColliCoin(const Vec2& tile);
	CREATE_FUNC(CTiledMapCtrl);
	CC_SYNTHESIZE_READONLY(Vec2, m_vBirthPos, BirthPos);
	CC_SYNTHESIZE_READONLY(Vec2, m_vEndPos, EndPos);
	CC_SYNTHESIZE_READONLY(vector<Vec2>, m_vCheckPos, CheckPos);
	CC_SYNTHESIZE_READONLY(vector<Vec2>, m_vEnemyPos, EnemyPos);
private:
	void initMap();
	void initObjectGroup();
private:
	TMXTiledMap* m_pTiledMap;
	TMXLayer* m_pFloor;
	TMXLayer* m_pBlock;
	TMXLayer* m_pLadder;
	TMXLayer* m_pBox;
	TMXLayer* m_pAir;
	TMXLayer* m_pRiver;
	TMXLayer* m_pCoin;
	TMXLayer* m_pKey;
	TMXLayer* m_pLive;
	TMXLayer* m_pDoor;
};
#endif