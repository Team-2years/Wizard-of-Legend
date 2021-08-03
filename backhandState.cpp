#include "stdafx.h"
#include "backhandState.h"

state * backhandState::inputHandle(player * player)
{
	if ((player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1))
		return new idleState;
	return nullptr;
}

void backhandState::enter(player * player)
{
	player->getPlayerData()->time = 0;
	player->getPlayerData()->atkHand = false;
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	switch (player->getPlayerData()->stateEnum)
	{
	case STATE_UP_BACKHAND:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardBackhandUp");
		player->getPlayerData()->errorX = -26;
		player->getPlayerData()->errorY = -8;
		break;
	case STATE_DOWN_BACKHAND:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardBackhandDown");
		player->getPlayerData()->errorX = -22;
		player->getPlayerData()->errorY = -8;
		break;
	case STATE_LEFT_BACKHAND:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardBackhandLeft");
		player->getPlayerData()->errorX = -18;
		player->getPlayerData()->errorY = -4;
		break;
	case STATE_RIGHT_BACKHAND:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardBackhandRight");
		player->getPlayerData()->errorX = -20;
		player->getPlayerData()->errorY = -4;
		break;
	}
}

void backhandState::update(player * player)
{
	player->getPlayerData()->time += 1;
	if (player->getPlayerData()->time % 5 == 0)
	{
		if (!(player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1))
			player->getPlayerData()->frameX += 1;
	}
}

void backhandState::exit(player * player)
{
}
