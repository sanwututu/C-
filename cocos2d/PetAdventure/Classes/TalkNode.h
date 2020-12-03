#ifndef __DialogLayer_H__
#define __DialogLayer_H__
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
class CDialogLayer : public CCLayerColor
{
	// 模态对话框菜单  
	CCMenu *m_pMenu;
	// 记录菜单点击  
	bool m_bTouchedMenu;

public:
	CDialogLayer();
	~CDialogLayer();

	virtual bool init();
	// 初始化对话框内容  
	void initDialog();

	CREATE_FUNC(CDialogLayer);

	void onEnter();
	void onExit();

	virtual bool TouchBegan(Touch *pTouch, Event *pEvent);
	virtual void TouchMoved(Touch *pTouch, Event *pEvent);
	virtual void TouchEnded(Touch *pTouch, Event *pEvent);
	virtual void TouchCancelled(Touch *pTouch, Event *pEvent);

	void okMenuItemCallback(Object *pSender);
	void cancelMenuItemCallback(Object *pSender);
};
#endif