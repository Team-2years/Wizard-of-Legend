#pragma once
#include "enemy.h"
class mimic :
	public enemy
{
	virtual HRESULT init(POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
};

