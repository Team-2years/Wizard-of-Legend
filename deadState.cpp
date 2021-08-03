#include "stdafx.h"
#include "deadState.h"
#include "getupState.h"
state * deadState::inputHandle(player * player)
{
	if (KEYMANAGER->isOnceKeyDown('R')) 
	{
		return new getupState;
	}
	return nullptr;
}

void deadState::enter(player * player)
{
	player->getPlayerData()->time = 0;
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	player->getPlayerData()->errorX = -18;
	player->getPlayerData()->errorY = -8;
	player->getPlayerData()->stateEnum = STATE_DEAD;
	player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardDeadDown1");
}

void deadState::update(player * player)
{
	player->getPlayerData()->time += 1;
	if (player->getPlayerData()->time % 9 == 0)
	{
		if ((player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1)) 
		{
			player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardDeadDown");
			player->getPlayerData()->errorX = -16;
			player->getPlayerData()->errorY = 14;
		}
		else
			player->getPlayerData()->frameX += 1;
	}
}

void deadState::exit(player * player)
{
}
