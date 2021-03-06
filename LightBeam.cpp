#include "stdafx.h"
#include "LightBeam.h"

HRESULT LightBeam::init(int skillMax, float range)
{

	_SkillMax = skillMax;
	_range = range;
	_x2 = 0;


	return S_OK;
}

void LightBeam::release()
{
}

void LightBeam::update()
{
	move();

}

void LightBeam::render()
{

	for (_viSkill = _vSkill.begin(); _viSkill != _vSkill.end(); ++_viSkill)
	{
		float _rx = (_viSkill->rc.right + _viSkill->rc.left) / 2;
		float _ry = (_viSkill->rc.bottom + _viSkill->rc.top) / 2;
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

		if (_viSkill->count % 5 == 0)
		{
			_viSkill->skillImage->setFrameX(_viSkill->skillImage->getFrameX() + 1);

			//최대 프레임보다 커지면
			//if (_viSkill->skillImage->getFrameX() >= _viSkill->skillImage->getMaxFrameX())
			//{
			//	_viSkill->skillImage->setFrameX(0);


			//}

			_viSkill->count = 0;
		}
	}

}

void LightBeam::fire(float x, float y, float angle, bool playerATK)
{
	if (_SkillMax < _vSkill.size()) return;

	tagLightBeam Skill;
	ZeroMemory(&Skill, sizeof(tagLightBeam));
	_angle = angle;
	Skill.skillImage = new dImage;
	Skill.skillImage->init(L"skill/전기방전.png", (int)2597, 55, 7, 1);
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


void LightBeam::move()
{
	for (_viSkill = _vSkill.begin(); _viSkill != _vSkill.end();)
	{
		_time++;
		if (_viSkill->playerATK == true)
		{
			_viSkill->rc = RectMakeCenter(_viSkill->x + 165, _viSkill->y,
				_viSkill->skillImage->getFrameWidth(),
				_viSkill->skillImage->getFrameHeight());
		}
		else
		{
			_viSkill->rc2 = RectMakeCenter(_viSkill->x + 165, _viSkill->y,
				_viSkill->skillImage->getFrameWidth(),
				_viSkill->skillImage->getFrameHeight());
		}
		if (_viSkill->skillImage->getFrameX() >= _viSkill->skillImage->getMaxFrameX())
		{
			//_viSkill->skillImage->setFrameX(0);
			SAFE_RELEASE(_viSkill->skillImage);
			SAFE_DELETE(_viSkill->skillImage);
			_viSkill = _vSkill.erase(_viSkill);

		}
		else ++_viSkill;
		//사거리보다 더 멀리 나가면(?)
		/*if (_range < getDistance(_viSkill->x, _viSkill->y, _viSkill->fireX, _viSkill->fireY))
		{

			float _rx = (_viSkill->rc.right + _viSkill->rc.left) / 2;
			float _ry = (_viSkill->rc.bottom + _viSkill->rc.top) / 2;
			_burn->fire(_rx, _ry, 0, 0);
			PARTICLEMANAGER->play("화염펑", _rx, _ry, 0);
			SAFE_RELEASE(_viSkill->skillImage);
			SAFE_DELETE(_viSkill->skillImage);
			_viSkill = _vSkill.erase(_viSkill);
		}*/
		//else ++_viSkill;

	}
}

void LightBeam::removeSkill(int arrNum)
{
	_vSkill[arrNum].skillImage->release();
	_vSkill.erase(_vSkill.begin() + arrNum);


}