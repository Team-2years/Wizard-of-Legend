#include "stdafx.h"
#include "jumpState.h"

state * jumpState::inputHandle(player * player)
{
	if (player->getPlayerData()->time > 10)
		return new idleState;
	return nullptr;
}

void jumpState::enter(player * player)
{
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	player->getPlayerData()->time = 0;
	player->getPlayerData()->speed = 4;
	player->getPlayerData()->gravity = 0.05;
	player->getPlayerData()->sumg = 0;
	player->getPlayerData()->jumpPower = 10;
	switch (player->getPlayerData()->stateEnum)
	{
	case STATE_DOWN_JUMP:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardJumpDown1");
		player->getPlayerData()->errorX = -12;
		player->getPlayerData()->errorY = 0;
		break;
	case STATE_UP_JUMP:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardJumpUp1");
		player->getPlayerData()->errorX = -12;
		player->getPlayerData()->errorY = 0;
		break;
	case STATE_LEFT_JUMP:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardJumpLeft0Alt");
		player->getPlayerData()->errorX = -12;
		player->getPlayerData()->errorY = 0;
		break;
	case STATE_RIGHT_JUMP:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardJumpRight0Alt");
		player->getPlayerData()->errorX = -8;
		player->getPlayerData()->errorY = 0;
		break;
	}
}

void jumpState::update(player * player)
{
	if (!(player->getPlayerData()->z + player->getPlayerData()->sumg - player->getPlayerData()->jumpPower > 0))
	{
		player->getPlayerData()->sumg += player->getPlayerData()->gravity * 10;
		player->getPlayerData()->z += player->getPlayerData()->sumg - player->getPlayerData()->jumpPower;
		player->getPlayerData()->x += cosf(player->getPlayerData()->angle) * player->getPlayerData()->speed;
		player->getPlayerData()->y += -sinf(player->getPlayerData()->angle)* player->getPlayerData()->speed;
	}
	else 
	{
		if (player->getPlayerData()->angle > PI) 
		{
			player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardJumpDown0");
			player->getPlayerData()->errorX = -16;
			player->getPlayerData()->errorY = 0;
		}
		else 
		{
			player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardJumpUp0");
			player->getPlayerData()->errorX = -16;
			player->getPlayerData()->errorY = 0;
		}
		player->getPlayerData()->z = 0;
		player->getPlayerData()->time++;
	}
}

void jumpState::exit(player * player)
{
}
