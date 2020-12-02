#include "EndScene.h"
#include "GameScene.h"
#include "GameMenu.h"

CEndScene::CEndScene()
{

}
CEndScene::~CEndScene(){

}
CEndScene* CEndScene::creatWithScore(int nScore){
	CEndScene* pScene = new CEndScene();
	if (pScene&&pScene->initWithScore(nScore)){
		pScene->autorelease();
		return pScene;
	}
	CC_SAFE_DELETE(pScene);
	return nullptr;
}
bool CEndScene::initWithScore(int nScore){
	if (!Scene::init()){
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//背景图片
	m_pBg = Sprite::createWithSpriteFrameName("background.png");
	m_pBg->setScale(1.5);
	this->addChild(m_pBg);
	//分数
	//分数标签，类型转换
	char temp[32];
	sprintf(temp, "%d", nScore, 10);
	std::string sScore = temp;
	m_pScore = Label::createWithTTF("Score:" + sScore, "fonts/Marker Felt.ttf", 36);
	m_pScore->getContentSize();
	float x = visibleSize.width / 2;
	float y = visibleSize.height / 2;
	m_pScore->setPosition(x, y +100);
	this->addChild(m_pScore, 1);
	//重新开始
	auto m_pReplayBtn = MenuItemImage::create(
		"",
		"",
		CC_CALLBACK_1(CEndScene::gameReplayCallback, this));
	m_pReplayBtn->setNormalImage(Sprite::create("Image/ui_replay.png"));
	m_pReplayBtn->setSelectedImage(Sprite::create("Image/ui_replay.png"));
	m_pReplayBtn->setScale(1.5);
	m_pReplayBtn->setPosition(Vec2(x, y));

	auto menu = Menu::create(m_pReplayBtn, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	//
	Label* label = Label::createWithTTF("Back to Menu", "fonts/Marker Felt.ttf", 24);
	
		label->setPosition(Vec2(x,y -50));
		this->addChild(label, 1);

	return true;
}
void CEndScene::gameReplayCallback(Ref* pSender)
{
	CCLOG("rePlay");
	if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){
		SimpleAudioEngine::sharedEngine()->playEffect("Music/button.mp3", false);
	}
	//CGameScene::destroy();
	CGameMenu* pGameMenu = CGameMenu::create();
	Director::getInstance()->replaceScene(pGameMenu);
}