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

	//추후 유물 넣을예정
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
	저주받은 아이템은 절대 첫번째칸에 안들어감

	유물 인벤 자체는 x * 2고, 다 찬 상태에서 먹으면 첫 칸에 있는거 버리는 식
	아이템 자체는 번호순으로 매기고, 정렬할거임.

	7*2로
	*/


	bool getisOpen() { return isOpenInventory; }
	void setOpenInventory() {isOpenInventory = isOpenInventory ? false : true;}

	//현재 옷 바꾸는 함수. 집안에서만 사용가능
	void changeCloth(ItemBasic* _cloth)
	{
		if (_cloth->getItemKind() != CLOTH) return;//예외처리
		if (Inven_Cloth.Inventory_Item.empty()) Inven_Cloth.Inventory_Item.push_back(_cloth);
		else Inven_Cloth.Inventory_Item[0] = _cloth;
	}
	
	//유물 획득. 던전에서 사용할거 
	void getRelics(ItemBasic* _Relics)
	{
		if (_Relics->getItemKind() != RELICS) return;

		if (Inven_Relics.Inventory_Item.size() > 16) Inven_Relics.Inventory_Item[0] = _Relics;	
		else Inven_Relics.Inventory_Item.push_back(_Relics);
	}



	void ClearGetDungeonItem()//던전에서 샀던 아이템 삭제
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

