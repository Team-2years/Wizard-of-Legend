#pragma once
#include "stdafx.h"
#include "gameNode.h"
#include "TileClass.h"
#include "player.h"
#include "PlayerHomeFunction.h"
#include "enemyManager.h"
#include "enemy.h"

class dg :
	public gameNode
{
	player* _player;
	TileClass* _tile;
	bool _debug;

	Home_Lelics* HomeLelics;
	Home_Arcana* HomeArcana;
	Home_Closet* HomeCloset;
	enemyManager* _enemyManager;
	DateBaseManager* _Data;

	vector <tagfireDash>* _fireDash;
	vector <tagfireDash>::iterator _ifireDash;
	vector<tagfireCross>* _fireCross;
	vector <tagfireCross>::iterator _ifireCross;
	vector<tagskill>* _skill;
	vector <tagskill>::iterator _iskill;
	vector<tagiceSpear>* _iceSpear;
	vector <tagiceSpear>::iterator _iiceSpear;
	vector<tagwaterZone>* _waterZone;
	vector <tagwaterZone>::iterator _iwaterZone;
	vector<tagbubble>* _bubble;
	vector <tagbubble>::iterator _ibubble;
	vector<tagLightningWave>* _LightningWave;
	vector <tagLightningWave>::iterator _iLightningWave;
	vector<tagLightningJump>* _LightningJump;
	vector <tagLightningJump>::iterator _iLightningJump;
	vector<tagLightBeam>* _LightBeam;
	vector <tagLightBeam>::iterator _iLightBeam;
	vector<tagiceWall>* _iceWall;
	vector <tagiceWall>::iterator _iiceWall;
	vector<tagfrostWall>* _frostWall;
	vector <tagfrostWall>::iterator _ifrostWall;
	vector<enemy*>* _vEnemy;
	vector <enemy*>::iterator _viEnemy;

	RECT _temp;

	CURRENTHOMEMENU Menu;
	RECT _mouseRECT;
public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void skillEnemyCollision();
	void skillPlayerCollision();
};

