#include "stdafx.h"
#include "Siva_waterbottle.h"
#include "player.h"

HRESULT Siva_waterbottle::init(bool _isDungeon, bool _isGetted)
{
	ItemNumber = 10004;
	ItemName = "시바의 물병";
	stat = 0.12f;
	ItemInfo = "물속성 공격력 12퍼 증가";
	kind = RELICS;
	RelicsType = RELICS_ATTACK;
	isDungeon = _isDungeon;
	isGetted = _isGetted;
	price_Jewel = 10;
	price_Gold = 150;
	IconImage = IMAGEMANAGER->findDImage("Shiva_Bottle");


	return S_OK;
}

void Siva_waterbottle::release()
{
}

void Siva_waterbottle::update(player * _Player)
{
	_Player->setPlayerWaterDamage(BASIC_DAMAGE_PER + stat);
}

void Siva_waterbottle::render(int x, int y, float sizeX, float sizeY)
{
	Icon = RectMake(x, y, 40, 40);

	DTDMANAGER->Rectangle(Icon);
	IconImage->scaleRender(x, y, sizeX, sizeY);
}
