// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

#define KEY_DOWN(vk_code) (GetAsyncKeyState(vk_code)&0x8000?1:0)

enum
{
	E_MENU_START,
	E_MENU_SETTING,
	E_MENU_EXIT
};
#define SYN_THE_SIZE(VarType, VarName, FuncName) \
public:\
	void set##FuncName(VarType InVarName)\
{\
	VarName = InVarName; \
	}\
	VarType get##FuncName()\
{\
	return VarName; \
	}\
protected:\
	VarType VarName;

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�