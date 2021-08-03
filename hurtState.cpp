#include "stdafx.h"
#include "hurtState.h"

state * hurtState::inputHandle(player * player)
{
	if (player->getPlayerData()->time > 10)
		return new idleState;
	return nullptr;
}

void hurtState::enter(player * player)
{
	player->getPlayerData()->time = 0;
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	player->getPlayerData()->hp -= 5;

	switch (player->getPlayerData()->stateEnum)
	{
	case STATE_DOWN_BACKHAND:
	case STATE_DOWN_FOREHAND:
	case STATE_DOWN_GROUNDSLAM:
	case STATE_DOWN_IDLE:
	case STATE_DOWN_KICK:
	case STATE_DOWN_WALK:
	case STATE_DOWN_PBAOE:
		player->getPlayerData()->stateEnum = STATE_DOWN_HURT;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardHurtDown");
		player->getPlayerData()->errorX = -12;
		player->getPlayerData()->errorY = 0;
		break;
	case STATE_UP_BACKHAND:
	case STATE_UP_FOREHAND:
	case STATE_UP_GROUNDSLAM:
	case STATE_UP_IDLE:
	case STATE_UP_KICK:
	case STATE_UP_WALK:
	case STATE_UP_PBAOE:
		player->getPlayerData()->stateEnum = STATE_UP_HURT;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardHurtUp");
		player->getPlayerData()->errorX = -12;
		player->getPlayerData()->errorY = 0;
		break;
	case STATE_LEFT_BACKHAND:
	case STATE_LEFT_FOREHAND:
	case STATE_LEFT_IDLE:
	case STATE_LEFT_KICK:
	case STATE_LEFT_WALK:
	case STATE_LEFT_PBAOE:
		player->getPlayerData()->stateEnum = STATE_LEFT_HURT;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardHurtLeft");
		player->getPlayerData()->errorX = -12;
		player->getPlayerData()->errorY = 0;
		break;
	case STATE_RIGHT_BACKHAND:
	case STATE_RIGHT_FOREHAND:
	case STATE_RIGHT_IDLE:
	case STATE_RIGHT_KICK:
	case STATE_RIGHT_WALK:
	case STATE_RIGHT_PBAOE:
		player->getPlayerData()->stateEnum = STATE_RIGHT_HURT;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardHurtRight");
		player->getPlayerData()->errorX = -10;
		player->getPlayerData()->errorY = 0;
		break;
	default:
		break;
	}
}

void hurtState::update(player * player)
{
	player->getPlayerData()->time++;
}

void hurtState::exit(player * player)
{
}
