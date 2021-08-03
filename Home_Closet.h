#pragma once
#include "stdafx.h"
#include "gameNode.h"
#include "ItemBasic.h"
#include "DateBaseManager.h"


#define MAX_CLOTH 16
#define DISTANCEX 100
#define DISTANCEY 100
#define ANGLE (float)(PI/8)


class Inventory;

enum ClosetRotate
{
	ROTATE_LEFT,
	ROTATE_RIGHT,
	ROTATE_NON
};


struct tagClothInfo
{
	dImage* Icon;
	dImage* backGroundImage;
	ItemBasic* Item;

	POINT backGroundImgXY;


	float scale_X;
	float sclae_Y;
	
	float angle;
};



class Home_Closet :
	public gameNode
{
private:

	DateBaseManager* _Database;


	tagClothInfo* ClothInfo[MAX_CLOTH];
	vector<ItemBasic*> clothInven;

	dImage* backGround;
	POINT backGroundImgXY;


	POINT Center;
	int currentIndex;
	
	int RotateCount;

	ClosetRotate currentRotate;


	Inventory* _Inven;
public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	void getCloth(ItemBasic* _cloth)
	{

		if (_cloth->getItemKind() != CLOTH) return;

		for (int i = 0; i < MAX_CLOTH; i++)
		{
			if (ClothInfo[i]->Item != nullptr) continue;
		
			ClothInfo[i]->Item = _cloth;
			
			break;
		}
	}


	void setAddressLinkInventory(Inventory* inven) { _Inven = inven; }//�ּҰ� �̾��ֱ�
	void changeCloset(int _currentIndex);//�ʹٲٱ�. ���忡�� �κ��丮������ �־��ִ°� 

	//�ش� �ε��� ����
	tagClothInfo* getCloset(int i) { return ClothInfo[i]; }


};

