#include "stdafx.h"
#include "gameNode.h"
#include "UIManager.h"
#include "ItemBasic.h"



#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;



HRESULT UIManager::init(int maxHp, int currentHp, int maxMp, int currentMp, int Jewel, int gold)
{


	backGroundPicture = IMAGEMANAGER->findDImage("Icon");
	
	//===================플레이어 정보===============================



	HP_Progress = new progressBar;
	HP_Progress->init("PlayerHp", "HP", currentHp, maxHp, true);

	MP_Progress = new progressBar;
	MP_Progress->init("PlayerMp", "MP",currentMp,maxMp, false);

	//testint = 0;

	//======================키 관련 정보===============================
	for (int i = 0; i < 8; i++)
	{
		switch (i)
		{
		case 6:   _key[i].rc = RectMake(60 + 30 + i * 50, WINSIZEY - 80, 40, 40);
			_key[i].key = KEY_SKILL;
			break; 
		case 7:  _key[i].rc = RectMake(60 +60 + 30 + i * 50, WINSIZEY - 80, 40, 40);
			_key[i].key = KEY_INVEN;
			break;
		default: _key[i].rc = RectMake(30 + i * 50, WINSIZEY - 80, 40, 40);
			_key[i].key = KEY_MAP;
			break;
		}


		_key[i].image = IMAGEMANAGER->findDImage("IconBackGround");
		_key[i].opacity = 1.0f;

		/*
		IMAGEMANAGER->addDImage("VK_LBUTTON", L"img/Key/M0.png",16,16);
	IMAGEMANAGER->addDImage("VK_RBUTTON", L"img/Key/M1.png",16,16);
	IMAGEMANAGER->addDImage("VK_Q", L"img/Key/Q.png",16,16);
	IMAGEMANAGER->addDImage("VK_E", L"img/Key/E.png",16,16);
	IMAGEMANAGER->addDImage("VK_R", L"img/Key/R.png",16,16);
	IMAGEMANAGER->addDImage("VK_SPACE", L"img/Key/Space.png",16,16);
	IMAGEMANAGER->addDImage("VK_TAB", L"img/Key/Tab.png", 16, 16);
	IMAGEMANAGER->addDImage("VK_M", L"img/Key/M.png", 16, 16);
		*/

		switch (i)
		{
		case 0: _key[i].Icon = IMAGEMANAGER->findDImage("VK_LBUTTON");
				_key[i].KeyInt = VK_LBUTTON;
			break;
		case 1: _key[i].Icon = IMAGEMANAGER->findDImage("VK_SPACE");
			_key[i].KeyInt = VK_SPACE;
			break;
		case 2: _key[i].Icon = IMAGEMANAGER->findDImage("VK_RBUTTON");
			_key[i].KeyInt = VK_RBUTTON;
			break;
		case 3: _key[i].Icon = IMAGEMANAGER->findDImage("VK_Q");
			_key[i].KeyInt = 'Q';
			break;
		case 4: _key[i].Icon = IMAGEMANAGER->findDImage("VK_E");
			_key[i].KeyInt = 'E';
			break;
		case 5: _key[i].Icon = IMAGEMANAGER->findDImage("VK_R");
			_key[i].KeyInt = 'R';
			break;
		case 6: _key[i].Icon = IMAGEMANAGER->findDImage("VK_M");
			_key[i].KeyInt = 'M';
			break;
		case 7: _key[i].Icon = IMAGEMANAGER->findDImage("VK_TAB");
			_key[i].KeyInt = VK_TAB;
			break;
		}
	}


	return S_OK;
}

void UIManager::release()
{
}

void UIManager::update()
{

	HP_Progress->update();
	MP_Progress->update();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _key[0].opacity = 0.4f;
	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON)) _key[0].opacity = 1.0f;
	
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) _key[1].opacity = 0.4f;
	if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) _key[1].opacity = 1.0f;

	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON)) _key[2].opacity = 0.4f;
	if (KEYMANAGER->isOnceKeyUp(VK_RBUTTON)) _key[2].opacity = 1.0f;

	if (KEYMANAGER->isOnceKeyDown('Q')) _key[3].opacity = 0.4f;
	if (KEYMANAGER->isOnceKeyUp('Q')) _key[3].opacity = 1.0f;

	if (KEYMANAGER->isOnceKeyDown('E')) _key[4].opacity = 0.4f;
	if (KEYMANAGER->isOnceKeyUp('E')) _key[4].opacity = 1.0f;

	if (KEYMANAGER->isOnceKeyDown('R')) _key[5].opacity = 0.4f;
	if (KEYMANAGER->isOnceKeyUp('R')) _key[5].opacity = 1.0f;
 
	if (KEYMANAGER->isOnceKeyDown('M')) _key[6].opacity = 0.4f;
	if (KEYMANAGER->isOnceKeyUp('M')) _key[6].opacity = 1.0f;

	if (KEYMANAGER->isOnceKeyDown(VK_TAB)) _key[7].opacity = 0.4f;
	if (KEYMANAGER->isOnceKeyUp(VK_TAB)) _key[7].opacity = 1.0f;



	//디버깅용. 아이템 잘 들어가나 확인.

}

void UIManager::render()
{
	for (int i = 0; i < 8; i++)
	{
		_key[i].image->render(_key[i].rc.left, _key[i].rc.top,_key[i].opacity);
		_key[i].Icon->sclaeRender_Center((_key[i].rc.left + _key[i].rc.right) / 2, _key[i].rc.top - 20, 1.5f,1.5f,_key[i].opacity);
	}

	backGroundPicture->scaleRender(10, 0, 1.5f / CAMERAMANAGER->getZoom(), 1.5f / CAMERAMANAGER->getZoom());
	HP_Progress->render(60, 5,4 / CAMERAMANAGER->getZoom(),5 / CAMERAMANAGER->getZoom(),0.8f / CAMERAMANAGER->getZoom(),1.0f / CAMERAMANAGER->getZoom());

	MP_Progress->render(60, HP_Progress->getbackGroundBar()->getY() + HP_Progress->getbackGroundBar()->getHeight() / CAMERAMANAGER->getZoom() + 5,6 / CAMERAMANAGER->getZoom(),1 / CAMERAMANAGER->getZoom(),0.8f / CAMERAMANAGER->getZoom(), 1.0f / CAMERAMANAGER->getZoom());

	
}
