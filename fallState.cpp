#include "stdafx.h"
#include "fallState.h"

state * fallState::inputHandle(player * player)
{
	if (player->getPlayerData()->z > 70) 
	{
		player->getPlayerData()->z = 0;
		return new idleState;

	}
	return nullptr;
}

void fallState::enter(player * player)
{
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	player->getPlayerData()->time = 0;
	player->getPlayerData()->speed = SPEED;
	switch (player->getPlayerData()->stateEnum)
	{
	case STATE_LEFT_WALK:
	case STATE_LEFT_DASH:
	case STATE_LEFTDOWN_DASH:
	case STATE_LEFTUP_DASH:
	case STATE_LEFT_IDLE:
		player->getPlayerData()->errorX = -15;
		player->getPlayerData()->errorY = 0;
		player->getPlayerData()->stateEnum = STATE_LEFT_FALL;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardFallLeft");
		break;
	case STATE_RIGHT_WALK:
	case STATE_RIGHT_DASH:
	case STATE_RIGHTDOWN_DASH:
	case STATE_RIGHTUP_DASH:
	case STATE_RIGHT_IDLE:
		player->getPlayerData()->errorX = -17;
		player->getPlayerData()->errorY = 0;
		player->getPlayerData()->stateEnum = STATE_RIGHT_FALL;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardFallRight");
		break;
	case STATE_UP_WALK:
	case STATE_UP_DASH:
	case STATE_UP_IDLE:
		player->getPlayerData()->errorX = -15;
		player->getPlayerData()->errorY = -3;
		player->getPlayerData()->stateEnum = STATE_UP_FALL;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardFallUp");
		break;
	case STATE_DOWN_WALK:
	case STATE_DOWN_DASH:
	case STATE_DOWN_IDLE:
		player->getPlayerData()->errorX = -15;
		player->getPlayerData()->errorY = -2;
		player->getPlayerData()->stateEnum = STATE_DOWN_FALL;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardFallDown");
		break;
	default:
		break;
	}
}

void fallState::update(player * player)
{
	player->getPlayerData()->time++;
	switch (player->getPlayerData()->stateEnum)
	{
	case STATE_LEFT_FALL:
		player->getPlayerData()->z += player->getPlayerData()->speed;
		if (player->getPlayerData()->time % 5 == 0)
		{
			if (player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1)
				player->getPlayerData()->frameX = 0;
			else
				player->getPlayerData()->frameX += 1;
		}
		break;
	case STATE_RIGHT_FALL:
		player->getPlayerData()->z += player->getPlayerData()->speed;
		if (player->getPlayerData()->time % 5 == 0)
		{
			if (player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1)
				player->getPlayerData()->frameX = 0;
			else
				player->getPlayerData()->frameX += 1;
		}
		break;
	case STATE_UP_FALL:
		player->getPlayerData()->z += player->getPlayerData()->speed;
		break;
	case STATE_DOWN_FALL:
		player->getPlayerData()->z += player->getPlayerData()->speed;
		break;
	default:
		break;
	}
}

void fallState::exit(player * player)
{
}
