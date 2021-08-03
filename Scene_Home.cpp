#include "stdafx.h"
#include "Scene_Home.h"

HRESULT Scene_Home::init()
{
	_tileClass = new TileClass;
	_tileClass->init("Tile_Home.map");
	CAMERAMANAGER->setBackScreenSize(3840, 2160);
	_player = new player;
	_player->init();
	_enemyManager = new enemyManager;
	_enemyManager->init();
	_enemyManager->linkPlayer(_player);

	
	_enemyManager->setIceBoss(PointMake(WINSIZEX - 200, WINSIZEY - 300));
	//_enemyManager->setOrb(PointMake(WINSIZEX - 200, WINSIZEY - 300));
	_tileClass->linkPlayer(_player);
	return S_OK;
}

void Scene_Home::release()
{
}

void Scene_Home::update()
{
	_player->update();
	_tileClass->update();
	_enemyManager->update();
	CAMERAMANAGER->updateScreen(_player->getPlayerData()->x, _player->getPlayerData()->y);
}

void Scene_Home::render()
{
	_tileClass->render();
	_player->render();
	_enemyManager->render();
}
