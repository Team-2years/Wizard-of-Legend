#pragma once
#include "gameNode.h"
#include "ItemHeader.h"
#include "singletonBase.h"

#include <unordered_map>


/*
	000XX = ��
	101XX = ����������
	102XX = ���������
	103XX = ����� ����
	20XXX = �Ƹ�ī��
*/

class DateBaseManager : gameNode

{
private:

	unordered_map<int, ItemBasic*> ItemDataBase;
	unordered_map<int, ItemBasic*>::iterator iter_ItemDataBase;

public:

	unordered_map<int, ItemBasic*> getItemDataBase() { return ItemDataBase; }


	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	ItemBasic* findItem(int itemNum);


};

