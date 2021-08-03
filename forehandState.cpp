#include "stdafx.h"
#include "forehandState.h"

state * forehandState::inputHandle(player * player)
{
	if ((player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1))
		return new idleState;
	return nullptr;
}

void forehandState::enter(player * player)
{
	player->getPlayerData()->time = 0;
	player->getPlayerData()->atkHand = true;
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	switch (player->getPlayerData()->stateEnum)
	{
	case STATE_UP_FOREHAND:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardForehandUp");
		player->getPlayerData()->errorX = -24;
		player->getPlayerData()->errorY = -8;
		break;
	case STATE_DOWN_FOREHAND:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardForehandDown");
		player->getPlayerData()->errorX = -22;
		player->getPlayerData()->errorY = -8;
		break;
	case STATE_LEFT_FOREHAND:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardForehandLeft");
		player->getPlayerData()->errorX = -18;
		player->getPlayerData()->errorY = 0;
		break;
	case STATE_RIGHT_FOREHAND:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardForehandRight");
		player->getPlayerData()->errorX = -20;
		player->getPlayerData()->errorY = 0;
		break;
	}
}

void forehandState::update(player * player)
{
	player->getPlayerData()->time += 1;
	if (player->getPlayerData()->time % 5 == 0)
	{
		if (!(player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1))
			player->getPlayerData()->frameX += 1;
	}
}

void forehandState::exit(player * player)
{
}
