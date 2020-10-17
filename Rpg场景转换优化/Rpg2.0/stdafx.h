// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
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

// TODO:  在此处引用程序需要的其他头文件