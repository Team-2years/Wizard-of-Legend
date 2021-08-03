#pragma once
#include "enemyState.h"
class enemyHurtState :
	public enemyState
{
private:
	int count;
public:
	virtual enemyState* inputHandle(enemy* enemy);
	virtual void enter(enemy* enemy);
	virtual void update(enemy* enemy);
	virtual void exit(enemy* enemy);
};

