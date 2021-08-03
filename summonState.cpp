#include "stdafx.h"
#include "summonState.h"

state * summonState::inputHandle(player * player)
{
	if (player->getPlayerData()->time > 30)
		return new idleState;
	return nullptr;
}

void summonState::enter(player * player)
{
	player->getPlayerData()->time = 0;
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	player->getPlayerData()->errorX = -14;
	player->getPlayerData()->errorY = 0;
	player->getPlayerData()->stateEnum = STATE_SUMMON;
	player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardSummonDown");
}

void summonState::update(player * player)
{
	player->getPlayerData()->time++;
}

void summonState::exit(player * player)
{
}
