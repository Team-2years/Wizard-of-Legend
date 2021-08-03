#include "stdafx.h"
#include "WizardCloth_Red.h"
#include "player.h"

HRESULT WizardCloth_Red::init(bool _isDungeon, bool _isGetted)
{
	ItemNumber = 50001;
	ItemName = "Èñ¸Á";
	stat = 0.12f;
	ItemInfo = "¸¶¹ý Ç¥ÁØ";
	kind = CLOTH;
	RelicsType = NOT_RELICS;
	isDungeon = _isDungeon;
	isGetted = _isGetted;
	price_Jewel = 75;
	price_Gold = 0;
	IconImage = IMAGEMANAGER->findDImage("¿Ê_»¡°­");


	return S_OK;
}

void WizardCloth_Red::release()
{
}

void WizardCloth_Red::update(player * _Player)
{
}

void WizardCloth_Red::render(int x, int y, float sizeX, float sizeY)
{
	Icon = RectMake(x, y, 40, 40);

	DTDMANAGER->Rectangle(Icon);
	IconImage->scaleRender(x, y, sizeX, sizeY);
}
