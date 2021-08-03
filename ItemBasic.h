#pragma once
#include "stdafx.h"
#include "gameNode.h"


class player;

enum ItemKind
{
	ARCANA,	//�Ƹ�ī��
	RELICS,	//����
	CLOTH	//��
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
	RECT Icon;//������ ��Ʈ
	
	float stat;//�����ϰ� �� ���ݰ���
	string ItemInfo;//�������
	bool isDungeon;//�������� �������� �ƴ���
	bool isGetted; //�̹� ������� ����
	ItemKind kind;
	int price_Jewel;
	int price_Gold;

	tagRelicsType RelicsType;//����Ÿ��

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

