#include "stdafx.h"
#include "getupState.h"

state * getupState::inputHandle(player * player)
{
	if (player->getPlayerData()->time > 30)
	return new idleState;
	return nullptr;
}

void getupState::enter(player * player)
{
	player->getPlayerData()->time = 0;
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	player->getPlayerData()->errorX = -14;
	player->getPlayerData()->errorY = 0;
	player->getPlayerData()->stateEnum = STATE_GETUP;
	player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardGetUp");
}

void getupState::update(player * player)
{
	player->getPlayerData()->time += 1;
	if (player->getPlayerData()->time % 10 == 0)
	{
		if (!(player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1))
		{
			player->getPlayerData()->frameX += 1;
		}
	}
}

void getupState::exit(player * player)
{
}
