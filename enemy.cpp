#include "stdafx.h"
#include "enemy.h"

HRESULT enemy::init()
{
	return S_OK;
}

HRESULT enemy::init(POINT position)
{
	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
}

void enemy::render()
{
}

void enemy::move()
{
}

void enemy::draw()
{
}

bool enemy::patternCount()
{
	_tagEnemy.rndCount++;
	if (_tagEnemy.rndCount % _tagEnemy.rndFireCount == 0)
	{
		_tagEnemy.rndCount = 0;
		return true;
	}
	return false;
}

void enemy::inputHandle()
{
	enemyState* tmpstate = _tagEnemy.state->inputHandle(this);
	if (tmpstate != nullptr)
	{
		SAFE_DELETE(_tagEnemy.state);
		_tagEnemy.state = tmpstate;
		_tagEnemy.state->enter(this);
	}
}

void enemy::changeState(enemyState * state)
{
	SAFE_DELETE(_tagEnemy.state);
	_tagEnemy.state = state;
	_tagEnemy.state->enter(this);
}



