#pragma once
#include "gameNode.h"
#include "stdafx.h"
#include "SaveDataManager.h"
#include "DateBaseManager.h"


class Home_Arcana;
class Home_Closet;
class Home_Lelics;



class Merchant_Country :
	public gameNode
{
private:
	
	DateBaseManager* _DataBase;

	vector<ItemBasic*> Relics_Merchant;
	vector<ItemBasic*> Arcana_Merchant;
	vector<ItemBasic*> Cloth_Merchant;

	Home_Arcana* HomeArcana;
	Home_Closet* HomeCloset;
	Home_Lelics* HomeRelics;


public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void settingMerchant();


	vector<ItemBasic*> getRelics_Merchant() { return Relics_Merchant; }
	vector<ItemBasic*> getArcana_Merchant() { return Arcana_Merchant; }
	vector<ItemBasic*> getCloth_Merchant() { return Cloth_Merchant; }

	void setAddressLinkHome(Home_Arcana* _Arcana, Home_Closet* _Closet, Home_Lelics* _Relics);


};

