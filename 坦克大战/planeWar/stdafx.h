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
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#define KEY_DOWN(vk_code) (GetAsyncKeyState(vk_code)&0x8000?1:0)
// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�

enum
{
	E_GAME_MENU,
	E_GAME_SEL,
	E_GAME,
};
enum DIR
{
	E_DIR_UP,
	E_DIR_LEFT,
	E_DIR_DOWN,
	E_DIR_RIGHT
};