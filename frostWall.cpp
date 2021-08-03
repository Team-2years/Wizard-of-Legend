
#include "stdafx.h"
#include "frostWall.h"

HRESULT frostWall::init(int skillMax, float range)
{
	_burn = new burn;
	_burn->init(50, 5);
	_SkillMax = skillMax;
	_range = range;
	_x2 = 0;
	return S_OK;

}

void frostWall::release()
{
}

void frostWall::update()
{
	move();
	_burn->update();
}

void frostWall::render()
{

	for (_viSkill = _vSkill.begin(); _viSkill != _vSkill.end(); ++_viSkill)
	{
		float _rx = (_viSkill->rc.right + _viSkill->rc.left) / 2;
		float _ry = (_viSkill->rc.bottom + _viSkill->rc.top) / 2 + 40;
		int _scale = 10;

		//DTDMANAGER->setRotation(_angle, (_viSkill->rc.right+ _viSkill->rc.left) /2, (_viSkill->rc.bottom + _viSkill->rc.top) / 2);
		DTDMANAGER->setRotation(-_angle, _viSkill->x, _viSkill->y);
		_viSkill->skillImage->frameRender(
			_viSkill->rc.left,
			_viSkill->rc.top,
			_viSkill->skillImage->getFrameX(), 0);
		DTDMANAGER->resetRotation();
		DTDMANAGER->setRotation(-_angle, _viSkill->x, _viSkill->y);
		_viSkill->skillImage->frameRender(
			_viSkill->rc2.left,
			_viSkill->rc2.top,
			_viSkill->skillImage->getFrameX(), 0);
		DTDMANAGER->resetRotation();
		//DTDMANAGER->Rectangle(_viSkill->rc);
		_viSkill->count++;

		if (_viSkill->count % 3 == 0)
		{
			if (_viSkill->skillImage->getFrameX() <= 1)
			{
				_viSkill->skillImage->setFrameX(_viSkill->skillImage->getFrameX() + 1);
			}
			if (_viSkill->_go == true)
			{
				_viSkill->skillImage->setFrameX(_viSkill->skillImage->getFrameX() + 1);
			}
			//�ִ� �����Ӻ��� Ŀ����
			//if (_viSkill->skillImage->getFrameX() >= _viSkill->skillImage->getMaxFrameX())
			//{
			//	_viSkill->skillImage->setFrameX(0);


			//}

			_viSkill->count = 0;
		}
	}
	_burn->render();
}

void frostWall::fire(float x, float y, float angle, bool playerATK)
{
	if (_SkillMax < _vSkill.size()) return;

	tagfrostWall Skill;
	ZeroMemory(&Skill, sizeof(tagfrostWall));
	_angle = angle;
	Skill.skillImage = new dImage;
	Skill.skillImage->init(L"skill/�������2.png", (int)234, 55, 6, 1);
	Skill.speed = 10.0f;
	Skill.angle = angle * PI / 180;
	Skill.x = Skill.fireX = x;
	Skill.y = Skill.fireY = y;
	Skill.playerATK = playerATK;
	if (Skill.playerATK == true)
	{
		Skill.rc = RectMakeCenter(Skill.x, Skill.y,
			Skill.skillImage->getFrameWidth(),
			Skill.skillImage->getFrameHeight());
	}
	else
	{
		Skill.rc2 = RectMakeCenter(Skill.x, Skill.y,
			Skill.skillImage->getFrameWidth(),
			Skill.skillImage->getFrameHeight());
	}

	_vSkill.push_back(Skill);
}


void frostWall::move()
{
	for (_viSkill = _vSkill.begin(); _viSkill != _vSkill.end();)
	{
		_viSkill->_time++;
		//_viSkill->x += _viSkill->speed;
		//_viSkill->x += cosf(_viSkill->angle) * _viSkill->speed;
		//_viSkill->y += -sinf(_viSkill->angle) * _viSkill->speed;
		if (_viSkill->playerATK == true)
		{
			_viSkill->rc = RectMakeCenter(_viSkill->x, _viSkill->y,
				_viSkill->skillImage->getFrameWidth(),
				_viSkill->skillImage->getFrameHeight());
		}
		else
		{
			_viSkill->rc2 = RectMakeCenter(_viSkill->x, _viSkill->y,
				_viSkill->skillImage->getFrameWidth(),
				_viSkill->skillImage->getFrameHeight());
		}
		if (_viSkill->_time > 200)
		{
			_viSkill->_time = 0;
			_viSkill->_go = true;

		}
		if (_viSkill->skillImage->getFrameX() >= _viSkill->skillImage->getMaxFrameX())
		{


			_viSkill->_go = false;
			SAFE_RELEASE(_viSkill->skillImage);
			SAFE_DELETE(_viSkill->skillImage);
			_viSkill = _vSkill.erase(_viSkill);


		}
		else ++_viSkill;

		//��Ÿ����� �� �ָ� ������(?)
		/*if (_range < getDistance(_viSkill->x, _viSkill->y, _viSkill->fireX, _viSkill->fireY))
		{

			float _rx = (_viSkill->rc.right + _viSkill->rc.left) / 2;
			float _ry = (_viSkill->rc.bottom + _viSkill->rc.top) / 2;
			_burn->fire(_rx, _ry, 0, 0);
			PARTICLEMANAGER->play("ȭ����", _rx, _ry, 0);
			SAFE_RELEASE(_viSkill->skillImage);
			SAFE_DELETE(_viSkill->skillImage);
			_viSkill = _vSkill.erase(_viSkill);
		}*/
		//else ++_viSkill;

	}
}

void frostWall::removeSkill(int arrNum)
{
	_vSkill[arrNum].skillImage->release();
	_vSkill.erase(_vSkill.begin() + arrNum);


}
