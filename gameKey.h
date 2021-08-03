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


	PlayerKey defaultKey[4];//�̵�Ű
	PlayerKey OtherKey[8];//0~5 �Ƹ�ī��, 6 �޴�, 7 ����

public:




};

