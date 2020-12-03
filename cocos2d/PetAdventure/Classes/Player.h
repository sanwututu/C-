#ifndef __Player_H__
#define __Player_H__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

enum
{
	E_STATE_NONE,
	E_STATE_IDLE,
	E_STATE_WALK,
	E_STATE_JUMP,
	E_STATE_ATTACK
};

class CPlayer :public Node
{
public:
	CPlayer();
	~CPlayer();
	virtual bool init();
	virtual void update(float delta);
	void changeState(int nState);
	void hurt();
	Rect getBoundingBoxToWorld();
	CREATE_FUNC(CPlayer);
	CC_SYNTHESIZE_READONLY(Sprite*, m_pImage, Image);
	CC_SYNTHESIZE_READONLY(bool, m_bAttack, Attack);
	CC_SYNTHESIZE_READONLY(bool, m_bKey, Key);
	CC_SYNTHESIZE_READONLY(int, m_nLive, Live);
	CC_SYNTHESIZE(int, m_nCoin, Coin);

private:
	//´´½¨¶¯»­
	void createAnims();
	void addKeyboardEvent();
	string checkCollicY();
	string checkCollicX();
	string checkCollicItem();
	string checkCollicBox();
	Vec2 getCollicPos(const Vec2& dir);
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* pEvent);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* pEvent);
	void onJumpCtrl();
private:
	bool m_bResetFollow;
	bool m_bLevitate;
	float m_fMaxX;
	int m_nState;
	int nLadder;
	float m_fAccel;
	int m_nDirX;
	string m_sPet;
	Vec2 m_vVelocity;
	Animation* m_pWalkAnim;
	Animation* m_pClimbAnim;
	Animation* m_pAttackAnim;
};
#endif