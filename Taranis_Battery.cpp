#include "stdafx.h"
#include "Taranis_Battery.h"
#include "player.h"

HRESULT Taranis_Battery::init(bool _isDungeon, bool _isGetted)
{
	ItemNumber = 10005;
	ItemName = "타라니스의 전지";
	stat = 0.12f;
	ItemInfo = "번개속성 공격력 12퍼 증가";
	kind = RELICS;
	RelicsType = RELICS_ATTACK;
	isDungeon = _isDungeon;
	isGetted = _isGetted;
	price_Jewel = 10;
	price_Gold = 150;
	IconImage = IMAGEMANAGER->findDImage("Taranis_Battery");

	return S_OK;
}

void Taranis_Battery::release()
{
}

void Taranis_Battery::update(player * _Player)
{
	_Player->setPlayerThunderDamage(BASIC_DAMAGE_PER + stat);
}

void Taranis_Battery::render(int x, int y, float sizeX, float sizeY)
{
	Icon = RectMake(x, y, 40, 40);

	DTDMANAGER->Rectangle(Icon);
	IconImage->scaleRender(x, y, sizeX, sizeY);
}
