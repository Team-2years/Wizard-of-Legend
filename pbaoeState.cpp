#include "stdafx.h"
#include "pbaoeState.h"

state * pbaoeState::inputHandle(player * player)
{
	if ((player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1))
		return new idleState;
	return nullptr;
}

void pbaoeState::enter(player * player)
{
	player->getPlayerData()->time = 0;
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	switch (player->getPlayerData()->stateEnum)
	{
	case STATE_UP_PBAOE:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardPBAoEUp");
		player->getPlayerData()->errorX = -26;
		player->getPlayerData()->errorY = -6;
		break;
	case STATE_DOWN_PBAOE:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardPBAoEDown");
		player->getPlayerData()->errorX = -24;
		player->getPlayerData()->errorY = -4;
		break;
	case STATE_LEFT_PBAOE:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardPBAoELeft");
		player->getPlayerData()->errorX = -24;
		player->getPlayerData()->errorY = -6;
		break;
	case STATE_RIGHT_PBAOE:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardPBAoERight");
		player->getPlayerData()->errorX = -24;
		player->getPlayerData()->errorY = -6;
		break;
	}
}

void pbaoeState::update(player * player)
{
	player->getPlayerData()->time += 1;
	if (player->getPlayerData()->time % 5 == 0)
	{
		if (!(player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1))
			player->getPlayerData()->frameX += 1;
	}
}

void pbaoeState::exit(player * player)
{
}
