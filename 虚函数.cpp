//�麯��.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <windows.h>
#include <iostream>

using namespace std;

//����
class CA
{
public:
	CA();
	virtual ~CA();
	virtual void print();
private:

};

CA::CA()
{
	cout << "����Ĺ��캯��" << endl;
}

CA::~CA()
{
	cout << "���������������" << endl;
}

void CA::print()
{
	cout << "����A�Ĵ�ӡ����" << endl;
}

//������̳���A
class CB : public CA
{
public:
	CB();
	~CB();
	//��д���׵�print�����������printҲ���麯����
	virtual void print();//�����virtual���Բ�д����Ϊ�������麯������������print��дҲ�����麯����
private:

};

CB::CB()
{
	cout << "������Ĺ��캯��" << endl;
}

CB::~CB()
{
	cout << "���������������" << endl;
}

void CB::print()
{
	cout << "������B�Ĵ�ӡ����" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//CA* pA = new CA();
	//pA->print();
	//CB* pB = new CB();
	//pB->print();

	////����ָ���ǿ��Դ洢���Ӷ�����ڴ档
	//CA* pA1 = (CA*)pB;
	//pA1->print();
	//ָ����ʲô�����ڵ��ú�����ʱ�򣬾͵�����Ӧ���Ͷ�Ӧ�ĺ�����
	//Ӧ�����ڴ���˭�ľ͵���˭�ĺ����� ����ָ��������A����B���������B��print
	//����취���Ѹ���ĺ���������麯���� virtual +������������---virtual void print();��


	//��newһ������������ʱ�򣬻���ȥ���û���Ĺ��캯���ٵ���������Ĺ��캯����
	CB* pB = new CB();
	//���ͷ��ڴ��ʱ�򣬻��ȵ����������������������ȥ���û��������������
	//delete pB;

	CA* pA = (CA*)pB;
	//����ǻ���ָ��洢����������ڴ棬��ô���ͷ��ڴ��ʱ��ֻ����ø����������������ζ�������������û�е��ã��ڴ��ͷŲ���ȫ���ڴ�й©��
	//����취���Ѹ����������������Ϊ������������

	//ΪʲôҪ��������������?
	/*������ǻ���ָ��洢����������ڴ棬��ô���ͷ��ڴ��ʱ��
	ֻ����ø����������������ζ�������������û�е��ã��ڴ��ͷŲ���ȫ���ڴ�й© */
	delete pA;
	system("pause");
	return 0;
}

