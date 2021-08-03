#pragma once
#include "enemy.h"
class knight :
	public enemy
{
	virtual HRESULT init(POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
};

