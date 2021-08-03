#include "stdafx.h"
#include "Rudra_Vane.h"
#include "player.h"

HRESULT Rudra_Vane::init(bool _isDungeon, bool _isGetted)
{
	ItemNumber = 10003;
	ItemName = "������ �ٶ�����";
	stat = 0.12f;
	ItemInfo = "�ٶ��Ӽ� ���ݷ� 12�� ����";
	kind = RELICS;
	RelicsType = RELICS_ATTACK;
	isDungeon = _isDungeon;
	isGetted = _isGetted;
	price_Jewel = 10;
	price_Gold = 150;
	IconImage = IMAGEMANAGER->findDImage("Rudra_Vane");

	return S_OK;
}

void Rudra_Vane::release()
{
}

void Rudra_Vane::update(player * _Player)
{
	_Player->setPlayerWindDamage(BASIC_DAMAGE_PER + stat);
}

void Rudra_Vane::render(int x, int y, float sizeX, float sizeY)
{

	Icon = RectMake(x, y, 40, 40);

	DTDMANAGER->Rectangle(Icon);
	IconImage->scaleRender(x, y, sizeX, sizeY);
}
