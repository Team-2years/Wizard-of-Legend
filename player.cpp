#include "stdafx.h"
#include "player.h"


#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

HRESULT player::init()
{
	_playerData.atkHand = false;
	_playerData.dashCount = 0;
	_playerData.errorX = 0;
	_playerData.errorY = 0;
	_playerData.state = new idleState;
	_playerData.state->enter(this);
	_playerData.stateEnum = STATE_DOWN_IDLE;
	_playerData.frameX = 0;
	_playerData.frameY = 0;
	_playerData.x = WINSIZEX / 2;
	_playerData.y = WINSIZEY / 2;
	_playerData.z = 0.f;
	_playerData.gravity = 0.7f;
	_playerData.jumpPower = 0.f;
	_playerData.speed = 0;
	_playerData.moveCommandInput = 0;
	_playerData.hp = 100;
	_playerData.time = 0;
	_playerData.rc = RectMakeCenter(_playerData.x, _playerData.y + 18, 20, 30);
	_playerData.hitCount = 0;
	//======================형준======================

	_playerData.maxHp = 500;
	_playerData.currentHp = _playerData.maxHp;

	_playerData.maxMp = 100;
	_playerData.currentMp = 0;

	_playerData.PlayerBasicDamage = BASIC_DAMAGE_PER;
	_playerData.PlayerEarthDamage = BASIC_DAMAGE_PER;
	_playerData.PlayerThunderDamage = BASIC_DAMAGE_PER;
	_playerData.PlayerWaterDamage = BASIC_DAMAGE_PER;
	_playerData.PlayerFireDamage = BASIC_DAMAGE_PER;
	_playerData.PlayerWindDamage = BASIC_DAMAGE_PER;

	DataBase = new DateBaseManager;
	DataBase->init();

//	_saveData = new SaveDataManager;
//	_saveData->init();
//	_saveData->load();


	_UI = new UIManager;
	_UI->init(_playerData.maxHp, _playerData.currentHp, _playerData.maxMp, _playerData.currentMp, _playerData.jewel, _playerData.gold);
	_Inven = new Inventory;
	_Inven->init();
	_Inven->setAddressLink(this);
	SKILLMANAGER->init();

    return S_OK;
}

void player::release()
{
}

void player::update()
{
	inputHandle();
	_playerData.dashCount--;
	_playerData.state->update(this);
	_playerData.rc = RectMakeCenter(_playerData.x, _playerData.y + 18, 20, 30);
	//======================형준==============================
	_playerData.hitCount++;
	//MP 줄어드는 함수
	if (_playerData.currentMp > 0)
	{
		mpCount++;

		if (mpCount > 5)
		{
			setPlayerMp(_playerData.currentMp - 1);
			mpCount = 0;
		}
	}

	//디버깅용. HP, MP 조절해서 변화 잘 되는지 확인
	if (KEYMANAGER->isOnceKeyDown('1')) setPlayerHp(_playerData.currentHp - 25);	
	if (KEYMANAGER->isOnceKeyDown('2')) setPlayerMp(_playerData.currentMp + 20);
	
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		SKILLMANAGER->fire(10, _ptMouse.x, _ptMouse.y, 0, true);
	}
	//디버깅용. 보석관련
	//if (KEYMANAGER->isOnceKeyDown('3')) _playerData.jewel++;	
	//if (KEYMANAGER->isOnceKeyDown('4'))
	//{
	//	_saveData->setJewel(_playerData.jewel);
	//	_saveData->save();
	//}
	//if (KEYMANAGER->isOnceKeyDown('5'))
	//{
	//	_saveData->load();
	//	_playerData.jewel = _saveData->getData().Jewel;
	//}
	//if (KEYMANAGER->isOnceKeyDown('6'))
	//{
	//	_Inven->getRelics(DataBase->findItem(10001));
	//}
	//if (KEYMANAGER->isOnceKeyDown('7'))
	//{
	//	_Inven->getRelics(DataBase->findItem(10002));
	//}

	CAMERAMANAGER->updateScreen(_playerData.x, _playerData.y);
	_UI->update();
	_Inven->update();
	SKILLMANAGER->update();
}

void player::render()
{
	
	DTDMANAGER->Rectangle(_playerData.rc);
	if(_playerData.image->getMaxFrameX() == 0 && _playerData.image->getMaxFrameY() == 0)
		RENDERMANAGER->push_BackRenderInfo(_playerData.rc.bottom / 16, _playerData.image, _playerData.x + _playerData.errorX, _playerData.y + _playerData.errorY + _playerData.z);

   else RENDERMANAGER->push_BackFrameRenderInfo(_playerData.rc.bottom / 16, _playerData.image, _playerData.x + _playerData.errorX, _playerData.y + _playerData.errorY + _playerData.z, _playerData.frameX, _playerData.frameY);

	//============형준===================



	//cout << _playerData.jewel << endl;
	SKILLMANAGER->render();

}

void player::changeState(state* state)
{
	SAFE_DELETE(_playerData.state);
	_playerData.state = state;
	_playerData.state->enter(this);
}

void player::inputHandle()
{
	state* tmpstate = _playerData.state->inputHandle(this);
	if (tmpstate != nullptr) 
	{
		SAFE_DELETE(_playerData.state);
		_playerData.state = tmpstate;
		_playerData.state->enter(this);
	}
}
