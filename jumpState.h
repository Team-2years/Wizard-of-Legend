#pragma once
#include "state.h"
#include "player.h"
class jumpState :
	public state
{
	virtual state* inputHandle(player* player);
	virtual void enter(player* player);
	virtual void update(player* player);
	virtual void exit(player* player);
};

