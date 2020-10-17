#pragma once
class CNode
{
public:
	CNode();
	~CNode();
	//�麯��
	virtual void render();
	virtual void update();
	//������ӽڵ�
	virtual void addChild(CNode* pNode, int nZOrder = 0);
	//дһ���ӿڣ��ж������Ƿ���ĳ���ڵ�
	bool isContainNode(CNode* pNode);
	//�Ƴ�����
	virtual void removeChild(CNode* pNode);
	//ͨ�����ֻ�ȡ����
	CNode* getChildByName(string strName);
	//����һ���������(˳�򣩣�����������С������ʾ˳�� ������ֵһ������ô�ȹ���ȥ����ʾ�������ȥ����ʾ
	//��order�̸ߵ�������ʾ��ǰ���ǣ����������нڵ㶼����ͬһ�����׽ڵ��ϡ���
	void setZOrder(int nZOrder)
	{
		//�޸���֮��Ҫ����
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
	//Ӧ����һ���������ڴ洢Ҫ�ŵ���ǰ�ڵ����������Ԫ�أ��ڵ㣩
	vector<CNode*> m_vecChildren;
private:
		//�Ժ�������������������order
		void sortChildrenByOrder();
		int m_nZOrder;
};

