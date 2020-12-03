#include "GameOver.h"
#include "GameMenu.h"

CGameOver::CGameOver()
{

}

CGameOver::~CGameOver()
{

}

bool CGameOver::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Label* label = Label::createWithTTF("GameOver!", "fonts/01digit.ttf", 60);
	label->setColor(Color3B(255, 0, 0));
	label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 100));
	this->addChild(label, 1);

	Label* pStart = Label::createWithTTF("Back To Menu", "fonts/01digit.ttf", 24);
	MenuItemLabel* m_pStart = MenuItemLabel::create(pStart, CC_CALLBACK_1(CGameOver::onBtnClick, this));
	m_pStart->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

	Menu* newmenu = Menu::create(m_pStart, NULL);
	newmenu->setPosition(Vec2::ZERO);
	this->addChild(newmenu, 1);
	return true;
}

void CGameOver::onBtnClick(Ref* pSender)
{
	CGameMenu* pGameMenu = CGameMenu::create();
	Director::getInstance()->replaceScene(pGameMenu);
}