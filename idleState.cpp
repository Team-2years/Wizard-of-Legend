#include "stdafx.h"

#include "idleState.h"
#include "walkState.h"
#include "dashState.h"
#include "backhandState.h"
#include "forehandState.h"
#include "deadState.h"
#include "fallState.h"
#include "groundSlamState.h"
#include "pbaoeState.h"
#include "kickState.h"
#include "hurtState.h"
#include "jokeposeState.h"
#include "summonState.h"
#include "jumpState.h"

#include "player.h"
state* idleState::inputHandle(player* player)
{
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		if (player->getPlayerData()->moveCommandInput == 0)
		{
			player->getPlayerData()->stateEnum = STATE_LEFT_WALK;
			return new walkState;
		}
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		if (player->getPlayerData()->moveCommandInput == 0)
		{
			player->getPlayerData()->stateEnum = STATE_RIGHT_WALK;
			return new walkState;
		}
	}
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		if (player->getPlayerData()->moveCommandInput == 0)
		{
			player->getPlayerData()->stateEnum = STATE_UP_WALK;
			return new walkState;
		}
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		if (player->getPlayerData()->moveCommandInput == 0)
		{
			player->getPlayerData()->stateEnum = STATE_DOWN_WALK;
			return new walkState;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_SPACE) && player->getPlayerData()->dashCount <= 0) 
	{
		return new dashState;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON)) 
	{
		float angle = getAngle(player->getPlayerData()->x, player->getPlayerData()->y, _ptMouse.x, _ptMouse.y);
		SKILLMANAGER->fire(0, player->getPlayerData()->x, player->getPlayerData()->y + 4, angle*180/PI, true);
		if (player->getPlayerData()->atkHand) 
		{
			if (angle > PI*0.25 && angle < PI*0.75)
				player->getPlayerData()->stateEnum = STATE_UP_BACKHAND;
			else if (angle > PI*0.75 && angle < PI*1.25)
				player->getPlayerData()->stateEnum = STATE_LEFT_BACKHAND;
			else if (angle > PI*1.25 && angle < PI*1.75)
				player->getPlayerData()->stateEnum = STATE_DOWN_BACKHAND;
			else 
				player->getPlayerData()->stateEnum = STATE_RIGHT_BACKHAND;
			return new backhandState;
		}
		else 
		{
			if (angle > PI*0.25 && angle < PI*0.75)
				player->getPlayerData()->stateEnum = STATE_UP_FOREHAND;
			else if (angle > PI*0.75 && angle < PI*1.25)
				player->getPlayerData()->stateEnum = STATE_LEFT_FOREHAND;
			else if (angle > PI*1.25 && angle < PI*1.75)
				player->getPlayerData()->stateEnum = STATE_DOWN_FOREHAND;
			else
				player->getPlayerData()->stateEnum = STATE_RIGHT_FOREHAND;
			return new forehandState;
		}

	}
	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
	{
		float angle = getAngle(player->getPlayerData()->x, player->getPlayerData()->y, _ptMouse.x, _ptMouse.y);
		if (angle > 0 && angle < PI)
			player->getPlayerData()->stateEnum = STATE_UP_GROUNDSLAM;
		else
			player->getPlayerData()->stateEnum = STATE_DOWN_GROUNDSLAM;
		SKILLMANAGER->fire(4, player->getPlayerData()->x, player->getPlayerData()->y + 12, 0, true);
		return new groundSlamState;
	}
	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		float angle = getAngle(player->getPlayerData()->x, player->getPlayerData()->y, _ptMouse.x, _ptMouse.y);
		SKILLMANAGER->fire(1, player->getPlayerData()->x, player->getPlayerData()->y + 12, angle * 180 / PI, true);
		if (player->getPlayerData()->atkHand)
		{
			if (angle > PI*0.25 && angle < PI*0.75)
				player->getPlayerData()->stateEnum = STATE_UP_BACKHAND;
			else if (angle > PI*0.75 && angle < PI*1.25)
				player->getPlayerData()->stateEnum = STATE_LEFT_BACKHAND;
			else if (angle > PI*1.25 && angle < PI*1.75)
				player->getPlayerData()->stateEnum = STATE_DOWN_BACKHAND;
			else
				player->getPlayerData()->stateEnum = STATE_RIGHT_BACKHAND;
			return new backhandState;
		}
		else
		{
			if (angle > PI*0.25 && angle < PI*0.75)
				player->getPlayerData()->stateEnum = STATE_UP_FOREHAND;
			else if (angle > PI*0.75 && angle < PI*1.25)
				player->getPlayerData()->stateEnum = STATE_LEFT_FOREHAND;
			else if (angle > PI*1.25 && angle < PI*1.75)
				player->getPlayerData()->stateEnum = STATE_DOWN_FOREHAND;
			else
				player->getPlayerData()->stateEnum = STATE_RIGHT_FOREHAND;
			return new forehandState;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		return new fallState;
	}
	if (KEYMANAGER->isOnceKeyDown('G'))
	{
		float angle = getAngle(player->getPlayerData()->x, player->getPlayerData()->y, _ptMouse.x, _ptMouse.y);
		if (angle > 0 && angle < PI)
			player->getPlayerData()->stateEnum = STATE_UP_GROUNDSLAM;
		else
			player->getPlayerData()->stateEnum = STATE_DOWN_GROUNDSLAM;

		return new groundSlamState;
	}
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		float angle = getAngle(player->getPlayerData()->x, player->getPlayerData()->y, _ptMouse.x, _ptMouse.y);
		if (angle > PI*0.25 && angle < PI*0.75)
			player->getPlayerData()->stateEnum = STATE_UP_PBAOE;
		else if (angle > PI*0.75 && angle < PI*1.25)
			player->getPlayerData()->stateEnum = STATE_LEFT_PBAOE;
		else if (angle > PI*1.25 && angle < PI*1.75)
			player->getPlayerData()->stateEnum = STATE_DOWN_PBAOE;
		else
			player->getPlayerData()->stateEnum = STATE_RIGHT_PBAOE;
		return new pbaoeState;
	}
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{

		float angle = getAngle(player->getPlayerData()->x, player->getPlayerData()->y, _ptMouse.x, _ptMouse.y);
		SKILLMANAGER->fire(6, player->getPlayerData()->x, player->getPlayerData()->y + 6, angle * 180 / PI, true);

		if (angle > PI*0.25 && angle < PI*0.75)
			player->getPlayerData()->stateEnum = STATE_UP_KICK;
		else if (angle > PI*0.75 && angle < PI*1.25)
			player->getPlayerData()->stateEnum = STATE_LEFT_KICK;
		else if (angle > PI*1.25 && angle < PI*1.75)
			player->getPlayerData()->stateEnum = STATE_DOWN_KICK;
		else
			player->getPlayerData()->stateEnum = STATE_RIGHT_KICK;
		return new kickState;
	}	
	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		float angle = getAngle(player->getPlayerData()->x, player->getPlayerData()->y, _ptMouse.x, _ptMouse.y);
		SKILLMANAGER->fire(8, player->getPlayerData()->x, player->getPlayerData()->y + 6, angle * 180 / PI, true);
		if (angle > PI*0.25 && angle < PI*0.75)
			player->getPlayerData()->stateEnum = STATE_UP_PBAOE;
		else if (angle > PI*0.75 && angle < PI*1.25)
			player->getPlayerData()->stateEnum = STATE_LEFT_PBAOE;
		else if (angle > PI*1.25 && angle < PI*1.75)
			player->getPlayerData()->stateEnum = STATE_DOWN_PBAOE;
		else
			player->getPlayerData()->stateEnum = STATE_RIGHT_PBAOE;
		return new pbaoeState;
	}
	if (KEYMANAGER->isOnceKeyDown('H'))
	{
		return new hurtState;
	}
	if (KEYMANAGER->isOnceKeyDown('J'))
	{
		return new jokeposeState;
	}
	if (KEYMANAGER->isOnceKeyDown('L'))
	{
		return new summonState;
	}
	if (KEYMANAGER->isOnceKeyDown('T'))
	{

		float angle = getAngle(player->getPlayerData()->x, player->getPlayerData()->y, _ptMouse.x, _ptMouse.y);
		if (angle > PI*0.25 && angle < PI*0.75)
			player->getPlayerData()->stateEnum = STATE_UP_JUMP;
		else if (angle > PI*0.75 && angle < PI*1.25)
			player->getPlayerData()->stateEnum = STATE_LEFT_JUMP;
		else if (angle > PI*1.25 && angle < PI*1.75)
			player->getPlayerData()->stateEnum = STATE_DOWN_JUMP;
		else
			player->getPlayerData()->stateEnum = STATE_RIGHT_JUMP;
		player->getPlayerData()->angle = angle;
		return new jumpState;
	}

	return nullptr;

}

void idleState::enter(player* player)
{
	player->getPlayerData()->frameX = 0;
	player->getPlayerData()->frameY = 0;
	player->getPlayerData()->errorX = -10;
	player->getPlayerData()->errorY = 0;
	player->getPlayerData()->speed = 0;
	player->getPlayerData()->time = 0;
	switch (player->getPlayerData()->stateEnum)
	{
	case STATE_LEFT_WALK:
	case STATE_LEFT_DASH:
	case STATE_LEFT_FALL:
	case STATE_LEFT_SLIDE:
	case STATE_LEFT_FOREHAND:
	case STATE_LEFT_BACKHAND:
		player->getPlayerData()->stateEnum = STATE_LEFT_IDLE;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardIdleLeft");
		player->getPlayerData()->errorX = -10;
		player->getPlayerData()->errorY = 0;
		break;
	case STATE_RIGHT_WALK:
	case STATE_RIGHT_DASH:
	case STATE_RIGHT_FALL:
	case STATE_RIGHT_SLIDE:
	case STATE_RIGHT_FOREHAND:
	case STATE_RIGHT_BACKHAND:
		player->getPlayerData()->errorX = -8;
		player->getPlayerData()->errorY = 0;
		player->getPlayerData()->stateEnum = STATE_RIGHT_IDLE;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardIdleRight");
		break;
	case STATE_UP_WALK:
	case STATE_UP_DASH:
	case STATE_UP_FALL:
	case STATE_UP_FOREHAND:
	case STATE_UP_BACKHAND:
		player->getPlayerData()->errorX = -10;
		player->getPlayerData()->errorY = 0;
		player->getPlayerData()->stateEnum = STATE_UP_IDLE;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardIdleUp");
		break;
	case STATE_DOWN_WALK:
	case STATE_DOWN_DASH:
	case STATE_DOWN_FALL:
	case STATE_DOWN_FOREHAND:
	case STATE_DOWN_BACKHAND:
		player->getPlayerData()->errorX = -10;
		player->getPlayerData()->errorY = 0;
		player->getPlayerData()->stateEnum = STATE_DOWN_IDLE;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardIdleDown");
		break;
	default:
		player->getPlayerData()->stateEnum = STATE_DOWN_IDLE;
		player->getPlayerData()->image = IMAGEMANAGER->findDImage("WizardIdleDown");
		break;
	}
}

void idleState::update(player* player)
{

}

void idleState::exit(player* player)
{
}
