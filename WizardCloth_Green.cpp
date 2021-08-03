#include "stdafx.h"
#include "WizardCloth_Green.h"
#include "player.h"

HRESULT WizardCloth_Green::init(bool _isDungeon, bool _isGetted)
{
	ItemNumber = 50004;
	ItemName = "¿Ï±Þ";
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

void WizardCloth_Green::release()
{
}

void WizardCloth_Green::update(player * _Player)
{
}

void WizardCloth_Green::render(int x, int y, float sizeX, float sizeY)
{
	Icon = RectMake(x, y, 40, 40);

	DTDMANAGER->Rectangle(Icon);
	IconImage->scaleRender(x, y, sizeX, sizeY);
}
