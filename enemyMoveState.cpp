#include "stdafx.h"
#include "enemyMoveState.h"
#include "enemyAttackState.h"
#include "enemy.h"

enemyState * enemyMoveState::inputHandle(enemy * enemy)
{
	switch (enemy->getTagEnemy()->type)
	{
	case ENEMY_GHOUL:
	case ENEMY_GHOULLARGE:
		if (enemy->getTagEnemy()->distancePlayer > 500)
			return new enemyIdleState;
		if (IntersectRect(&temp, &enemy->getTagEnemy()->rc, &enemy->getTagEnemy()->playerRc))
			return new enemyAttackState;
		break;
	case ENEMY_EARTHZONER:
		if (enemy->getTagEnemy()->distancePlayer > 300)
			return new enemyIdleState;
		switch (RND->getFromIntTo(0,250))
		{
		case 1:
			return new enemyAttackState;
			break;
		default:
			break;
		}
		if (IntersectRect(&temp, &enemy->getTagEnemy()->rc, &enemy->getTagEnemy()->playerRc))
			return new enemyAttackState;
		break;
	case ENEMY_GOLEM:
		if (enemy->getTagEnemy()->distancePlayer > 500)
			return new enemyIdleState;
		if (getDistance((enemy->getTagEnemy()->rc.right + enemy->getTagEnemy()->rc.left) / 2,
			(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2,
			enemy->getTagEnemy()->playerX, enemy->getTagEnemy()->playerY) < enemy->getTagEnemy()->radius)
			return new enemyAttackState;
		break;
	case ENEMY_KNIGHT:
	case ENEMY_KNIGHTBLUE:
	case ENEMY_KNIGHTRED:
	case ENEMY_KNIGHTGREEN:
		if (enemy->getTagEnemy()->distancePlayer > 500)
			return new enemyIdleState;
		if (IntersectRect(&temp, &enemy->getTagEnemy()->rc, &enemy->getTagEnemy()->playerRc))
			return new enemyAttackState;
		break;
	case ENEMY_SUMMONER:
	case ENEMY_SUMMONERBLUE:
	case ENEMY_SUMMONERRED:
	case ENEMY_SUMMONERGREEN:
		cout << count;
		if (count > 75) 
		{
			return new enemyIdleState;
		}
		break;
	default:
		break;
	}
	return nullptr;
}

void enemyMoveState::enter(enemy * enemy)
{
	count = 0;
	enemy->getTagEnemy()->frameX = 0;
	enemy->getTagEnemy()->frameY = 0;
	maxCount = 10;
	switch (enemy->getTagEnemy()->type)
	{
	case ENEMY_GHOUL:
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GhoulRunRight");
		break;
	case ENEMY_GHOULLARGE:
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GhoulLargeRunRight");
		break;
	case ENEMY_EARTHZONER:
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("EarthZonerIdle");
		break;
	case ENEMY_GOLEM:
		enemy->getTagEnemy()->errorX = -20;
		enemy->getTagEnemy()->errorY = -10;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GolemRunRight");
		break;
	case ENEMY_KNIGHT:
		maxCount = 9;
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("RunRight");
		break;
	case ENEMY_KNIGHTBLUE:
		maxCount = 9;
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("RunRight_blue");
		break;
	case ENEMY_KNIGHTRED:
		maxCount = 9;
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("RunRight_red");
		break;
	case ENEMY_KNIGHTGREEN:
		maxCount = 9;
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("RunRight_green");
		break;
	case ENEMY_SUMMONER:
		angle = RND->getFromFloatTo(0, PI2);
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerRunRight");
		break;
	case ENEMY_SUMMONERBLUE:
		angle = RND->getFromFloatTo(0, PI2);
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerRunRight_blue");
		break;
	case ENEMY_SUMMONERRED:
		angle = RND->getFromFloatTo(0, PI2);
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerRunRight_red");
		break;
	case ENEMY_SUMMONERGREEN:
		angle = RND->getFromFloatTo(0, PI2);
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerRunRight_green");
		break;
	default:
		break;
	}
}

void enemyMoveState::update(enemy * enemy)
{
	if (enemy->getTagEnemy()->anglePlayer <= PI / 2 || enemy->getTagEnemy()->anglePlayer >= PI * 3 / 2)
		enemy->getTagEnemy()->isRight = true;
	else
		enemy->getTagEnemy()->isRight = false;
	count++;
	if (count % maxCount == 0)
	{
		switch (enemy->getTagEnemy()->type)
		{
		case ENEMY_KNIGHT:
		case ENEMY_KNIGHTBLUE:
		case ENEMY_KNIGHTRED:
		case ENEMY_KNIGHTGREEN:

			if (enemy->getTagEnemy()->image->getMaxFrameX()-2 <= enemy->getTagEnemy()->frameX) enemy->getTagEnemy()->frameX = 0;
			else {
			
				enemy->getTagEnemy()->frameX++;
			}
			break;
		default:
			if (enemy->getTagEnemy()->image->getMaxFrameX() <= enemy->getTagEnemy()->frameX) enemy->getTagEnemy()->frameX = 0;
			else
				enemy->getTagEnemy()->frameX++;
			break;
		}
		
	}
	switch (enemy->getTagEnemy()->type)
	{
	case ENEMY_SUMMONER:
	case ENEMY_SUMMONERBLUE:
	case ENEMY_SUMMONERRED:
	case ENEMY_SUMMONERGREEN:
		if (count % 25 == 0)
		{
			angle = RND->getFromFloatTo(0, PI2);
		}
		if (!IntersectRect(&temp, &enemy->getTagEnemy()->rc, &enemy->getTagEnemy()->playerRc))
		{
			enemy->getTagEnemy()->x += cosf(angle) * enemy->getTagEnemy()->speed;
			enemy->getTagEnemy()->y += -sinf(angle) * enemy->getTagEnemy()->speed;
		}
		break;
	default:
		if (!IntersectRect(&temp, &enemy->getTagEnemy()->rc, &enemy->getTagEnemy()->playerRc))
		{
			enemy->getTagEnemy()->x += cosf(enemy->getTagEnemy()->anglePlayer) * enemy->getTagEnemy()->speed;
			enemy->getTagEnemy()->y += -sinf(enemy->getTagEnemy()->anglePlayer) * enemy->getTagEnemy()->speed;
		}
		break;
	}
}

void enemyMoveState::exit(enemy * enemy)
{ 

}
