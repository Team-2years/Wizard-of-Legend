#pragma once
#include "gameNode.h"

class enemy;

class enemyState :
	public gameNode
{
public:
	virtual enemyState* inputHandle(enemy* enemy) = 0;
	virtual void enter(enemy* enemy) = 0;
	virtual void update(enemy* enemy) = 0;
	virtual void exit(enemy* enemy) = 0;
};

