#pragma once
#include "stdafx.h"
#include "gameNode.h"

enum keyKind
{
	MOVE,
	SKILL,
	INTERACTION,
	MENU_TAP,
	MAP,
};


struct PlayerKey
{
	int key;
	D2D1_RECT_F rc;
	keyKind kind;
	dImage* KeyImage;
	string KeyName;
	dImage* IconImage;
	string IconName;
	bool is_Can_Click;
	bool isClick;
};

class gameKey :
	public gameNode
{
private:


	PlayerKey defaultKey[4];//이동키
	PlayerKey OtherKey[8];//0~5 아르카나, 6 메뉴, 7 지도

public:




};

