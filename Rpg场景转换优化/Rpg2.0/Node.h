#pragma once
class CNode
{
public:
	CNode();
	~CNode();
	//虚函数
	virtual void render();
	virtual void update();
	//用于添加节点
	virtual void addChild(CNode* pNode, int nZOrder = 0);
	//写一个接口，判断容器是否含有某个节点
	bool isContainNode(CNode* pNode);
	//移除孩子
	virtual void removeChild(CNode* pNode);
	//通过名字获取孩子
	CNode* getChildByName(string strName);
	//处理一个层次索引(顺序），根据索引大小处理显示顺序： 如果这个值一样，那么先挂上去后显示，后挂上去先显示
	//让order教高的优先显示（前提是：必须是所有节点都挂在同一个父亲节点上。）
	void setZOrder(int nZOrder)
	{
		//修改完之后要排序
		m_nZOrder = nZOrder;
		this->getParent()->sortChildrenByOrder();
	}
	int getZOrder()
	{
		return m_nZOrder;
	}	
	SYN_THE_SIZE(CNode*, m_pParent, Parent);
	SYN_THE_SIZE(string, m_strName, Name);
protected:
	//应该有一个容器用于存储要放到当前节点上面的其他元素（节点）
	vector<CNode*> m_vecChildren;
private:
		//对孩子容器进行排序，依据order
		void sortChildrenByOrder();
		int m_nZOrder;
};

