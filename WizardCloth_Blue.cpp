#include "stdafx.h"
#include "WizardCloth_Blue.h"
#include "player.h"

HRESULT WizardCloth_Blue::init(bool _isDungeon, bool _isGetted)
{
	ItemNumber = 50002;
	ItemName = "ÀÎ³»";
	stat = 0.12f;
	ItemInfo = "¸¶¹ý Ç¥ÁØ";
	kind = CLOTH;
	RelicsType = NOT_RELICS;
	isDungeon = _isDungeon;
	isGetted = _isGetted;
	price_Jewel = 75;
	price_Gold = 0;
	IconImage = IMAGEMANAGER->findDImage("¿Ê_ÆÄ¶û");



	return S_OK;
}

void WizardCloth_Blue::release()
{
}

void WizardCloth_Blue::update(player * _Player)
{
}

void WizardCloth_Blue::render(int x, int y, float sizeX, float sizeY)
{
	Icon = RectMake(x, y, 40, 40);

	DTDMANAGER->Rectangle(Icon);
	IconImage->scaleRender(x, y, sizeX, sizeY);
}
