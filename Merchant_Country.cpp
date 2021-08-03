#include "stdafx.h"
#include "Merchant_Country.h"
#include "Home_Arcana.h"
#include "Home_Closet.h"
#include "Home_Lelics.h"

HRESULT Merchant_Country::init()
{
	_DataBase = new DateBaseManager;
	_DataBase->init();



	return S_OK;
}

void Merchant_Country::release()
{
}

void Merchant_Country::update()
{
}

void Merchant_Country::render()
{
}

void Merchant_Country::settingMerchant()
{
	/*
	vector<ItemBasic*> Relics_Merchant;
	vector<ItemBasic*> Arcana_Merchant;
	vector<ItemBasic*> Cloth_Merchant;
	*/

	for(int i=0; i< _DataBase->getItemDataBase().size();i++)
	{
		DateBaseManager* MerchantData;
		MerchantData = _DataBase;

		switch (_DataBase->getItemDataBase()[i]->getItemKind())
		{
		case ARCANA:
			break;
		case RELICS:
			
			

			for (int i = 0; i < MerchantData->getItemDataBase().size(); i++)
			{
				for (int j = 0; j < HomeRelics->getRelics_Drawer(0).Item.size(); i++)
				{
					if (MerchantData->getItemDataBase()[i]->getItemNumber() == HomeRelics->getRelics_Drawer(0).Item[j]->getItemNumber())
					{
						//MerchantData->getItemDataBase().erase(MerchantData->getItemDataBase().begin() + )
					}
				}
			}


			break;
		case CLOTH:
			break;
		}
	}


}

void Merchant_Country::setAddressLinkHome(Home_Arcana * _Arcana, Home_Closet * _Closet, Home_Lelics * _Relics)
{
	HomeArcana = _Arcana;
	HomeRelics = _Relics;
	HomeCloset = _Closet;
}
