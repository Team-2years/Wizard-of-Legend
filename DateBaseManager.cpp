#include "stdafx.h"
#include "gameNode.h"
#include "DateBaseManager.h"
#include "ItemHeader.h"


HRESULT DateBaseManager::init()
{
	ItemBasic* newItem = new Gaia_Shovel;
	newItem->init(false, false);
	ItemDataBase.insert(make_pair(newItem->getItemNumber(), newItem));
	
	ItemBasic* newItem1 = new Iflits_MatchStick;	
	newItem1->init(false, false);
	ItemDataBase.insert(make_pair(newItem1->getItemNumber(), newItem1));

	ItemBasic* newItem2 = new Taranis_Battery;
	newItem2->init(false, false);
	ItemDataBase.insert(make_pair(newItem2->getItemNumber(), newItem2));

	ItemBasic* newItem3 = new Siva_waterbottle;
	newItem3->init(false, false);
	ItemDataBase.insert(make_pair(newItem3->getItemNumber(), newItem3));

	ItemBasic* newItem4 = new Rudra_Vane;
	newItem4->init(false, false);
	ItemDataBase.insert(make_pair(newItem4->getItemNumber(), newItem4));

	ItemBasic* newItem50001 = new WizardCloth_Red;
	newItem50001->init(false,false);
	ItemDataBase.insert(make_pair(newItem50001->getItemNumber(), newItem50001));

	ItemBasic* newItem50002 = new WizardCloth_Blue;
	newItem50002->init(false,false);
	ItemDataBase.insert(make_pair(newItem50002->getItemNumber(), newItem50002));

	ItemBasic* newItem50003 = new WizardCloth_Yellow;
	newItem50003->init(false,false);
	ItemDataBase.insert(make_pair(newItem50003->getItemNumber(), newItem50003));

	ItemBasic* newItem50004 = new WizardCloth_Green;
	newItem50004->init(false,false);
	ItemDataBase.insert(make_pair(newItem50004->getItemNumber(), newItem50004));



	return S_OK;
}

void DateBaseManager::release()
{
}

void DateBaseManager::update()
{
}

void DateBaseManager::render()
{
}

ItemBasic * DateBaseManager::findItem(int itemNum)
{
	
	return ItemDataBase.find(itemNum)->second;
}
