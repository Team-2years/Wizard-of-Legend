#pragma once
#include "gameNode.h"
#include "TileClass.h"
#include "player.h"
#include "enemyManager.h"

class Scene_Home : public gameNode
{
private:
	TileClass * _tileClass;
	enemyManager* _enemyManager;
	player* _player;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

