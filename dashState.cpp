#include "stdafx.h"
#include "dashState.h"

state * dashState::inputHandle(player * player)
{
	if (player->getPlayerData()->time > 15)
		return new idleState;
	return nullptr;
}

void dashState::enter(player * player)
{
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	player->getPlayerData()->dashCount = 60;
	player->getPlayerData()->time = 0;
	player->getPlayerData()->speed = 15;
	switch (player->getPlayerData()->stateEnum)
	{
	case STATE_LEFT_IDLE:
	case STATE_LEFT_WALK:
		player->getPlayerData()->stateEnum = STATE_LEFT_DASH;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardDashLeft");
		player->getPlayerData()->errorX = -20;
		player->getPlayerData()->errorY = 0;
		break;
	case STATE_RIGHT_IDLE:
	case STATE_RIGHT_WALK:
		player->getPlayerData()->stateEnum = STATE_RIGHT_DASH;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardDashRight");
		player->getPlayerData()->errorX = -24;
		player->getPlayerData()->errorY = 0;
		break;

	case STATE_UP_IDLE:
	case STATE_UP_WALK:
		player->getPlayerData()->stateEnum = STATE_UP_DASH;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardDashUp");
		player->getPlayerData()->errorX = -16;
		player->getPlayerData()->errorY = 0;
		break;

	case STATE_DOWN_IDLE:
	case STATE_DOWN_WALK:
		player->getPlayerData()->stateEnum = STATE_DOWN_DASH;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardDashDown");
		player->getPlayerData()->errorX = -14;
		player->getPlayerData()->errorY = 0;
		break;
	case STATE_LEFTUP_DASH:
	case STATE_LEFTDOWN_DASH:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardDashLeft");
		player->getPlayerData()->errorX = -20;
		player->getPlayerData()->errorY = 0;
		break;
	case STATE_RIGHTUP_DASH:
	case STATE_RIGHTDOWN_DASH:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardDashRight");
		player->getPlayerData()->errorX = -24;
		player->getPlayerData()->errorY = 0;
		break;
	default:
		break;
	}
}

void dashState::update(player * player)
{
	if(player->getPlayerData()->time % 3 == 0)
	SKILLMANAGER->fire(7, player->getPlayerData()->x, player->getPlayerData()->y, 0, true);
	player->getPlayerData()->time++;
	switch (player->getPlayerData()->stateEnum)
	{
	case STATE_LEFT_DASH:
		player->getPlayerData()->x -= player->getPlayerData()->speed;
		if (player->getPlayerData()->time % 5 == 0)
		{
			if (player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1)
				player->getPlayerData()->frameX = 0;
			else
				player->getPlayerData()->frameX += 1;
		}
		break;
	case STATE_RIGHT_DASH:
		player->getPlayerData()->x += player->getPlayerData()->speed;
		if (player->getPlayerData()->time % 5 == 0)
		{
			if (player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1)
				player->getPlayerData()->frameX = 0;
			else
				player->getPlayerData()->frameX += 1;
		}
		break;
	case STATE_UP_DASH:
		player->getPlayerData()->y -= player->getPlayerData()->speed;
		break;
	case STATE_DOWN_DASH:
		player->getPlayerData()->y += player->getPlayerData()->speed;
		break;
	case STATE_LEFTUP_DASH:
		player->getPlayerData()->x -= player->getPlayerData()->speed * 0.75;
		player->getPlayerData()->y -= player->getPlayerData()->speed * 0.75;
		break;
	case STATE_LEFTDOWN_DASH:
		player->getPlayerData()->x -= player->getPlayerData()->speed * 0.75;
		player->getPlayerData()->y += player->getPlayerData()->speed * 0.75;
		break;
	case STATE_RIGHTUP_DASH:
		player->getPlayerData()->x += player->getPlayerData()->speed * 0.75;
		player->getPlayerData()->y -= player->getPlayerData()->speed * 0.75;
		break;
	case STATE_RIGHTDOWN_DASH:
		player->getPlayerData()->x += player->getPlayerData()->speed * 0.75;
		player->getPlayerData()->y += player->getPlayerData()->speed * 0.75;
		break;
	default:
		break;
	}
}

void dashState::exit(player * player)
{
}
