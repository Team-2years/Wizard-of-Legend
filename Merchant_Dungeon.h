#pragma once
#include "gameNode.h"
#include "stdafx.h"
#include "SaveDataManager.h"


class Merchant_Dungeon :
	public gameNode
{
private:



public:


	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

