#include "stdafx.h"
#include "Giant_Heart.h"
#include "player.h"

HRESULT Giant_Heart::init(bool _isDungeon, bool _isGetted)
{
	ItemNumber = 20001;
	ItemName = "거인의 심장";
	stat = 0.12f;
	ItemInfo = "최대 체력 10% 증가";
	kind = RELICS;
	RelicsType = RELICS_ATTACK;
	isDungeon = _isDungeon;
	isGetted = _isGetted;
	price_Jewel = 10;
	price_Gold = 150;
	IconImage = IMAGEMANAGER->findDImage("Gaia_Shovel");

	return S_OK;
}

void Giant_Heart::release()
{
}

void Giant_Heart::update(player * _Player)
{
	_Player->getPlayerData()->maxHp = BASIC_MAX_HP + BASIC_MAX_HP * 0.1f;
}

void Giant_Heart::render(int x, int y, float sizeX, float sizeY)
{
	Icon = RectMake(x, y, 40, 40);

	DTDMANAGER->Rectangle(Icon);
	IconImage->scaleRender(x, y, sizeX, sizeY);
}
