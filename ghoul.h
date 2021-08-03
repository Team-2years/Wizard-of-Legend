#pragma once
#include "enemy.h"
class ghoul :
	public enemy
{
public:
	virtual HRESULT init(POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
};

