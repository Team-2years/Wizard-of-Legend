#pragma once
#include "stdafx.h"
#include "gameNode.h"


class player;

enum ItemKind
{
	ARCANA,	//아르카나
	RELICS,	//유물
	CLOTH	//옷
};

enum tagRelicsType
{
	NOT_RELICS,
	RELICS_ATTACK,
	RELICS_DEFENSE,
	RELICS_OTHER
};


class ItemBasic :
	public gameNode
{
protected:

	int ItemNumber;
	const char* ItemName;
	dImage* IconImage;
	RECT Icon;//아이콘 렉트
	
	float stat;//관여하게 될 스텟관련
	string ItemInfo;//설명관련
	bool isDungeon;//던전에서 얻은건지 아닌지
	bool isGetted; //이미 얻었는지 여부
	ItemKind kind;
	int price_Jewel;
	int price_Gold;

	tagRelicsType RelicsType;//유물타입

public:

	virtual HRESULT init(bool _isDungeon, bool _isGetted)=0;
	virtual void release()=0;
	virtual void update(player* _Player) = 0;
	virtual void render(int x, int y,float sizeX, float sizeY)=0;
 
	virtual int getItemNumber() { return ItemNumber; }
	virtual bool getisDungeon() { return isDungeon; }
	virtual bool getisGetted() { return isGetted; }
	virtual ItemKind getItemKind() { return kind; }
	virtual tagRelicsType getRelicsType() { return RelicsType; }
	virtual RECT getItemRect() { return Icon; }
	virtual dImage* getImage() { return IconImage; }
};

