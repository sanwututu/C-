#include "LoadingScene.h"
#include "DataClass.h"
#include "SimpleAudioEngine.h"
#include "GameMenu.h"
#include "LevelMgr.h"

using namespace CocosDenshion;
CLoadingScene::CLoadingScene()
:m_nCurIndex(0)
, m_nState(0)
, m_nCount(0)
, m_nTotalSize(0)
, m_bCommonFinish(false)
{
}

CLoadingScene::~CLoadingScene()
{
}

bool CLoadingScene::initWithData(string strSceneName)
{
	if (!Scene::init())
	{
		return false;
	}
	m_strSceneName = strSceneName;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	m_pComDt = CResDtMgr::getInstance()->getData("Common");
	m_pSceneDt = CResDtMgr::getInstance()->getData(strSceneName);
	m_nTotalSize += (m_pComDt->VecPng.size() + m_pComDt->VecPlist.size() + m_pComDt->VecAudio.size());
	m_nTotalSize += (m_pSceneDt->VecPng.size() + m_pSceneDt->VecPlist.size() + m_pSceneDt->VecAudio.size());

	Sprite* pBg = Sprite::create("Default-Landscape_ipad.png");
	pBg->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(pBg);

	Sprite* pProgressBg = Sprite::create("Common/ui_ProgressBar_01.png");
	pProgressBg->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(pProgressBg);
	m_pProgress = ProgressTimer::create(Sprite::create("Common/ui_ProgressBar_02.png"));
	m_pProgress->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(m_pProgress);
	m_pProgress->setType(ProgressTimer::Type::BAR);
	m_pProgress->setMidpoint(Vec2(0, 0.5));
	m_pProgress->setBarChangeRate(Vec2(1, 0));

	this->scheduleUpdate();
	return true;
}

CLoadingScene* CLoadingScene::createWithData(string strSceneName)
{
	CLoadingScene* pScene = new CLoadingScene();
	if (pScene&&pScene->initWithData(strSceneName))
	{
		pScene->autorelease();
		return pScene;
	}
	CC_SAFE_DELETE(pScene);
	return nullptr;
}

void CLoadingScene::update(float delta)
{
	//资源未加载完成
	if (m_nCount < m_nTotalSize)
	{
		if (!m_bCommonFinish)
		{
			this->loadRes(m_pComDt);
		}
		else
		{
			this->loadRes(m_pSceneDt);
		}
		float fPercent = (float)m_nCount * 100 / m_nTotalSize;
		m_pProgress->setPercentage(fPercent);
	}
	else{
		this->unscheduleUpdate();
		//CCLOG("change scene!");

		if ("Menu" == m_strSceneName)
		{
			Scene* pScene = CGameMenu::create();
			TransitionFade* pFade = TransitionFade::create(1, pScene);
			Director::getInstance()->replaceScene(pFade);
		}
		else{
			CLevelMgr::getInstance()->changScene();
		}
	}

}

void CLoadingScene::loadRes(SResDt* pDt)
{
	if (0 == m_nState)
	{
		//加载png
		//判断是否加载完成
		if (m_nCurIndex >= pDt->VecPng.size())
		{
			m_nState = 1;//加载plist
			m_nCurIndex = 0;
			return;
		}
		string strPath = pDt->VecPng[m_nCurIndex];
		//纹理
		TextureCache* pCache = Director::getInstance()->getTextureCache();
		pCache->addImage(strPath);
		m_nCurIndex++;
		m_nCount++;
	}
	else if (1 == m_nState)
	{
		if (m_nCurIndex >= pDt->VecPlist.size())
		{
			m_nState = 2;
			m_nCurIndex = 0;
			return;
		}
		//加载plist
		SpriteFrameCache* pCache = SpriteFrameCache::getInstance();
		pCache->addSpriteFramesWithFile(pDt->VecPlist[m_nCurIndex]);
		m_nCurIndex++;
		m_nCount++;
	}
	else if (2 == m_nState)
	{
		if (m_nCurIndex >= pDt->VecAudio.size())
		{
			m_nState = 0;
			m_nCurIndex = 0;
			m_bCommonFinish = true;
			return;
		}
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic(pDt->VecAudio[m_nCurIndex].c_str());
		m_nCurIndex++;
		m_nCount++;
	}
}
