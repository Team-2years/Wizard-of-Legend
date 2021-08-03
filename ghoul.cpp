#include "stdafx.h"
#include "ghoul.h"
#include "enemyIdleState.h"

HRESULT ghoul::init(POINT position)
{
	_tagEnemy.type = ENEMY_GHOUL;
	_tagEnemy.state = new enemyIdleState;
	_tagEnemy.state->enter(this);
	_tagEnemy.damage = 5;
	_tagEnemy.frameX = 0;
	_tagEnemy.isSummon = false;

	_tagEnemy.frameY = 0;
	_tagEnemy.hp = 50;
	_tagEnemy.radius = 30;
	_tagEnemy.speed = 2.5;
	_tagEnemy.x = position.x;
	_tagEnemy.y = position.y;
	_tagEnemy.z = 0;
	_tagEnemy.isRight = true;
	_tagEnemy.rc = RectMake(_tagEnemy.x, _tagEnemy.y, 48, 48);
	return S_OK;
}

void ghoul::release()
{
}

void ghoul::update()
{
	_tagEnemy.state->update(this);
	_tagEnemy.rc = RectMake(_tagEnemy.x, _tagEnemy.y, 18, 36);
	if (_tagEnemy.anglePlayer <= PI / 2 || _tagEnemy.anglePlayer >= PI * 3 / 2)
		_tagEnemy.isRight = true;
	else
		_tagEnemy.isRight = false;

}

void ghoul::render()
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
