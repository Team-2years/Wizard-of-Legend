#include "stdafx.h"
#include "Inventory.h"
#include "gameNode.h"
#include "player.h"
#include "Home_Closet.h"
#include "Home_Lelics.h"
#include "Home_Arcana.h"


HRESULT Inventory::init()
{

	
	_rc = RectMake(120, 15, 400, 680);


	//==================================옷==================================
	Inven_Cloth.reserveSize = 1;
	//Inven_Cloth.Inventory_Item[0] = nullptr;
	Inven_Cloth.OutRect = RectMake(_rc.left, _rc.top, 400, 80);
	Inven_Cloth.InRect = RectMake(Inven_Cloth.OutRect.left + 20,
								 Inven_Cloth.OutRect.top+15,
									360,50);

	Inven_Cloth.InRectImg = IMAGEMANAGER->findDImage("InRect");
	Inven_Cloth.OutRectImg = IMAGEMANAGER->findDImage("OutRect");

	Inven_Cloth.sizeX = (float)(Inven_Cloth.OutRect.right - Inven_Cloth.OutRect.left)  / (float)Inven_Cloth.OutRectImg->getWidth();
	Inven_Cloth.sizeY = (float)(Inven_Cloth.OutRect.bottom - Inven_Cloth.OutRect.top) / (float)Inven_Cloth.OutRectImg->getHeight();

	Inven_Cloth.sizeX_in = (float)(Inven_Cloth.InRect.right - Inven_Cloth.InRect.left) / (float)Inven_Cloth.InRectImg->getWidth();
	Inven_Cloth.sizeY_in = (float)(Inven_Cloth.InRect.bottom - Inven_Cloth.InRect.top) / (float)Inven_Cloth.InRectImg->getHeight();


	//===============================아르카나==================================
	Inven_Arcana.reserveSize = 6;
	Inven_Arcana.OutRect = RectMake(_rc.left, Inven_Cloth.OutRect.bottom, 400, 160);
	Inven_Arcana.InRect = RectMake(Inven_Arcana.OutRect.left + 20,
		Inven_Arcana.OutRect.top + 30,
									360, 70);

	Inven_Arcana.InRectImg = IMAGEMANAGER->findDImage("InRect");
	Inven_Arcana.OutRectImg = IMAGEMANAGER->findDImage("OutRect");

	Inven_Arcana.sizeX = (float)(Inven_Arcana.OutRect.right - Inven_Arcana.OutRect.left) / (float)Inven_Arcana.OutRectImg->getWidth();
	Inven_Arcana.sizeY = (float)(Inven_Arcana.OutRect.bottom - Inven_Arcana.OutRect.top) / (float)Inven_Arcana.OutRectImg->getHeight();

	Inven_Arcana.sizeX_in = (float)(Inven_Arcana.InRect.right - Inven_Arcana.InRect.left) / (float)Inven_Arcana.InRectImg->getWidth();
	Inven_Arcana.sizeY_in = (float)(Inven_Arcana.InRect.bottom - Inven_Arcana.InRect.top) / (float)Inven_Arcana.InRectImg->getHeight();

	//=================================유물==================================
	Inven_Relics.reserveSize = 14;
	Inven_Relics.OutRect = RectMake(_rc.left, Inven_Arcana.OutRect.bottom, 400, 160);
	Inven_Relics.InRect = RectMake(Inven_Relics.OutRect.left + 20,
									Inven_Relics.OutRect.top + 40,
									360,110);

	Inven_Relics.InRectImg = IMAGEMANAGER->findDImage("InRect");
	Inven_Relics.OutRectImg = IMAGEMANAGER->findDImage("OutRect");


	Inven_Relics.sizeX = (float)(Inven_Relics.OutRect.right - Inven_Relics.OutRect.left) / (float)Inven_Relics.OutRectImg->getWidth();
	Inven_Relics.sizeY = (float)(Inven_Relics.OutRect.bottom - Inven_Relics.OutRect.top) / (float)Inven_Relics.OutRectImg->getHeight();

	Inven_Relics.sizeX_in = (float)(Inven_Relics.InRect.right - Inven_Relics.InRect.left) / (float)Inven_Relics.InRectImg->getWidth();
	Inven_Relics.sizeY_in = (float)(Inven_Relics.InRect.bottom - Inven_Relics.InRect.top) / (float)Inven_Relics.InRectImg->getHeight();


	//=================================설명==================================
	Inven_Explanation.OutRect = RectMake(_rc.left, Inven_Relics.OutRect.bottom, 400, 300);
	Inven_Explanation.InRect = RectMake(Inven_Explanation.OutRect.left + 20, 
										Inven_Explanation.OutRect.top+40,
										360,240);

	Inven_Explanation.InRectImg = IMAGEMANAGER->findDImage("InRect");
	Inven_Explanation.OutRectImg = IMAGEMANAGER->findDImage("OutRect");

	Inven_Explanation.sizeX = (float)(Inven_Explanation.OutRect.right - Inven_Explanation.OutRect.left) / (float)Inven_Explanation.OutRectImg->getWidth();
	Inven_Explanation.sizeY = (float)(Inven_Explanation.OutRect.bottom - Inven_Explanation.OutRect.top) / (float)Inven_Explanation.OutRectImg->getHeight();

	Inven_Explanation.sizeX_in = (float)(Inven_Explanation.InRect.right - Inven_Explanation.InRect.left) / (float)Inven_Explanation.InRectImg->getWidth();
	Inven_Explanation.sizeY_in = (float)(Inven_Explanation.InRect.bottom - Inven_Explanation.InRect.top) / (float)Inven_Explanation.InRectImg->getHeight();


	isOpenInventory = false;

	

	return S_OK;
}

void Inventory::release()
{
}

void Inventory::update()
{
	if (KEYMANAGER->isOnceKeyDown('Z')) 
	{
		isOpenInventory = isOpenInventory ? false : true;
	}

	for (int i = 0; i < Inven_Relics.Inventory_Item.size(); i++)
	{
		Inven_Relics.Inventory_Item[i]->update(_Player);
	}
	
	_rc = RectMake(CAMERAMANAGER->getScreen().left+ rcXY.x, CAMERAMANAGER->getScreen().top + rcXY.y, 400, 680);
	/*Inven_Cloth.OutRect = RectMake(_rc.left, _rc.top, 400, 80);
	Inven_Cloth.InRect = RectMake(Inven_Cloth.OutRect.left + 20,
		Inven_Cloth.OutRect.top + 15,
		360, 50);

	Inven_Arcana.OutRect = RectMake(_rc.left, Inven_Cloth.OutRect.bottom, 400, 160);
	Inven_Arcana.InRect = RectMake(Inven_Arcana.OutRect.left + 20,
		Inven_Arcana.OutRect.top + 30,
		360, 70);

	Inven_Relics.OutRect = RectMake(_rc.left, Inven_Arcana.OutRect.bottom, 400, 160);
	Inven_Relics.InRect = RectMake(Inven_Relics.OutRect.left + 20,
		Inven_Relics.OutRect.top + 40,
		360, 110);

	Inven_Explanation.OutRect = RectMake(_rc.left, Inven_Relics.OutRect.bottom, 400, 300);
	Inven_Explanation.InRect = RectMake(Inven_Explanation.OutRect.left + 20,
		Inven_Explanation.OutRect.top + 40,
		360, 240);*/
}

void Inventory::render()
{
	if (isOpenInventory)
	{
	//	DTDMANAGER->Rectangle(_rc);

		//DTDMANAGER->Rectangle(Inven_Cloth.OutRect);
		//DTDMANAGER->Rectangle(Inven_Cloth.InRect);

		//DTDMANAGER->Rectangle(Inven_Arcana.OutRect);
		//DTDMANAGER->Rectangle(Inven_Arcana.InRect);

		//
		//DTDMANAGER->Rectangle(Inven_Relics.OutRect);
		//DTDMANAGER->Rectangle(Inven_Relics.InRect);
		//
		//DTDMANAGER->Rectangle(Inven_Explanation.OutRect);
		//DTDMANAGER->Rectangle(Inven_Explanation.InRect);

	


		Inven_Cloth.OutRectImg->scaleRender(Inven_Cloth.OutRect.left, Inven_Cloth.OutRect.top, 
											Inven_Cloth.sizeX, Inven_Cloth.sizeY, 0.95f);
		Inven_Cloth.InRectImg->scaleRender(Inven_Cloth.InRect.left, Inven_Cloth.InRect.top,
			Inven_Cloth.sizeX_in, Inven_Cloth.sizeY_in, 0.95f);


		if (Inven_Cloth.Inventory_Item[0] != nullptr)
		{
			Inven_Cloth.Inventory_Item[0]->getImage()->scaleRender(Inven_Cloth.InRect.left + 40, Inven_Cloth.InRect.top-5, 1.0f, 1.0f);
		}

		Inven_Arcana.OutRectImg->scaleRender(Inven_Arcana.OutRect.left, Inven_Arcana.OutRect.top,
			Inven_Arcana.sizeX, Inven_Arcana.sizeY, 0.95f);
		Inven_Arcana.InRectImg->scaleRender(Inven_Arcana.InRect.left, Inven_Arcana.InRect.top,
			Inven_Arcana.sizeX_in, Inven_Arcana.sizeY_in, 0.95f);



		Inven_Relics.OutRectImg->scaleRender(Inven_Relics.OutRect.left, Inven_Relics.OutRect.top,
			Inven_Relics.sizeX, Inven_Relics.sizeY, 0.95f);
		Inven_Relics.InRectImg->scaleRender(Inven_Relics.InRect.left, Inven_Relics.InRect.top,
			Inven_Relics.sizeX_in, Inven_Relics.sizeY_in, 0.95f);



		if (!Inven_Relics.Inventory_Item.empty())
		{
			for (int i = 0; i < Inven_Relics.Inventory_Item.size(); i++)
			{			
				Inven_Relics.Inventory_Item[i]->render(Inven_Relics.InRect.left + 10 + 60*(i%7) , Inven_Relics.InRect.top + 10 + 60*(i/7),(float)40/97,(float)40/98);
			}
		}

		Inven_Explanation.OutRectImg->scaleRender(Inven_Explanation.OutRect.left, Inven_Explanation.OutRect.top,
			Inven_Explanation.sizeX, Inven_Explanation.sizeY, 0.95f);
		Inven_Explanation.InRectImg->scaleRender(Inven_Explanation.InRect.left, Inven_Explanation.InRect.top,
			Inven_Explanation.sizeX_in, Inven_Explanation.sizeY_in, 0.95f);

	}
}
