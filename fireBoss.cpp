#include "stdafx.h"
#include "fireBoss.h"

HRESULT fireBoss::init(POINT position)
{
	_tagEnemy.type = BOSS_FIREBOSS;
	_tagEnemy.state = new enemyIdleState;
	_tagEnemy.state->enter(this);
	_tagEnemy.damage = 10;
	_tagEnemy.frameX = 0;
	_tagEnemy.frameY = 0;
	_tagEnemy.isSummon = false;

	_tagEnemy.hp = 1000;
	_tagEnemy.radius = 30;
	_tagEnemy.speed = 2.5;
	_tagEnemy.x = position.x;
	_tagEnemy.y = position.y;
	_tagEnemy.z = 0;
	_tagEnemy.isRight = true;
	_tagEnemy.rc = RectMake(_tagEnemy.x, _tagEnemy.y, 48, 48);
	return S_OK;
}

void fireBoss::release()
{
}

void fireBoss::update()
{
}

void fireBoss::render()
{
}
