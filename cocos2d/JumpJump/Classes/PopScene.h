#ifndef __PopScene_H__
#define __PopScene_H__
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
class CPopScene : public CCLayer
{
public:
	CPopScene();
	~CPopScene();
    static CCScene * scene();
    bool init();
	CREATE_FUNC(CPopScene);
private:
    //注册触摸事件，实现ccTouchBegan()方法
	void addTouchEvent();
	bool onTouchBegan(Touch* pTouch, Event* pEvent);
	void onTouchEnded(Touch* pTouch, Event* pEvent);
    //在弹出的对话框上加俩个按钮，以下的函数是对应的按钮的处理事件
    void yesButton(CCObject * object);
    void noButton(CCObject * object);
    //设置对话框的title
    void setTitle();
    //设置对话框的文本内容
    void setContent();
    //m_size代表的是对话框背景的大小
    CCSize m_size;
    //对话框的背景精灵
    CCSprite * m_bgSprite;
};
#endif