#include "stdafx.h"
#include "Iflits_MatchStick.h"
#include "player.h"

HRESULT Iflits_MatchStick::init(bool _isDungeon, bool _isGetted)
{
	ItemNumber = 10002;
	ItemName = "������Ʈ�� ���ɰ���";
	stat = 0.12f;
	ItemInfo = "�ҼӼ� ���ݷ� 12�� ����";
	kind = RELICS;
	RelicsType = RELICS_ATTACK;
	isDungeon = _isDungeon;
	isGetted = _isGetted;
	price_Jewel = 10;
	price_Gold = 150;
	IconImage = IMAGEMANAGER->findDImage("Ifrit_MatchStick");

    return S_OK;
}

void Iflits_MatchStick::release()
{
}

void Iflits_MatchStick::update(player* _Player)
{
	_Player->setPlayerFireDamaage(BASIC_DAMAGE_PER + stat);
}

void Iflits_MatchStick::render(int x, int y, float sizeX, float sizeY)
{
	Icon = RectMake(x, y, 40, 40);

	DTDMANAGER->Rectangle(Icon);
	IconImage->scaleRender(x, y, sizeX, sizeY);

}
