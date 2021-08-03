#pragma once
#include "enemyState.h"
class enemyAttackState :
	public enemyState
{
private:
	int count;
	int maxCount;
	int endCount;
	RECT temp;
	float angle;
	int ptn;
	float targetX;
	float targetY;
public:
	virtual enemyState* inputHandle(enemy* enemy);
	virtual void enter(enemy* enemy);
	virtual void update(enemy* enemy);
	virtual void exit(enemy* enemy);
};