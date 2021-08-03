﻿#pragma once

enum CURRENTHOMEMENU
{
	MENU_NON,
	MENU_LELICS,
	MENU_ARCANA,
	MENU_CLOTH
};

// D2D 사용을 위한 lib
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "WindowsCodecs.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "Comdlg32.lib")

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN   // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
#include <cassert>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


//d2d 백터 포인트 및 형식
#include <vector>
#include <map>


enum class Pivot : int
{
	LeftTop, Center, Bottom
};

namespace Direction
{
	enum Enum : int
	{
		Left = 1,
		Top = 2,
		Right = 4,
		Bottom = 8,
		LeftTop = Left | Top,
		LeftBottom = Left | Bottom,
		RightTop = Right | Top,
		RightBottom = Right | Bottom,
		End = 0
	};

};

// D2D Header Files
#include <d2d1.h>
#include <d2d1helper.h>
#include <wincodec.h>
#include <dwrite.h>

//d2d추가 유틸 =====================

#include "Vector2.h"
#include "Math.h"
#include "FloatRect.h"
#include "Figure.h"

#include <iostream>
#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "utils.h"
#include "txtData.h"
#include "timeManager.h"
#include "effectManager.h"
#include "sceneManager.h"
#include "soundManager.h"
#include "iniDataManager.h"
#include "cameraManager.h"
#include "imageManager.h"
#include "keyAniManager.h"
#include "dtdManager.h"
#include "printManager.h"
#include "streamManager.h"
#include "renderManager.h"
#include "ParticleManeager.h"
#include "skillManager.h"

#include "SaveDataManager.h"

using namespace std;
using namespace UJN_UTIL;
using namespace D2D1;
using namespace Figure;

extern int WinsizeX;
extern int WinsizeY;

//==================================
// ## 매크로 처리 ## 21.04.23 ##
//==================================

#define WINNAME (LPTSTR)(TEXT("Wizards of Legend"))

#define WINSTARTX 30	//윈도우 창 시작좌표 (left)
#define WINSTARTY 10	//윈도우 창 시작좌표 (top)
#define ORIGINWINSIZEX 1444	//윈도우 가로크기
#define ORIGINWINSIZEY 860	//윈도우 세로크기
#define WINSIZEX WinsizeX	//윈도우 가로크기
#define WINSIZEY WinsizeY	//윈도우 세로크기
#define MAPSIZEX 6753
#define MAPSIZEY 1000

#define WINSTYLE WS_CAPTION | WS_SYSMENU

#define RND				randomFunction::getSingleton()
#define KEYMANAGER		keyManager::getSingleton()
#define TIMEMANAGER		timeManager::getSingleton()
#define EFFECTMANAGER	effectManager::getSingleton()
#define SCENEMANAGER	sceneManager::getSingleton()
#define SOUNDMANAGER	soundManager::getSingleton()
#define KEYANIMANAGER	keyAniManager::getSingleton()
#define TXTDATA			txtData::getSingleton()
#define INIDATA			iniDataManager::getSingleton()
#define CAMERAMANAGER	cameraManager::getSingleton()
#define IMAGEMANAGER	imageManager::getSingleton()
#define DTDMANAGER dtdManager::getSingleton()
#define PRINTMANAGER printManager::getSingleton()
#define STREAMMANAGER streamManager::getSingleton()
#define RENDERMANAGER renderManager::getSingleton()
#define SAVEDATAMANAGER SaveDataManager::getSingleton()
#define PARTICLEMANAGER ParticleManeager::getSingleton()
#define SKILLMANAGER skillManager::getSingleton()

#define SAFE_DELETE(p) {if(p) {delete(p); (p) = nullptr;}}
#define SAFE_RELEASE(p) {if(p) {(p)->release(); (p) = NULL;}}
#define SAFE_RELEASE2(p) { if(p) { (p)->Release(); (p) = NULL; } }

#define Synthesize(ValueType,ValueName,FuncName) \
protected: ValueType ValueName;\
public: inline ValueType Get##FuncName(void) const{return ValueName;}\
public: inline void Set##FuncName(ValueType value){ValueName = value;}

//==================================
// ## extern ## 21.04.28 ##
//==================================

extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;

