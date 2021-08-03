#include "stdafx.h"
#include "orb.h"

HRESULT orb::init(POINT position)
{
	_tagEnemy.type = ENEMY_ORB;
	_tagEnemy.state = new enemyIdleState;
	_tagEnemy.state->enter(this);
	_tagEnemy.damage = 10;
	_tagEnemy.frameX = 0;
	_tagEnemy.frameY = 0;
	_tagEnemy.hp = 70;
	_tagEnemy.radius = 30;
	_tagEnemy.speed = 5;
	_tagEnemy.x = position.x;
	_tagEnemy.y = position.y;
	_tagEnemy.z = 0;
	_tagEnemy.summonNum = 0;
	_tagEnemy.isRight = true;
	_tagEnemy.isSummon = false;
	_tagEnemy.angle = 0;
	_tagEnemy.rc = RectMake(_tagEnemy.x, _tagEnemy.y, 48, 48);
	return S_OK;
}

void orb::release()
{
}

void orb::update()
{
	_tagEnemy.state->update(this);
	_tagEnemy.rc = RectMake(_tagEnemy.x-8, _tagEnemy.y-8, 16, 16);
}

void orb::render()
{
	DTDMANAGER->Rectangle(_tagEnemy.rc);
	DTDMANAGER->Rectangle(_tagEnemy.attackRC);
	
	//cout << _tagEnemy.angle / PI2 << endl;
	cout << _tagEnemy.angle << endl;
		DTDMANAGER->setRotation(-360*_tagEnemy.angle/(PI2)-270,_tagEnemy.x - _tagEnemy.errorX, _tagEnemy.y + _tagEnemy.z);
		if (_tagEnemy.image->getMaxFrameX() == 0 && _tagEnemy.image->getMaxFrameY() == 0) {

			_tagEnemy.image->render(_tagEnemy.x, _tagEnemy.y + _tagEnemy.z);
		}
		else
		{
			_tagEnemy.image->frameRender(_tagEnemy.x, _tagEnemy.y + _tagEnemy.z, _tagEnemy.frameX, _tagEnemy.frameY);
		}
		DTDMANAGER->resetRotation();
	
}
