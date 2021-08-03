#pragma once
#include "enemyState.h"
class enemyIdleState :
	public enemyState
{
private:
	int count;
	int maxCount;
public:
	virtual enemyState* inputHandle(enemy* enemy);
	virtual void enter(enemy* enemy);
	virtual void update(enemy* enemy);
	virtual void exit(enemy* enemy);
};

