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
    //ע�ᴥ���¼���ʵ��ccTouchBegan()����
	void addTouchEvent();
	bool onTouchBegan(Touch* pTouch, Event* pEvent);
	void onTouchEnded(Touch* pTouch, Event* pEvent);
    //�ڵ����ĶԻ����ϼ�������ť�����µĺ����Ƕ�Ӧ�İ�ť�Ĵ����¼�
    void yesButton(CCObject * object);
    void noButton(CCObject * object);
    //���öԻ����title
    void setTitle();
    //���öԻ�����ı�����
    void setContent();
    //m_size������ǶԻ��򱳾��Ĵ�С
    CCSize m_size;
    //�Ի���ı�������
    CCSprite * m_bgSprite;
};
#endif