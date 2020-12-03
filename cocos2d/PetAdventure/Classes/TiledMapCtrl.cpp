#include "TiledMapCtrl.h"
#include "LevelMgr.h"

CTiledMapCtrl::CTiledMapCtrl()
{

}
CTiledMapCtrl::~CTiledMapCtrl()
{

}

bool CTiledMapCtrl::init(){
	if (!Node::init()){
		return false;
	}
	this->initMap();
	this->initObjectGroup();
	return true;
}

void CTiledMapCtrl::initMap()
{
	//����TiledMap

	SLevelDt* pLevelDt = CLevelMgr::getInstance()->getLevelDt();
	m_pTiledMap = TMXTiledMap::create(pLevelDt->strTile);
	this->addChild(m_pTiledMap);

	m_pFloor = m_pTiledMap->getLayer("floor");
	m_pBlock = m_pTiledMap->getLayer("block");
	m_pLadder = m_pTiledMap->getLayer("ladder");
	m_pBox = m_pTiledMap->getLayer("box");
	m_pAir = m_pTiledMap->getLayer("air");
	m_pRiver = m_pTiledMap->getLayer("river");
	m_pDoor = m_pTiledMap->getLayer("door");
	m_pCoin = m_pTiledMap->getLayer("coin");
	m_pKey = m_pTiledMap->getLayer("key");
	m_pLive = m_pTiledMap->getLayer("live");
}

void CTiledMapCtrl::initObjectGroup()
{
	TMXObjectGroup* pObjGroup = m_pTiledMap->getObjectGroup("objects");
	ValueVector objs = pObjGroup->getObjects();
	for (cocos2d::Value& obj : objs)
	{
		ValueMap valueMap = obj.asValueMap();
		string strType = valueMap["type"].asString();
		if ("BirthPoint" == strType)
		{
			m_vBirthPos.x = valueMap["x"].asFloat();
			m_vBirthPos.y = valueMap["y"].asFloat();
		}
		else if ("CheckPoint" == strType)
		{
			Vec2 vPos;
			vPos.x = valueMap["x"].asFloat();
			vPos.y = valueMap["y"].asFloat();

			m_vCheckPos.push_back(vPos);
			int i = 1;
		}
		else if ("Dumpling" == strType)
		{
			Vec2 vPos;
			vPos.x = valueMap["x"].asFloat();
			vPos.y = valueMap["y"].asFloat();

			m_vEnemyPos.push_back(vPos);
		}
		else if ("EndPoint" == strType)
		{
			m_vEndPos.x = valueMap["x"].asFloat();
			m_vEndPos.y = valueMap["y"].asFloat();
		}
	}
}

cocos2d::Vec2 CTiledMapCtrl::getTileByPos(const Vec2& pos)
{
	//ÿ�����Ӵ�С
	Size sizeTile = m_pTiledMap->getTileSize();
	//��ͼ��С(�Ը���Ϊ��λ)
	Size sizeMap = m_pTiledMap->getMapSize();
	//��ͼ��С
	int nX = pos.x / sizeTile.width;
	int nY = (sizeTile.height * sizeMap.height - pos.y + 6) / sizeTile.height;
	return Vec2(nX, nY);
}

cocos2d::Vec2 CTiledMapCtrl::getPosByTile(const Vec2& tile)
{
	//ÿ�����Ӵ�С
	Size sizeTile = m_pTiledMap->getTileSize();
	//��ͼ��С(�Ը���Ϊ��λ)
	Size sizeMap = m_pTiledMap->getMapSize();
	Vec2 pos;
	pos.x = tile.x * sizeTile.width + sizeTile.width / 2;
	pos.y = sizeTile.height * sizeMap.height - tile.y * sizeTile.height - sizeTile.height / 2;
	return pos;
}
void CTiledMapCtrl::follow(Node* pTarget)
{
	this->stopAllActions();
	//ÿ�����Ӵ�С
	Size sizeTile = m_pTiledMap->getTileSize();
	//��ͼ��С(�Ը���Ϊ��λ)
	Size sizeMap = m_pTiledMap->getMapSize();
	float fWidth = sizeTile.width * sizeMap.width + this->getPositionX();
	CCLOG("fWidth = %f", fWidth);
	Follow* pFollow = Follow::create(pTarget, Rect(-this->getPositionX(), 0, fWidth, sizeTile.height*sizeMap.height));
	this->runAction(pFollow);
}


string CTiledMapCtrl::checkColliY(const Vec2& tile)
{
	//�ж��Ƿ����ذ�
	unsigned int nGID = m_pFloor->getTileGIDAt(tile);
	if (nGID > 0)
	{
		return "floor";
	}
	//�ж��Ƿ���ש��
	nGID = m_pBlock->getTileGIDAt(tile);
	if (nGID > 0)
	{
		return "block";
	}
	//�ж��Ƿ���ש��
	nGID = m_pBox->getTileGIDAt(tile);
	if (nGID > 0)
	{
		return "box";
	}
	//�ж��Ƿ�������
	nGID = m_pRiver->getTileGIDAt(tile);
	if (nGID > 0)
	{
		return "river";
	}
	return "none";
}

std::string CTiledMapCtrl::checkColliX(const Vec2& tile)
{
	//�ж��Ƿ���ש��
	unsigned int nGID = m_pBlock->getTileGIDAt(tile);
	if (nGID > 0)
	{
		return "block";
	}
	//�ж��Ƿ����ذ�
	nGID = m_pFloor->getTileGIDAt(tile);
	if (nGID > 0)
	{
		return "floor";
	}
	//�ж��Ƿ�������
	nGID = m_pBox->getTileGIDAt(tile);
	if (nGID > 0)
	{
		return "box";
	}
	return "none";
}
std::string CTiledMapCtrl::checkColliItem(const Vec2& tile)
{
	//�ж��Ƿ�������
	unsigned int nGID = m_pLadder->getTileGIDAt(tile);
	if (nGID > 0)
	{
		return "ladder";
	}
	//�ж��Ƿ�������
	nGID = m_pLive->getTileGIDAt(tile);
	if (nGID > 0)
	{
		m_pLive->removeTileAt(tile);
		return "live";
	}
	//����Ӳ��
	nGID = m_pCoin->getTileGIDAt(tile);
	if (nGID > 0)
	{
		m_pCoin->removeTileAt(tile);
		return "coin";
	}
	//�ж�����Կ��
	nGID = m_pKey->getTileGIDAt(tile);
	if (nGID > 0)
	{
		m_pKey->removeTileAt(tile);
		return "key";
	}
	////�ж��Ƿ�����
	nGID = m_pDoor->getTileGIDAt(tile);
	if (nGID > 0)
	{
		return "door";
	}
	return "none";
}
std::string CTiledMapCtrl::checkColliBox(const Vec2& tile)
{
	//�ж��Ƿ�������
	unsigned int nGID = m_pBox->getTileGIDAt(tile);
	if (nGID > 0)
	{
		return "box";
	}
	return "none";
}
std::string CTiledMapCtrl::checkColliAir(const Vec2& tile)
{
	if (m_pAir){
		unsigned int nGID = m_pAir->getTileGIDAt(tile);
		if (nGID > 0)
		{
			return "air";
		}
	}
	return "none";
}
std::string CTiledMapCtrl::checkColliCoin(const Vec2& tile)
{
	unsigned int nGID = m_pCoin->getTileGIDAt(tile);
	if (nGID > 0)
	{
		m_pCoin->removeTileAt(tile);
	}
	return "none";
}