#include "stdafx.h"
#include "kickState.h"

state * kickState::inputHandle(player * player)
{
	if ((player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1))
		return new idleState;
	return nullptr;
}

void kickState::enter(player * player)
{
	player->getPlayerData()->time = 0;
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	switch (player->getPlayerData()->stateEnum)
	{
	case STATE_LEFT_KICK:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardKickLeft");
		player->getPlayerData()->errorX = -24;
		player->getPlayerData()->errorY = -8;
		break;
	case STATE_RIGHT_KICK:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardKickRight");
		player->getPlayerData()->errorX = -24;
		player->getPlayerData()->errorY = -8;
		break;
	case STATE_DOWN_KICK:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardKickDown");
		player->getPlayerData()->errorX = -24;
		player->getPlayerData()->errorY = -8;
		break;
	case STATE_UP_KICK:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardKickUp");
		player->getPlayerData()->errorX = -24;
		player->getPlayerData()->errorY = -8;
		break;
	}
}

void kickState::update(player * player)
{
	player->getPlayerData()->time += 1;
	if (player->getPlayerData()->time % 5 == 0)
	{
		if (!(player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1))
			player->getPlayerData()->frameX += 1;
	}
}

void kickState::exit(player * player)
{
}
