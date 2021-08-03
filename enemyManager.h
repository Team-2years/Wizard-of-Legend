#pragma once
#include "gameNode.h"
#include "ghoul.h"
#include "ghoulLarge.h"
#include "EarthZoner.h"
#include "flameZoner.h"
#include "blobRoller.h"
#include "mimic.h"
#include "golem.h"
#include "knight.h"
#include "blueKnight.h"
#include "redKnight.h"
#include "greenKnight.h"
#include "blueSummoner.h"
#include "redSummoner.h"
#include "greenSummoner.h"
#include "summoner.h"
#include "iceBoss.h"
#include "orb.h"
class player;

class enemyManager :
	public gameNode
{
private:
	vector<enemy*> _vEnemy;
	vector<enemy*>::iterator _viEnemy;
	player* _player;
	RECT temp;
public:
	enemyManager();
	~enemyManager();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setGhoul(POINT position);
	void setGhoulLarge(POINT position);
	void setEarthZoner(POINT position);
	void setFlameZoner(POINT position);
	void setBlobRoller(POINT position);
	void setMimic(POINT position);
	void setGolem(POINT position);
	void setKnight(POINT position);
	void setBlueKnight(POINT position);
	void setRedKnight(POINT position);
	void setGreenKnight(POINT position);
	void setSummoner(POINT position);
	void setBlueSummoner(POINT position);
	void setRedSummoner(POINT position);
	void setGreenSummoner(POINT position);
	void setOrb(POINT position);
	void setIceBoss(POINT position);
	void linkPlayer(player* player) { _player = player; };

	vector<enemy*>* getvEnemy() { return &_vEnemy; }
};

