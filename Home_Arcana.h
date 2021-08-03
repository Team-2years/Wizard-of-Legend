#pragma once
#include "stdafx.h"
#include "gameNode.h"
#include "ItemBasic.h"
#include "SaveDataManager.h"

#define ELEMENT_MIN 0
#define ELEMENT_MAX 5

enum Element
{
	FIRE,
	WIND,
	EARTH,
	THUNDER,
	WATER
};

enum ArcanaKind
{
	Arcana_Kind_Basic,
	Arcana_Kind_Movement,
	Arcana_Kind_Standard,
	Arcana_Kind_Signiture
};

struct tagArcanaElement
{
	int index;
	

	vector<ItemBasic*> Arcana;
	dImage* ArcanaBookElementImg;
	dImage* ArcanaBookElementIconImg;
	dImage* ArcanaBookTabImage;
	dImage* ArcanaBookLogoImage;


	
	


	int count;

};


struct tagArcana
{
	dImage* firstCardImg;//��ó�� â ī�� �̹���
	POINT firstCard_xy; //�̹��� ���� xy��ǥ
	bool isSelect_firstCard;//�������ΰ���
	ArcanaKind Kind;




	dImage* ArcanaBookImg;
	dImage* ArcanaBookLogo;
	
	tagArcanaElement ArcanaList[5];

	Element ArcanaElements;
	bool isOpenSpellBook;

};

struct tagCard
{
	POINT ArcanaStartPosition;
	POINT ArcanaCurrentPosition;
	POINT ArcanaEndPosition;
	dImage* ArcanaCardImage;
	bool isPickUpCard;
	bool isDrop;
};


class Home_Arcana :
	public gameNode
{
private:

	tagArcana HomeUI_Arcana[4];


	RECT first;

	POINT PanelPoint;
	POINT SpellBookPoint;


	int currentArcanaIndex;
	int currentArcanaElement;
	Element currentElementIndex;


	int CardCount;

	tagCard currentCard;
	POINT moveSpeed;



public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	
	
};

