#include "stdafx.h"
#include "mimic.h"

HRESULT mimic::init(POINT position)
{
	_tagEnemy.type = ENEMY_MIMIC;
	_tagEnemy.state = new enemyIdleState;
	_tagEnemy.state->enter(this);
	_tagEnemy.damage = 15;
	_tagEnemy.frameX = 0;
	_tagEnemy.frameY = 0;
	_tagEnemy.hp = 120;
	_tagEnemy.radius = 50;
	_tagEnemy.speed = 4.5;
	_tagEnemy.x = position.x;
	_tagEnemy.y = position.y;
	_tagEnemy.z = 0;
	_tagEnemy.isRight = true;
	_tagEnemy.isSummon = false;

	_tagEnemy.rc = RectMake(_tagEnemy.x, _tagEnemy.y, 48, 48);
	return S_OK;
}

void mimic::release()
{
}

void mimic::update()
{
	_tagEnemy.state->update(this);
	_tagEnemy.rc = RectMake(_tagEnemy.x, _tagEnemy.y + 10, 18, 16);
}

void mimic::render()
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
		DTDMANAGER->setScale(_tagEnemy.x, _tagEnemy.y + _tagEnemy.errorY + _tagEnemy.z);
		if (_tagEnemy.image->getMaxFrameX() == 0 && _tagEnemy.image->getMaxFrameY() == 0) {

			_tagEnemy.image->render(_tagEnemy.x + _tagEnemy.errorX - 48 + _tagEnemy.image->getWidth(), _tagEnemy.y + _tagEnemy.errorY + _tagEnemy.z);
		}
		else
		{
			_tagEnemy.image->frameRender(_tagEnemy.x + _tagEnemy.errorX - 48 + _tagEnemy.image->getFrameWidth(), _tagEnemy.y + _tagEnemy.errorY + _tagEnemy.z, _tagEnemy.frameX, _tagEnemy.frameY);
		}
		DTDMANAGER->resetRotation();
	}
}
