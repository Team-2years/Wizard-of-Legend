#pragma once
#include "stdafx.h"
#include "gameNode.h"
#include "ItemBasic.h"
#include "SaveDataManager.h"
#include "DateBaseManager.h"


class Inventory;


enum HomeLelicsEnum
{
	NOT_OPEN,	//안엶
	OPEN_KIND_LIST,	//유물 종류 리스트
	OPEN_RELICS_LIST //유물 보는 리스트

};

struct tagRelicsDrawer
{
	dImage* Drawer;
	dImage* Knob_1;
	dImage* Knob_2;
	dImage* Icon;
	int DrawerFrame;
	int KnobFrame;

	float x, y;
	POINT knob_XY_1;
	POINT knob_XY_2;

	int knobDistance;

	vector<ItemBasic*> Item;
	dImage* ItemInventoryImage;
	POINT ItemInvenXY;

	//bool isOpenInventory;
	


	tagRelicsType Relics_kind;


	bool isSelect;
};


class Home_Lelics :
	public gameNode
{
private:

	DateBaseManager* _DataBase;


	tagRelicsDrawer Relics_Drawer[3];

	POINT DrawerXY; 
	
	int currentDrawer;
	int frameCount;

	HomeLelicsEnum CurrentInvenMode;

	bool isOpenMimi;


	Inventory* _Inven;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	

	tagRelicsDrawer getRelics_Drawer(int i) { return Relics_Drawer[i]; }


	bool getisOpenMimi() { return isOpenMimi; }
	void setisOpenMimi(bool OpenClose) { isOpenMimi = OpenClose; }

	void getRelics(ItemBasic* _item)
	{
		if (_item->getItemKind() != RELICS) return;
		if (_item->getisDungeon()) return;

		switch (_item->getItemKind())
		{
		case RELICS_ATTACK:  if(Relics_Drawer[0].Item.size()<24) Relics_Drawer[0].Item.push_back(_item);
			break;
		case RELICS_DEFENSE:  if (Relics_Drawer[1].Item.size() < 24)  Relics_Drawer[1].Item.push_back(_item);
			break;
		case RELICS_OTHER:  if (Relics_Drawer[2].Item.size() < 24)  Relics_Drawer[2].Item.push_back(_item);
			break;
		}
	}


	void setAddressInventory(Inventory* inven) { _Inven = inven; }
	   
	void LoadRelicsData();
	
};

