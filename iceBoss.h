#pragma once
#include "enemy.h"
class iceBoss :
	public enemy
{
	virtual HRESULT init(POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
};

