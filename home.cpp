#include "stdafx.h"
#include "home.h"
#include "enemyHurtState.h"
#include "hurtState.h"

#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;


HRESULT home::init()
{

	_tile = new TileClass;

	//´øÀü ·£´ýÀ¸·Î ³ª¿À°Ô ÇÒ ¶§
	/*int temp = RND->getInt(2);
	switch (temp)
	{
	case 0:
		_tile->init("tile_IceRoad1.map");
		break;
	case 1:
		_tile->init("tile_IceRoad2.map");
		break;
	default:
		break;
	}*/
	_tile->init("tile_Home.map");
	// ´øÀü ¸Ê¿¡¼­´Â ¾Æ·¡²¨ ÁÖ¼® Ç®¸é ´ð´Ï´Ù.
	//_tile->setRandomDungeon("tile_Ice.map");

	//CAMERAMANAGER->setBackScreenSize(3840, 2160);
	_player = new player;
	_player->init();
	_player->getPlayerData()->x = 800;
	_player->getPlayerData()->y = 820;
	HomeLelics = new Home_Lelics;
	HomeLelics->init();
	HomeArcana = new Home_Arcana;
	HomeArcana->init();
	HomeCloset = new Home_Closet;
	HomeCloset->init();


	Menu = MENU_NON;

	_Data = new DateBaseManager;
	_Data->init();

	if (HomeCloset->getCloset(0)->Item == nullptr)
	{
		HomeCloset->getCloth(_Data->findItem(50001));
		_player->getInven()->changeCloth(HomeCloset->getCloset(0)->Item);
		HomeCloset->getCloth(_Data->findItem(50002));

	}
	_enemyManager = new enemyManager;
	_enemyManager->init();
	_enemyManager->linkPlayer(_player);
	//_enemyManager->setIceBoss(PointMake(500, 500));

	_vEnemy = _enemyManager->getvEnemy();
	HomeLelics->setAddressInventory(_player->getInven());
	HomeCloset->setAddressLinkInventory(_player->getInven());
	_mouseRECT = RectMakeCenter(_ptMouse.x, _ptMouse.y, 20, 20);

	_fireDash = SKILLMANAGER->getFireDash();
	_fireCross = SKILLMANAGER->getFireCross();
	_skill = SKILLMANAGER->getSkill();
	_iceSpear = SKILLMANAGER->getIceSpear();
	_waterZone = SKILLMANAGER->getWaterZone();
	_bubble = SKILLMANAGER->getBubble();
	_LightningWave = SKILLMANAGER->getLightningWave();
	_LightningJump = SKILLMANAGER->getLightningJump();
	_LightBeam = SKILLMANAGER->getLightBeam();
	_iceWall = SKILLMANAGER->getIceWall();
	_frostWall = SKILLMANAGER->getFrostWall();
	return S_OK;
}

void home::release()
{
}

void home::update()
{
	_tile->update();
	//_player->update();

	if (KEYMANAGER->isOnceKeyDown('8'))
	{
		if (Menu == MENU_NON) Menu = MENU_LELICS;
		else if (Menu == MENU_LELICS) Menu = MENU_NON;
	}
	if (KEYMANAGER->isOnceKeyDown('9'))
	{
		if (Menu == MENU_NON) Menu = MENU_ARCANA;
		else if (Menu == MENU_ARCANA) Menu = MENU_NON;
	}
	if (KEYMANAGER->isOnceKeyDown('0'))
	{
		if (Menu == MENU_NON) Menu = MENU_CLOTH;
		else if (Menu == MENU_CLOTH) Menu = MENU_NON;
	}

	_mouseRECT = RectMakeCenter(_ptMouse.x, _ptMouse.y, 20, 20);

	if (HomeLelics->getisOpenMimi()) HomeLelics->update();

	switch (Menu)
	{
	case MENU_NON: _player->update();
		_enemyManager->update();
		skillEnemyCollision();
		skillPlayerCollision();
		break;
	case MENU_LELICS:
		/*
		if (HomeLelics->getisOpenMimi()) HomeLelics->setisOpenMimi(false);
		else HomeLelics->setisOpenMimi(true);
		*/
		HomeLelics->update();
		break;
	case MENU_ARCANA:
		HomeArcana->update();
		break;
	case MENU_CLOTH:
		HomeCloset->update();
		break;
	}
}

void home::render()
{
	_tile->render();
	_player->render();
	_enemyManager->render();

	RENDERMANAGER->render();
	//DTDMANAGER->render();
	_player->getUI()->render();
	_player->getInven()->render();

	//_Data->findItem(50001)->getImage()->render(WINSIZEX / 2, WINSIZEY / 2);

	//IMAGEMANAGER->findDImage("¿Ê_»¡°­")->render(WINSIZEX / 2, WINSIZEY / 2);

	//if (HomeLelics->getisOpenMimi()) HomeLelics->render();

	switch (Menu)
	{
	case MENU_NON:
		break;
	case MENU_LELICS: HomeLelics->render();
		break;
	case MENU_ARCANA: HomeArcana->render();
		break;
	case MENU_CLOTH: HomeCloset->render();
		break;
	}
	DTDMANAGER->Rectangle(_mouseRECT);
}

void home::skillEnemyCollision()
{
	if (!_vEnemy->empty())
	{
		for (_viEnemy = _vEnemy->begin(); _viEnemy != _vEnemy->end(); _viEnemy++)
		{
			RECT rc = (*_viEnemy)->getRect();
			if (!_fireDash->empty())
			{
				for (_ifireDash = _fireDash->begin(); _ifireDash != _fireDash->end(); _ifireDash++)
				{
					if (&_ifireDash->playerATK == false) continue;
					if (IntersectRect(&_temp, &rc, &_ifireDash->rc))
					{
						enemyState* st = new enemyHurtState;
						(*_viEnemy)->changeState(st);
					}
				}
			}

			if (!_fireCross->empty())
			{
				for (int i = 0; i < _fireCross->size(); i++)
				{
					for (_ifireCross = _fireCross->begin(); _ifireCross != _fireCross->end(); _ifireCross++)
					{
						if (&_ifireCross->playerATK == false) continue;
						if (IntersectRect(&_temp, &rc, &_ifireCross->rc))
						{
							enemyState* st = new enemyHurtState;
							(*_viEnemy)->changeState(st);
						}
					}
				}
			}

			if (!_skill->empty())
			{
				for (int i = 0; i < _skill->size(); i++)
				{
					for (int i = 0; i < _skill->size(); i++)
					{
						if (&(*_skill)[i].playerATK == false) continue;
						if (IntersectRect(&_temp, &rc, &(*_skill)[i].rc))
						{
							enemyState* st = new enemyHurtState;
							(*_viEnemy)->changeState(st);
						}
					}
				}
			}

			if (!_iceSpear->empty())
			{
				for (int i = 0; i < _iceSpear->size(); i++)
				{
					for (int i = 0; i < _iceSpear->size(); i++)
					{
						if (&(*_iceSpear)[i].playerATK == false) continue;
						if (IntersectRect(&_temp, &rc, &(*_iceSpear)[i].rc))
						{
							enemyState* st = new enemyHurtState;
							(*_viEnemy)->changeState(st);
						}
					}
				}
			}

			if (!_waterZone->empty())
			{
				for (int i = 0; i < _waterZone->size(); i++)
				{
					for (int i = 0; i < _waterZone->size(); i++)
					{
						if (&(*_waterZone)[i].playerATK == false) continue;
						if (IntersectRect(&_temp, &rc, &(*_waterZone)[i].rc))
						{
							enemyState* st = new enemyHurtState;
							(*_viEnemy)->changeState(st);
						}
					}
				}
			}

			if (!_bubble->empty())
			{
				for (int i = 0; i < _bubble->size(); i++)
				{
					for (int i = 0; i < _bubble->size(); i++)
					{
						if (&(*_bubble)[i].playerATK == false) continue;
						if (IntersectRect(&_temp, &rc, &(*_bubble)[i].rc))
						{
							enemyState* st = new enemyHurtState;
							(*_viEnemy)->changeState(st);
						}
					}
				}
			}

			if (!_LightningWave->empty())
			{
				for (int i = 0; i < _LightningWave->size(); i++)
				{
					for (int i = 0; i < _LightningWave->size(); i++)
					{
						if (&(*_LightningWave)[i].playerATK == false) continue;
						if (IntersectRect(&_temp, &rc, &(*_LightningWave)[i].rc))
						{
							enemyState* st = new enemyHurtState;
							(*_viEnemy)->changeState(st);
						}
					}
				}
			}

			if (!_LightningJump->empty())
			{
				for (int i = 0; i < _LightningJump->size(); i++)
				{
					for (int i = 0; i < _LightningJump->size(); i++)
					{
						if (&(*_LightningJump)[i].playerATK == false) continue;
						if (IntersectRect(&_temp, &rc, &(*_LightningJump)[i].rc))
						{
							enemyState* st = new enemyHurtState;
							(*_viEnemy)->changeState(st);
						}
					}
				}
			}

			if (!_LightBeam->empty())
			{
				for (int i = 0; i < _LightBeam->size(); i++)
				{
					for (int i = 0; i < _LightBeam->size(); i++)
					{
						if (&(*_LightBeam)[i].playerATK == false) continue;

						if (IntersectRect(&_temp, &rc, &(*_LightBeam)[i].rc))
						{
							enemyState* st = new enemyHurtState;
							(*_viEnemy)->changeState(st);
						}
					}
				}
			}

			if (!_iceWall->empty())
			{
				for (int i = 0; i < _iceWall->size(); i++)
				{
					for (int i = 0; i < _iceWall->size(); i++)
					{
						if (&(*_iceWall)[i].playerATK == false) continue;

						if (IntersectRect(&_temp, &rc, &(*_iceWall)[i].rc))
						{
							enemyState* st = new enemyHurtState;
							(*_viEnemy)->changeState(st);
						}
					}
				}
			}

			if (!_frostWall->empty())
			{
				for (int i = 0; i < _frostWall->size(); i++)
				{
					if (&(*_frostWall)[i].playerATK == false) continue;

					for (int i = 0; i < _frostWall->size(); i++)
					{
						if (IntersectRect(&_temp, &rc, &(*_frostWall)[i].rc))
						{
							enemyState* st = new enemyHurtState;
							(*_viEnemy)->changeState(st);
						}
					}
				}
			}

		}
	}
}

void home::skillPlayerCollision()
{
	RECT rc = _player->getPlayerData()->rc;

	if (!_fireDash->empty())
	{
		if (IntersectRect(&_temp, &rc, &_ifireDash->rc2) && _player->getPlayerData()->hitCount > 40)
		{
			state* st = new hurtState;
			_player->changeState(st);
			_player->getPlayerData()->hitCount = 0;

		}
	}

	if (!_fireCross->empty())
	{
		for (int i = 0; i < _fireCross->size(); i++)
		{
			if (IntersectRect(&_temp, &rc, &_ifireCross->rc2) && _player->getPlayerData()->hitCount > 40)
			{
				state* st = new hurtState;
				_player->changeState(st);
				_player->getPlayerData()->hitCount = 0;

			}
		}
	}

	if (!_skill->empty())
	{
		for (int i = 0; i < _skill->size(); i++)
		{
			if (IntersectRect(&_temp, &rc, &(*_skill)[i].rc2) && _player->getPlayerData()->hitCount > 40)
			{
				state* st = new hurtState;
				_player->changeState(st);
				_player->getPlayerData()->hitCount = 0;

			}
		}
	}

	if (!_iceSpear->empty())
	{
		for (int i = 0; i < _iceSpear->size(); i++)
		{

			if (IntersectRect(&_temp, &rc, &(*_iceSpear)[i].rc2) && _player->getPlayerData()->hitCount > 40)
			{
				state* st = new hurtState;
				_player->changeState(st);
				_player->getPlayerData()->hitCount = 0;

			}
		}
	}

	if (!_waterZone->empty())
	{
		for (int i = 0; i < _waterZone->size(); i++)
		{

			if (IntersectRect(&_temp, &rc, &(*_waterZone)[i].rc2) && _player->getPlayerData()->hitCount > 40)
			{
				state* st = new hurtState;
				_player->changeState(st);
				_player->getPlayerData()->hitCount = 0;

			}
		}
	}

	if (!_bubble->empty())
	{
		for (int i = 0; i < _bubble->size(); i++)
		{
			if (IntersectRect(&_temp, &rc, &(*_bubble)[i].rc2) && _player->getPlayerData()->hitCount > 40)
			{
				state* st = new hurtState;
				_player->changeState(st);
				_player->getPlayerData()->hitCount = 0;

			}

		}
	}

	if (!_LightningWave->empty())
	{
		for (int i = 0; i < _LightningWave->size(); i++)
		{

			if (IntersectRect(&_temp, &rc, &(*_LightningWave)[i].rc2) && _player->getPlayerData()->hitCount > 40)
			{
				state* st = new hurtState;
				_player->changeState(st);
				_player->getPlayerData()->hitCount = 0;

			}

		}
	}

	if (!_LightningJump->empty())
	{
		for (int i = 0; i < _LightningJump->size(); i++)
		{

			if (IntersectRect(&_temp, &rc, &(*_LightningJump)[i].rc2) && _player->getPlayerData()->hitCount > 40)
			{
				state* st = new hurtState;
				_player->changeState(st);
				_player->getPlayerData()->hitCount = 0;

			}

		}
	}

	if (!_LightBeam->empty())
	{
		for (int i = 0; i < _LightBeam->size(); i++)
		{

			if (IntersectRect(&_temp, &rc, &(*_LightBeam)[i].rc2) && _player->getPlayerData()->hitCount > 40)
			{
				state* st = new hurtState;
				_player->changeState(st);
				_player->getPlayerData()->hitCount = 0;
			}

		}
	}

	if (!_iceWall->empty())
	{
		for (int i = 0; i < _iceWall->size(); i++)
		{

			if (IntersectRect(&_temp, &rc, &(*_iceWall)[i].rc2) && _player->getPlayerData()->hitCount > 40)
			{
				state* st = new hurtState;
				_player->changeState(st);
				_player->getPlayerData()->hitCount = 0;
			}
		}
	}

	if (!_frostWall->empty())
	{
		for (int i = 0; i < _frostWall->size(); i++)
		{

			if (IntersectRect(&_temp, &rc, &(*_frostWall)[i].rc2) && _player->getPlayerData()->hitCount > 40)
			{
				state* st = new hurtState;
				_player->changeState(st);
				_player->getPlayerData()->hitCount = 0;
			}
		}
	}
}
