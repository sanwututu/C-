//
#include "stdafx.h"
#include <windows.h>
#include <iostream>
using namespace std;

//每个节点的类型。
struct SNode
{
	SNode()
	{
		nID = 0;
		pNextNode = nullptr;
	}
	//要存储的数据
	int nID;
	//指向下一个节点的指针
	SNode* pNextNode;
};

//创建链表:参数1:你要创建的链表的长度，
void createList(int nSize,SNode* pHead);
//访问链表每个节点，遍历。参数：头指针
void traversingList(SNode* pHead);
//查找节点:位置，头结点
SNode* findNode(int nIndex, SNode* pHead);
//插入节点:位置，头结点,插入的节点。
void insertNode(SNode*& pHead, SNode* pInsertNode, int nIndex = 0);

//删除
//反转
int _tmain(int argc, _TCHAR* argv[])
{
	//首先必须保证链表头是存在的
	SNode* pHead = new SNode();
	cout << "请输入头结点信息:" << endl;
	cin >> pHead->nID;
	createList(3,pHead);
	//插入一个节点
	SNode* pInertNode = new SNode();
	pInertNode->nID = 1005;
	insertNode(pHead, pInertNode);
	traversingList(pHead);
	SNode* pFindNode = findNode(5, pHead);
	cout << "找到的节点信息：" << endl;
	if (pFindNode)
	{
	cout << pFindNode->nID << endl;
	}
	else
	{
	cout << "位置不存在" << endl;
	}
	
	system("pause");
	return 0;
}

void createList(int nSize, SNode* pHead)
{
	//保存最后一个节点的地址
	SNode* pLastNode = pHead;
	for (int i = 0; i < nSize; i++)
	{
		SNode* pNewNode = new SNode();
		/*cout << "请输入新节点信息：" << endl;
		cin >> pNewNode->nID;*/
		pNewNode->nID = 1002 + i;
		//要把创建的出来的节点跟头结点链接起来:把创建出来的节点的地址存储到,
		//最后一个节点的下一个节点指针存储新节点地址。
		pLastNode->pNextNode = pNewNode;
		//更改最后一个节点的指向:每次创建出来之后并且连接起来之后，新节点都是最后一个节点。
		pLastNode = pNewNode;
	}	
}
//遍历
void traversingList(SNode* pHead)
{
	//中间指针，一开始指向头结点
	SNode* pCurNode = pHead;
	cout << "链表信息：" << endl;
	while (pCurNode)
	{
		cout << pCurNode->nID << endl;
		//更改指向
		pCurNode = pCurNode->pNextNode;
	}
}

SNode* findNode(int nIndex, SNode* pHead)
{
	SNode* pCurNode = pHead;
	//添加位置变量，初始化为0，头结点位置是0.
	int nCount = 0;
	//需要遍历。
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
		//插入的位置是头的位置，那么插入的节点变成新节点。
		//先插入再变头结点
		//插入的节点的下一个节点指针存储原头结点
		pInsertNode->pNextNode = pHead;
		//插入的节点变成新的头结点。
		pHead = pInsertNode;
		return;
	}
	//需要找到插入的位置的前一个节点。
	//遍历 
	SNode* pCurNode = pHead;
	//遍历到的节点索引。
	int nCount = 0;
	while (pCurNode)
	{
		//需要找到要插入的位置的前一个节点 需要用nIndex-1来比较
		if (nIndex-1 == nCount)
		{
			//pCurNode就是要插入的位置的前一个节点。
			//先连， 插入的节点跟找到的节点的下一个节点连接起来。
			pInsertNode->pNextNode = pCurNode->pNextNode;
			//断，找到的这个节点跟插入的节点连接
			pCurNode->pNextNode = pInsertNode;
		}
		pCurNode = pCurNode->pNextNode;
		nCount++;
	}

	if (nCount < nIndex)
	{
		cout << "插入位置不对" << endl;
	}
}

