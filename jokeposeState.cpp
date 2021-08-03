#include "stdafx.h"
#include "jokeposeState.h"

state * jokeposeState::inputHandle(player * player)
{
	if (player->getPlayerData()->time > 30)
		return new idleState;
	return nullptr;
}

void jokeposeState::enter(player * player)
{
	player->getPlayerData()->time = 0;
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	player->getPlayerData()->errorX = -14;
	player->getPlayerData()->errorY = 0;
	player->getPlayerData()->stateEnum = STATE_JOKEPOSE;
	player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardJokePose");
}

void jokeposeState::update(player * player)
{
	player->getPlayerData()->time++;
}

void jokeposeState::exit(player * player)
{
}

