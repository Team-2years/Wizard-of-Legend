#pragma once
#include "state.h"
#include "player.h"
#include <list>
class walkState :
	public state
{
private:
	list<playerStateEnum> moveListLR;
	list<playerStateEnum> moveListUD;
public:
	virtual state* inputHandle(player* player);
	virtual void enter(player* player);
	virtual void update(player* player);
	virtual void exit(player* player);

	void move(player * player);
};

