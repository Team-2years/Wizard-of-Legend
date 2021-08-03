#include "stdafx.h"
#include "golem.h"

HRESULT golem::init(POINT position)
{
	_tagEnemy.type = ENEMY_GOLEM;
	_tagEnemy.state = new enemyIdleState;
	_tagEnemy.state->enter(this);
	_tagEnemy.damage = 15;
	_tagEnemy.frameX = 0;
	_tagEnemy.frameY = 0;
	_tagEnemy.hp = 150;
	_tagEnemy.radius = 50;
	_tagEnemy.speed = 1;
	_tagEnemy.x = position.x;
	_tagEnemy.y = position.y;
	_tagEnemy.z = 0;
	_tagEnemy.isSummon = false;

	_tagEnemy.isRight = true;
	_tagEnemy.rc = RectMake(_tagEnemy.x, _tagEnemy.y, 48, 48);
	return S_OK;
}

void golem::release()
{
}

void golem::update()
{
	_tagEnemy.state->update(this);
	_tagEnemy.rc = RectMake(_tagEnemy.x - 3, _tagEnemy.y + 40, 24, 16);
}

void golem::render()
{
	DTDMANAGER->Rectangle(_tagEnemy.rc);
	DTDMANAGER->Rectangle(_tagEnemy.attackRC);
	if (_tagEnemy.isRight)
		if (_tagEnemy.image->getMaxFrameX() == 0 && _tagEnemy.image->getMaxFrameY() == 0) {
			RENDERMANAGER->push_BackRenderInfo(_tagEnemy.rc.bottom, _tagEnemy.image, _tagEnemy.x + _tagEnemy.errorX, _tagEnemy.y + _tagEnemy.errorY + _tagEnemy.z);
		}
		else RENDERMANAGER->push_BackFrameRenderInfo(_tagEnemy.rc.bottom, _tagEnemy.image, _tagEnemy.x + _tagEnemy.errorX, _tagEnemy.y + _tagEnemy.errorY + _tagEnemy.z, _tagEnemy.frameX, _tagEnemy.frameY);
	else
	{
		DTDMANAGER->setScale(_tagEnemy.x - _tagEnemy.errorX, _tagEnemy.y + _tagEnemy.errorY + _tagEnemy.z);
		if (_tagEnemy.image->getMaxFrameX() == 0 && _tagEnemy.image->getMaxFrameY() == 0) {

			_tagEnemy.image->render(_tagEnemy.x, _tagEnemy.y + _tagEnemy.errorY + _tagEnemy.z);
		}
		else
		{
			_tagEnemy.image->frameRender(_tagEnemy.x, _tagEnemy.y + _tagEnemy.errorY + _tagEnemy.z, _tagEnemy.frameX, _tagEnemy.frameY);
		}
		DTDMANAGER->resetRotation();
	}
}
