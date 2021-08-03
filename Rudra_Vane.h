#pragma once
#include "ItemBasic.h"
class Rudra_Vane :
	public ItemBasic
{
private:

public:

	virtual HRESULT init(bool _isDungeon, bool _isGetted);
	virtual void release();
	virtual void update(player* _Player);
	virtual void render(int x, int y, float sizeX, float sizeY);

};

