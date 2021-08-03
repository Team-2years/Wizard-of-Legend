#pragma once
#include "enemy.h"
class summoner :
	public enemy
{
	virtual HRESULT init(POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
};

