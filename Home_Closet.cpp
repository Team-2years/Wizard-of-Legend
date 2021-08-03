#include "stdafx.h"
#include "Home_Closet.h"
#include "Inventory.h"

#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

HRESULT Home_Closet::init()
{

	DateBaseManager* _Database;
	


	//65,40
	backGroundImgXY = PointMake(65, 40);
	backGround = IMAGEMANAGER->findDImage("ø ¿Â_BG");






	//ø ¿Â ¡ﬂΩ…¡°
	Center = PointMake(409, 308);
	//229,308
	//409,128
	//π›¡ˆ∏ß 180



	for (int i = 0; i < MAX_CLOTH; i++)
	{
		
		ClothInfo[i] = new tagClothInfo;

		ClothInfo[i]->angle = (PI* 1.5f + PI / 8 * i);
		ClothInfo[i]->backGroundImgXY = PointMake(409 + 180 * cosf(ClothInfo[i]->angle), 308 -180*(-sinf(ClothInfo[i]->angle)));
		ClothInfo[i]->backGroundImage = IMAGEMANAGER->findDImage("ø _BG");		
		ClothInfo[i]->Icon = IMAGEMANAGER->findDImage("ø _¿⁄π∞ºË");

		ClothInfo[i]->Item = nullptr;
		
	}
	
	currentIndex = 0;
	currentRotate = ROTATE_NON;

	RotateCount=0;

	return S_OK;
}

void Home_Closet::release()
{
}

void Home_Closet::update()
{

	if (currentRotate == ROTATE_NON)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			//currentIndex = currentIndex > 0 ? currentIndex - 1 : MAX_CLOTH - 1;
			currentIndex = currentIndex < MAX_CLOTH - 1 ? currentIndex + 1 : 0;
			currentRotate = ROTATE_RIGHT;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{

			//currentIndex = currentIndex < MAX_CLOTH - 1 ? currentIndex + 1 : 0;
			currentIndex = currentIndex > 0 ? currentIndex - 1 : MAX_CLOTH - 1;
			currentRotate = ROTATE_LEFT;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		this->changeCloset(currentIndex);
	}

	switch (currentRotate)
	{
	case ROTATE_LEFT:

		if (RotateCount < 5)
		{
			RotateCount++;

			for (int i = 0; i < MAX_CLOTH; i++)
			{
				float angle = getAngle(Center.x, Center.y, ClothInfo[i]->backGroundImgXY.x, ClothInfo[i]->backGroundImgXY.y) - ANGLE*0.2f;

				ClothInfo[i]->backGroundImgXY.x = 180 * cosf(angle) + Center.x;
				ClothInfo[i]->backGroundImgXY.y = 180 * (-sinf(angle)) + Center.y;
			}
		}
		else
		{
			RotateCount = 0;
			currentRotate = ROTATE_NON;
		}
	
		break;
	case ROTATE_RIGHT:


		if (RotateCount < 5)
		{
			RotateCount++;
			 
			for (int i = 0; i < MAX_CLOTH; i++)
			{
				float angle = getAngle(Center.x, Center.y, ClothInfo[i]->backGroundImgXY.x, ClothInfo[i]->backGroundImgXY.y) + ANGLE * 0.2f;

				ClothInfo[i]->backGroundImgXY.x = 180 * cosf(angle) + Center.x;
				ClothInfo[i]->backGroundImgXY.y = 180 * (-sinf(angle)) + Center.y;
			}
		}
		else
		{
			RotateCount = 0;
			currentRotate = ROTATE_NON;
		}
	

		break;
	case ROTATE_NON:
		break;
	}



	for (int i = 0; i < MAX_CLOTH; i++)
	{
		/*if (i == currentIndex) ClothInfo[i].backGroundImage = IMAGEMANAGER->findDImage("ø _¿⁄π∞ºË");
		else ClothInfo[i].backGroundImage = IMAGEMANAGER->findDImage("ø _BG");
*/
		if (ClothInfo[i]->Item == nullptr)
		{
			ClothInfo[i]->backGroundImage = IMAGEMANAGER->findDImage("ø _¿⁄π∞ºË");
		}
		else
		{
			ClothInfo[i]->backGroundImage = IMAGEMANAGER->findDImage("ø _BG");
			ClothInfo[i]->Icon = ClothInfo[i]->Item->getImage();
		}
	}


	
}

void Home_Closet::render()
{
	backGround->render(backGroundImgXY.x, backGroundImgXY.y);
	
	for (int i = 0; i < MAX_CLOTH; i++)
	{
		/*
		if(i==currentIndex) ClothInfo[i].backGroundImage->sclaeRender_Center(ClothInfo[i].backGroundImgXY.x, ClothInfo[i].backGroundImgXY.y,1.2f,1.2f);
		else ClothInfo[i].backGroundImage->RenderCenter(ClothInfo[i].backGroundImgXY.x, ClothInfo[i].backGroundImgXY.y);
		*/
		
		if (ClothInfo[i]->Item == nullptr)
		{
			if(currentIndex==i) ClothInfo[i]->backGroundImage->sclaeRender_Center(ClothInfo[i]->backGroundImgXY.x, ClothInfo[i]->backGroundImgXY.y, 1.2f, 1.2f);
			else ClothInfo[i]->backGroundImage->RenderCenter(ClothInfo[i]->backGroundImgXY.x, ClothInfo[i]->backGroundImgXY.y);

			
		}
		else
		{
			if (currentIndex == i)
			{
				ClothInfo[i]->backGroundImage->sclaeRender_Center(ClothInfo[i]->backGroundImgXY.x, ClothInfo[i]->backGroundImgXY.y, 1.2f, 1.2f);
				ClothInfo[i]->Icon->sclaeRender_Center(ClothInfo[i]->backGroundImgXY.x-3, ClothInfo[i]->backGroundImgXY.y - 10,1.4f,1.4f);
			}
			else
			{
				ClothInfo[i]->backGroundImage->RenderCenter(ClothInfo[i]->backGroundImgXY.x, ClothInfo[i]->backGroundImgXY.y);
				ClothInfo[i]->Icon->RenderCenter(ClothInfo[i]->backGroundImgXY.x, ClothInfo[i]->backGroundImgXY.y);
			}
		}
		
	}

	cout << "«ˆ¿Á ¿Œµ¶Ω∫ : " << currentIndex << endl;
}

void Home_Closet::changeCloset(int _currentIndex)
{
	if (ClothInfo[_currentIndex]->Item == nullptr) return;
	
	_Inven->changeCloth(ClothInfo[_currentIndex]->Item);	
}
