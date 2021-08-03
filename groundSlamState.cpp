#include "stdafx.h"
#include "groundSlamState.h"

state * groundSlamState::inputHandle(player * player)
{
	if ((player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1))
		return new idleState;
	return nullptr;
}

void groundSlamState::enter(player * player)
{
	player->getPlayerData()->time = 0;
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	switch (player->getPlayerData()->stateEnum)
	{
	case STATE_DOWN_GROUNDSLAM:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardGroundSlamDown");
		player->getPlayerData()->errorX = -24;
		player->getPlayerData()->errorY = -4;
		break;
	case STATE_UP_GROUNDSLAM:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardGroundSlamUp");
		player->getPlayerData()->errorX = -24;
		player->getPlayerData()->errorY = -4;
		break;
	default:
		
		break;
	}
}

void groundSlamState::update(player * player)
{
	player->getPlayerData()->time += 1;
	if (player->getPlayerData()->time % 5 == 0)
	{
		if (!(player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1))
			player->getPlayerData()->frameX += 1;
	}
}

void groundSlamState::exit(player * player)
{
}
