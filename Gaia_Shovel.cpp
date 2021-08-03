#include "stdafx.h"
#include "Gaia_Shovel.h"
#include "player.h"

HRESULT Gaia_Shovel::init(bool _isDungeon, bool _isGetted)
{
	

	ItemNumber = 10001;
	ItemName = "가이아의 삽";
	stat = 0.12f;
	ItemInfo = "땅속성 공격력 12퍼 증가";
	kind = RELICS;
	RelicsType = RELICS_ATTACK;
	isDungeon = _isDungeon;
	isGetted = _isGetted;
	price_Jewel = 10;
	price_Gold = 150;
	IconImage = IMAGEMANAGER->findDImage("Gaia_Shovel");

	return S_OK;
}

void Gaia_Shovel::release()
{
}

void Gaia_Shovel::update(player* _Player)
{
	
	//_Player->setPlayerEarthDamage(_Player->getPlayerData()->PlayerEarthDamage + stat);
	_Player->setPlayerEarthDamage(BASIC_DAMAGE_PER + stat);
}

void Gaia_Shovel::render(int x, int y, float sizeX, float sizeY)
{
	Icon = RectMake(x, y, 40, 40);

	DTDMANAGER->Rectangle(Icon);
	IconImage->scaleRender(x, y,sizeX,sizeY);

}
