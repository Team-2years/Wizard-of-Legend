#include "stdafx.h"
#include "walkState.h"
#include "idleState.h"
#include "slideState.h"
#include "dashState.h"
#include "backhandState.h"
#include "forehandState.h"

state * walkState::inputHandle(player * player)
{
	if (moveListUD.empty() && player->getPlayerData()->speed == DASHSPEED)
	{
		if (player->getPlayerData()->stateEnum == STATE_LEFT_WALK) 
		{
			if (KEYMANAGER->isOnceKeyDown('D')) 
			{
				return new slideState;
			}
		}
		else if (player->getPlayerData()->stateEnum == STATE_RIGHT_WALK)
		{
			if (KEYMANAGER->isOnceKeyDown('A'))
			{
				return new slideState;
			}
		}
	}
	if (moveListLR.empty() && moveListUD.empty()) 
	{
		if (player->getPlayerData()->speed == DASHSPEED &&
			(player->getPlayerData()->stateEnum == STATE_LEFT_WALK || player->getPlayerData()->stateEnum == STATE_RIGHT_WALK
				|| player->getPlayerData()->stateEnum == STATE_DOWN_WALK
				|| player->getPlayerData()->stateEnum == STATE_UP_WALK))
		{
			return new slideState;
		}
		else
		return new idleState;
	}
	if (KEYMANAGER->isStayKeyDown(VK_SPACE) && player->getPlayerData()->dashCount <= 0)
	{
		if (!moveListLR.empty() && !moveListUD.empty())
		{
			if (moveListLR.back() == STATE_LEFT_WALK && moveListUD.back() == STATE_UP_WALK)
			{
				player->getPlayerData()->stateEnum = STATE_LEFTUP_DASH;
			}
			else if (moveListLR.back() == STATE_LEFT_WALK && moveListUD.back() == STATE_DOWN_WALK)
			{
				player->getPlayerData()->stateEnum = STATE_LEFTDOWN_DASH;
			}
			else if (moveListLR.back() == STATE_RIGHT_WALK && moveListUD.back() == STATE_UP_WALK)
			{
				player->getPlayerData()->stateEnum = STATE_RIGHTUP_DASH;
			}
			else if (moveListLR.back() == STATE_RIGHT_WALK && moveListUD.back() == STATE_DOWN_WALK)
			{
				player->getPlayerData()->stateEnum = STATE_RIGHTDOWN_DASH;
			}
		}
		return new dashState;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		if (player->getPlayerData()->atkHand)
		{
			return new backhandState;
		}
		else
		{
			return new forehandState;
		}
	}
	return nullptr;
}

void walkState::enter(player * player)
{
	moveListLR.clear();
	moveListUD.clear();
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	player->getPlayerData()->errorX = -24;
	player->getPlayerData()->errorY = -4;
	player->getPlayerData()->speed = SPEED;
	player->getPlayerData()->time = 0;
	switch (player->getPlayerData()->stateEnum)
	{
	case STATE_LEFT_WALK:
	case STATE_RIGHT_SLIDE:

		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardRunLeft");
		moveListLR.push_back(STATE_LEFT_WALK);
		break;
	case STATE_RIGHT_WALK:
	case STATE_LEFT_SLIDE:

		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardRunRight");
		moveListLR.push_back(STATE_RIGHT_WALK);

		break;
	case STATE_UP_WALK:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardRunUp");
		moveListUD.push_back(STATE_UP_WALK);
		break;
	case STATE_DOWN_WALK:
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardRunDown");
		moveListUD.push_back(STATE_DOWN_WALK);
		break;
	default:
		break;
	}
}

void walkState::update(player * player)
{
	move(player);
	player->getPlayerData()->time += 1;
	if (player->getPlayerData()->time % 5 == 0) 
	{
		if (player->getPlayerData()->frameX > player->getPlayerData()->image->getMaxFrameX()-1)
			player->getPlayerData()->frameX = 0;
		else
			player->getPlayerData()->frameX += 1;
	}
	if (player->getPlayerData()->time > 40) 
	{
		player->getPlayerData()->speed = DASHSPEED;
	}
}

void walkState::exit(player * player)
{
}

void walkState::move(player * player)
{
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		moveListLR.push_back(STATE_LEFT_WALK);
		player->getPlayerData()->stateEnum = STATE_LEFT_WALK;
	}
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		moveListLR.remove(STATE_LEFT_WALK);
	}
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		moveListLR.push_back(STATE_RIGHT_WALK);
		player->getPlayerData()->stateEnum = STATE_RIGHT_WALK;
	}
	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		moveListLR.remove(STATE_RIGHT_WALK);

	}
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		moveListUD.push_back(STATE_DOWN_WALK);
		player->getPlayerData()->stateEnum = STATE_DOWN_WALK;
	}
	if (KEYMANAGER->isOnceKeyUp('S'))
	{
		moveListUD.remove(STATE_DOWN_WALK);

	}
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		moveListUD.push_back(STATE_UP_WALK);
		player->getPlayerData()->stateEnum = STATE_UP_WALK;
	}
	if (KEYMANAGER->isOnceKeyUp('W'))
	{
		moveListUD.remove(STATE_UP_WALK);
	}

	
	if (!moveListUD.empty() && !moveListLR.empty()) 
	{
		if (player->getPlayerData()->time > 40)
			player->getPlayerData()->speed = DASHSPEED * 0.75;
		else
			player->getPlayerData()->speed = SPEED * 0.75;
	}
	else 
	{
		if (player->getPlayerData()->time > 40)
			player->getPlayerData()->speed = DASHSPEED;
		else
			player->getPlayerData()->speed = SPEED;
	}
	if (!moveListUD.empty())
	{
		switch (moveListUD.back())
		{
		case STATE_UP_WALK:
			player->getPlayerData()->y -= player->getPlayerData()->speed;
			player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardRunUp");

			break;

		case STATE_DOWN_WALK:
			player->getPlayerData()->y += player->getPlayerData()->speed;
			player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardRunDown");

			break;
		}
		if (moveListLR.empty())
		{
			player->getPlayerData()->stateEnum = moveListUD.back();
		}
	}
	if (!moveListLR.empty())
	{
		switch (moveListLR.back())
		{
		case STATE_LEFT_WALK:
			player->getPlayerData()->x -= player->getPlayerData()->speed;
			player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardRunLeft");
			break;

		case STATE_RIGHT_WALK:
			player->getPlayerData()->x += player->getPlayerData()->speed;
			player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardRunRight");
			break;
		}
		if (moveListUD.empty())
		{
			player->getPlayerData()->stateEnum = moveListLR.back();
		}
	}
}
