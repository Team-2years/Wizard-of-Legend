#include "stdafx.h"
#include "Home_Lelics.h"
#include "Inventory.h"


#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

HRESULT Home_Lelics::init()
{

	DrawerXY = PointMake(45, 30);

	for (int i = 0; i < 3; i++)
	{
		Relics_Drawer[i].Drawer = IMAGEMANAGER->findDImage("유물함");
		Relics_Drawer[i].Knob_1 = IMAGEMANAGER->findDImage("손잡이");
		Relics_Drawer[i].Knob_2 = IMAGEMANAGER->findDImage("손잡이");
		Relics_Drawer[i].DrawerFrame = 0;
		Relics_Drawer[i].KnobFrame = 0;

		Relics_Drawer[i].x = DrawerXY.x + 55;
		Relics_Drawer[i].y = DrawerXY.y + 155 + 102*i;
		

		Relics_Drawer[i].knob_XY_1 = PointMake(Relics_Drawer[i].x + 47, Relics_Drawer[i].y + 29);
		Relics_Drawer[i].knob_XY_2 = PointMake(Relics_Drawer[i].x + 435, Relics_Drawer[i].y + 29);
		
		switch (i)
		{
		case 0: Relics_Drawer[i].Relics_kind = RELICS_ATTACK;
			Relics_Drawer[i].Icon = IMAGEMANAGER->findDImage("공격유물 아이콘");
			break;
		case 1: Relics_Drawer[i].Relics_kind = RELICS_DEFENSE;
			Relics_Drawer[i].Icon = IMAGEMANAGER->findDImage("방어유물 아이콘");
			break;
		case 2: Relics_Drawer[i].Relics_kind = RELICS_OTHER;
			Relics_Drawer[i].Icon = IMAGEMANAGER->findDImage("기타유물 아이콘");
			break;
		}
		
		Relics_Drawer[i].isSelect = false;
		
		Relics_Drawer[i].knobDistance = 0;

		Relics_Drawer[i].ItemInventoryImage = IMAGEMANAGER->findDImage("유물목록");

		Relics_Drawer[i].ItemInvenXY = PointMake(DrawerXY.x, DrawerXY.y + 15);
	}

	
	currentDrawer = 0;
	Relics_Drawer[currentDrawer].isSelect = true;
	frameCount = 0;

	CurrentInvenMode = OPEN_KIND_LIST;

	isOpenMimi = false;


	_DataBase = new DateBaseManager;
	_DataBase->init();

	return S_OK;
}

void Home_Lelics::release()
{
}

void Home_Lelics::update()
{
	if (CurrentInvenMode == OPEN_KIND_LIST)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_HOME))
		{
			if (currentDrawer > 0)
			{
				currentDrawer--;
				Relics_Drawer[currentDrawer + 1].isSelect = false;
				Relics_Drawer[currentDrawer + 1].DrawerFrame = 0;
				Relics_Drawer[currentDrawer + 1].knobDistance = 0;
				Relics_Drawer[currentDrawer].isSelect = true;
				Relics_Drawer[currentDrawer].DrawerFrame = 0;
				Relics_Drawer[currentDrawer].KnobFrame = 0;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_END))
		{
			if (currentDrawer < 2)
			{
				currentDrawer++;
				Relics_Drawer[currentDrawer - 1].isSelect = false;
				Relics_Drawer[currentDrawer - 1].DrawerFrame = 0;
				Relics_Drawer[currentDrawer - 1].knobDistance = 0;
				Relics_Drawer[currentDrawer].isSelect = true;
				Relics_Drawer[currentDrawer].DrawerFrame = 0;
				Relics_Drawer[currentDrawer].KnobFrame = 0;
			}
		}


		if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) CurrentInvenMode = OPEN_RELICS_LIST;

		if (Relics_Drawer[currentDrawer].isSelect)
		{
			frameCount++;

			if (frameCount % 1 == 0)
			{
				Relics_Drawer[currentDrawer].DrawerFrame++;
				Relics_Drawer[currentDrawer].knobDistance += 5;
				if (Relics_Drawer[currentDrawer].DrawerFrame > 3)
				{
					Relics_Drawer[currentDrawer].DrawerFrame = 3;
					Relics_Drawer[currentDrawer].knobDistance = 20;
				}
			}

			if (frameCount % 7 == 0)
			{
				Relics_Drawer[currentDrawer].KnobFrame++;
				if (Relics_Drawer[currentDrawer].KnobFrame > 2) Relics_Drawer[currentDrawer].KnobFrame = 2;
			}
		}
	}

	if (CurrentInvenMode == OPEN_RELICS_LIST)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) CurrentInvenMode = OPEN_KIND_LIST;
	}

	//73,191
	//162,191

	if (KEYMANAGER->isOnceKeyDown('B')) getRelics(_DataBase->findItem(10001));
	if (KEYMANAGER->isOnceKeyDown('N')) getRelics(_DataBase->findItem(10002));





	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		SAVEDATAMANAGER->DataSave_Attack_Relics(Relics_Drawer[0].Item);
	}
	if (KEYMANAGER->isOnceKeyDown('V'))
	{		
		LoadRelicsData();
	}
}

void Home_Lelics::render()
{
	IMAGEMANAGER->findDImage("유물함 UI")->render(DrawerXY.x, DrawerXY.y);


	switch (CurrentInvenMode)
	{
	case OPEN_KIND_LIST:

		for (int i = 2; i >= 0; i--)
		{
			Relics_Drawer[i].Drawer->frameRender(Relics_Drawer[i].x, Relics_Drawer[i].y, Relics_Drawer[i].DrawerFrame, 0);

			Relics_Drawer[i].Knob_1->frameRender(Relics_Drawer[i].knob_XY_1.x, Relics_Drawer[i].knob_XY_1.y + Relics_Drawer[i].knobDistance, Relics_Drawer[i].KnobFrame, 0);
			Relics_Drawer[i].Knob_2->frameRender(Relics_Drawer[i].knob_XY_2.x, Relics_Drawer[i].knob_XY_2.y + Relics_Drawer[i].knobDistance, Relics_Drawer[i].KnobFrame, 0);
			Relics_Drawer[i].Icon->render((Relics_Drawer[i].knob_XY_2.x + Relics_Drawer[i].knob_XY_1.x) / 2, Relics_Drawer[i].knob_XY_1.y + Relics_Drawer[i].knobDistance);
		}

		break;
	case OPEN_RELICS_LIST:

		Relics_Drawer[currentDrawer].ItemInventoryImage->render(Relics_Drawer[currentDrawer].ItemInvenXY.x, Relics_Drawer[currentDrawer].ItemInvenXY.y);
		Relics_Drawer[currentDrawer].Icon->render(Relics_Drawer[currentDrawer].ItemInvenXY.x + 75, Relics_Drawer[currentDrawer].ItemInvenXY.y + 60);

		for (int i = 0; i < Relics_Drawer[currentDrawer].Item.size(); i++)
		{
			Relics_Drawer[currentDrawer].Item[i]->getImage()->scaleRender(DrawerXY.x + 78 + 90 * (i % 6), DrawerXY.y + 180 + 94 * (i / 6),0.5f,0.5f);


		}




		break;
	}


//	cout << currentDrawer << endl;

	//cout << "X : " << _ptMouse.x << " , Y : " << _ptMouse.y << endl;

	//45,30
	//123,216
	//213,216
	//, 310 
}

void Home_Lelics::LoadRelicsData()
{
	Relics_Drawer[0].Item.clear();

	SAVEDATAMANAGER->Load_Attack_Relics();

	for (int i = 0; i < 24; i++)
	{
		if (SAVEDATAMANAGER->getData().Attack_Relics_Data[i] == 99999) break;
		Relics_Drawer[0].Item.push_back(_DataBase->findItem(SAVEDATAMANAGER->getData().Attack_Relics_Data[i]));
	}


}
