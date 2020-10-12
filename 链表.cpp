//
#include "stdafx.h"
#include <windows.h>
#include <iostream>
using namespace std;

//ÿ���ڵ�����͡�
struct SNode
{
	SNode()
	{
		nID = 0;
		pNextNode = nullptr;
	}
	//Ҫ�洢������
	int nID;
	//ָ����һ���ڵ��ָ��
	SNode* pNextNode;
};

//��������:����1:��Ҫ����������ĳ��ȣ�
void createList(int nSize,SNode* pHead);
//��������ÿ���ڵ㣬������������ͷָ��
void traversingList(SNode* pHead);
//���ҽڵ�:λ�ã�ͷ���
SNode* findNode(int nIndex, SNode* pHead);
//����ڵ�:λ�ã�ͷ���,����Ľڵ㡣
void insertNode(SNode*& pHead, SNode* pInsertNode, int nIndex = 0);

//ɾ��
//��ת
int _tmain(int argc, _TCHAR* argv[])
{
	//���ȱ��뱣֤����ͷ�Ǵ��ڵ�
	SNode* pHead = new SNode();
	cout << "������ͷ�����Ϣ:" << endl;
	cin >> pHead->nID;
	createList(3,pHead);
	//����һ���ڵ�
	SNode* pInertNode = new SNode();
	pInertNode->nID = 1005;
	insertNode(pHead, pInertNode);
	traversingList(pHead);
	SNode* pFindNode = findNode(5, pHead);
	cout << "�ҵ��Ľڵ���Ϣ��" << endl;
	if (pFindNode)
	{
	cout << pFindNode->nID << endl;
	}
	else
	{
	cout << "λ�ò�����" << endl;
	}
	
	system("pause");
	return 0;
}

void createList(int nSize, SNode* pHead)
{
	//�������һ���ڵ�ĵ�ַ
	SNode* pLastNode = pHead;
	for (int i = 0; i < nSize; i++)
	{
		SNode* pNewNode = new SNode();
		/*cout << "�������½ڵ���Ϣ��" << endl;
		cin >> pNewNode->nID;*/
		pNewNode->nID = 1002 + i;
		//Ҫ�Ѵ����ĳ����Ľڵ��ͷ�����������:�Ѵ��������Ľڵ�ĵ�ַ�洢��,
		//���һ���ڵ����һ���ڵ�ָ��洢�½ڵ��ַ��
		pLastNode->pNextNode = pNewNode;
		//�������һ���ڵ��ָ��:ÿ�δ�������֮������������֮���½ڵ㶼�����һ���ڵ㡣
		pLastNode = pNewNode;
	}	
}
//����
void traversingList(SNode* pHead)
{
	//�м�ָ�룬һ��ʼָ��ͷ���
	SNode* pCurNode = pHead;
	cout << "������Ϣ��" << endl;
	while (pCurNode)
	{
		cout << pCurNode->nID << endl;
		//����ָ��
		pCurNode = pCurNode->pNextNode;
	}
}

SNode* findNode(int nIndex, SNode* pHead)
{
	SNode* pCurNode = pHead;
	//���λ�ñ�������ʼ��Ϊ0��ͷ���λ����0.
	int nCount = 0;
	//��Ҫ������
	while (pCurNode)
	{
		if (nCount == nIndex)
		{
			return  pCurNode;
		}
		pCurNode = pCurNode->pNextNode;
		nCount++;
	}
	return nullptr;
}

void insertNode(SNode*& pHead, SNode* pInsertNode, int nIndex /*=0*/ )
{
	if (0 == nIndex)
	{
		//�����λ����ͷ��λ�ã���ô����Ľڵ����½ڵ㡣
		//�Ȳ����ٱ�ͷ���
		//����Ľڵ����һ���ڵ�ָ��洢ԭͷ���
		pInsertNode->pNextNode = pHead;
		//����Ľڵ����µ�ͷ��㡣
		pHead = pInsertNode;
		return;
	}
	//��Ҫ�ҵ������λ�õ�ǰһ���ڵ㡣
	//���� 
	SNode* pCurNode = pHead;
	//�������Ľڵ�������
	int nCount = 0;
	while (pCurNode)
	{
		//��Ҫ�ҵ�Ҫ�����λ�õ�ǰһ���ڵ� ��Ҫ��nIndex-1���Ƚ�
		if (nIndex-1 == nCount)
		{
			//pCurNode����Ҫ�����λ�õ�ǰһ���ڵ㡣
			//������ ����Ľڵ���ҵ��Ľڵ����һ���ڵ�����������
			pInsertNode->pNextNode = pCurNode->pNextNode;
			//�ϣ��ҵ�������ڵ������Ľڵ�����
			pCurNode->pNextNode = pInsertNode;
		}
		pCurNode = pCurNode->pNextNode;
		nCount++;
	}

	if (nCount < nIndex)
	{
		cout << "����λ�ò���" << endl;
	}
}

