#pragma once
#include "gameNode.h"
#include "ItemHeader.h"
#include "singletonBase.h"

#include <unordered_map>


/*
	000XX = 옷
	101XX = 공격형유물
	102XX = 방어형유물
	103XX = 기능형 유물
	20XXX = 아르카나
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

