#pragma once

#include "gameNode.h"
#include "stdafx.h"
#include "DateBaseManager.h"

class player;
class Home_Closet;
class Home_Lelics;
class Home_Arcana;



struct tagItemInfo
{
	RECT OutRect;
	RECT InRect;
	dImage* OutRectImg;
	dImage* InRectImg;
	float sizeX,  sizeY;
	float sizeX_in, sizeY_in;
	int distanceX,  distanceY;

	int reserveSize;

	vector<ItemBasic*> Inventory_Item;	
};


class Inventory :
	public gameNode
{
private:


	player* _Player;

	//���� ���� ��������
	tagItemInfo Inven_Cloth;
	tagItemInfo Inven_Arcana;
	tagItemInfo Inven_Relics;
	tagItemInfo Inven_Explanation;



	vector<ItemBasic*> myItem;
	vector<ItemBasic*>::iterator Iter_myItem;


	RECT _rc;


	bool  isOpenInventory;

	POINT rcXY;



public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	void setAddressLink(player* _TP) { _Player = _TP; }
	/*
	���ֹ��� �������� ���� ù��°ĭ�� �ȵ�

	���� �κ� ��ü�� x * 2��, �� �� ���¿��� ������ ù ĭ�� �ִ°� ������ ��
	������ ��ü�� ��ȣ������ �ű��, �����Ұ���.

	7*2��
	*/


	bool getisOpen() { return isOpenInventory; }
	void setOpenInventory() {isOpenInventory = isOpenInventory ? false : true;}

	//���� �� �ٲٴ� �Լ�. ���ȿ����� ��밡��
	void changeCloth(ItemBasic* _cloth)
	{
		if (_cloth->getItemKind() != CLOTH) return;//����ó��
		if (Inven_Cloth.Inventory_Item.empty()) Inven_Cloth.Inventory_Item.push_back(_cloth);
		else Inven_Cloth.Inventory_Item[0] = _cloth;
	}
	
	//���� ȹ��. �������� ����Ұ� 
	void getRelics(ItemBasic* _Relics)
	{
		if (_Relics->getItemKind() != RELICS) return;

		if (Inven_Relics.Inventory_Item.size() > 16) Inven_Relics.Inventory_Item[0] = _Relics;	
		else Inven_Relics.Inventory_Item.push_back(_Relics);
	}



	void ClearGetDungeonItem()//�������� ��� ������ ����
	{
		for (Iter_myItem = myItem.begin(); Iter_myItem != myItem.end();)
		{
			if ((*Iter_myItem)->getisDungeon())
			{
				myItem.erase(Iter_myItem);
			}
			else Iter_myItem++;
		}
	}
	POINT getXY() { return rcXY; }
	void setXY(POINT xy) { rcXY = xy; }




};

