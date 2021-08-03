#include "stdafx.h"
#include "slideState.h"
#include "walkState.h"
state * slideState::inputHandle(player * player)
{
	if (player->getPlayerData()->speed <= 0) 
	{
		switch (player->getPlayerData()->stateEnum)
		{
		case STATE_LEFT_SLIDE:		
			return new idleState;
			break;
		case STATE_RIGHT_SLIDE:
			return new idleState;
			break;
		case STATE_DOWN_SLIDE:
			return new idleState;
			break;
		case STATE_UP_SLIDE:
			return new idleState;
			break;
		default:
			break;
		}
	}
	return nullptr;
}

void slideState::enter(player * player)
{
	player->getPlayerData()->errorX = -24;
	player->getPlayerData()->errorY = -4;
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	player->getPlayerData()->time = 0;
	switch (player->getPlayerData()->stateEnum)
	{
	case STATE_LEFT_WALK:
		player->getPlayerData()->stateEnum = STATE_LEFT_SLIDE;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardSlideLeft");
		break;
	case STATE_RIGHT_WALK:
		player->getPlayerData()->stateEnum = STATE_RIGHT_SLIDE;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardSlideRight");
		break;
	case STATE_DOWN_WALK:
		player->getPlayerData()->errorX = -14;
		player->getPlayerData()->stateEnum = STATE_DOWN_SLIDE;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("SlideDown");
		break;
	case STATE_UP_WALK:
		player->getPlayerData()->errorX = -18;
		player->getPlayerData()->stateEnum = STATE_UP_SLIDE;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("SlideUp");
		break;
	default:
		break;
	}
}

void slideState::update(player * player)
{
	player->getPlayerData()->time++;
	if (player->getPlayerData()->time%3 == 0)
	{
		if (!(player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX() - 1))
			player->getPlayerData()->frameX += 1;
		player->getPlayerData()->speed -= 1;
	}
	switch (player->getPlayerData()->stateEnum)
	{
	case STATE_LEFT_SLIDE:
		player->getPlayerData()->x -= player->getPlayerData()->speed;
		break;
	case STATE_RIGHT_SLIDE:
		player->getPlayerData()->x += player->getPlayerData()->speed;
		break;
	case STATE_DOWN_SLIDE:
		player->getPlayerData()->y += player->getPlayerData()->speed;
		break;
	case STATE_UP_SLIDE:
		player->getPlayerData()->y -= player->getPlayerData()->speed;
		break;
	default:
		break;
	}
}

void slideState::exit(player * player)
{
}
