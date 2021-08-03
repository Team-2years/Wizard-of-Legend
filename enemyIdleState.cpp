#include "stdafx.h"
#include "enemyIdleState.h"
#include "enemyMoveState.h"
#include "enemyDeathState.h"
#include "enemyHurtState.h"
#include "enemyAttackState.h"
#include "enemy.h"

enemyState * enemyIdleState::inputHandle(enemy * enemy)
{
	switch (enemy->getTagEnemy()->type)
	{
	case ENEMY_GHOUL:
	case ENEMY_GHOULLARGE:
	case ENEMY_GOLEM:
	case ENEMY_KNIGHT:
	case ENEMY_KNIGHTBLUE:
	case ENEMY_KNIGHTRED:
	case ENEMY_KNIGHTGREEN:
		if (enemy->getTagEnemy()->distancePlayer <= 500 && maxCount < count)
			return new enemyMoveState;
		break;
	case ENEMY_EARTHZONER:
		if (enemy->getTagEnemy()->distancePlayer <= 300 && maxCount < count)
			return new enemyMoveState;
			break;
	case ENEMY_FLAMEZONER:
		if (enemy->getTagEnemy()->distancePlayer <= 300 && maxCount < count)
		switch (RND->getFromIntTo(0, 250))
		{
		case 1:
			return new enemyAttackState;
			break;
		default:
			break;
		}
		break;
	case ENEMY_BLOBROLLER:
		if (enemy->getTagEnemy()->distancePlayer <= 300 && maxCount < count)
			switch (RND->getFromIntTo(0, 150))
			{
			case 1:
				return new enemyAttackState;
				break;
			default:
				break;
			}
		break;
	case ENEMY_MIMIC:
		if (enemy->getTagEnemy()->distancePlayer <= 200 && maxCount < count)
			return new enemyAttackState;
		break;
	case ENEMY_SUMMONER:
	case ENEMY_SUMMONERBLUE:
	case ENEMY_SUMMONERRED:
	case ENEMY_SUMMONERGREEN:
		if (enemy->getTagEnemy()->distancePlayer <= 700 && maxCount < count)
			switch (RND->getFromIntTo(0, 4))
			{
			case 0:
				if(enemy->getTagEnemy()->summonNum < 3)
				return new enemyAttackState;
				break;
			default:
				return new enemyMoveState;
				break;
			}
			
		break;
	case ENEMY_ORB:
		if (maxCount < count)
		{
			return new enemyAttackState;
		}
		break;
	case BOSS_ICEBOSS:
		if (maxCount < count)
			return new enemyAttackState;
		break;

	default:
		break;
	}
	
	return nullptr;
}

void enemyIdleState::enter(enemy * enemy)
{
	enemy->getTagEnemy()->frameX = 0;
	enemy->getTagEnemy()->frameY = 0;
	
	count = 0;
	switch (enemy->getTagEnemy()->type)
	{
	case ENEMY_GHOUL:
		maxCount = RND->getFromIntTo(30, 50);
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GhoulIdle");
		break;
	case ENEMY_GHOULLARGE:
		maxCount = RND->getFromIntTo(30, 90);
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GhoulLargeIdle");
		break;
	case ENEMY_EARTHZONER:
		maxCount = RND->getFromIntTo(30, 90);
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("EarthZonerIdle");
		break;
	case ENEMY_FLAMEZONER:
		maxCount = RND->getFromIntTo(30, 90);
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("FlameZonerIdle");
		break;
	case ENEMY_BLOBROLLER:
		maxCount = RND->getFromIntTo(30, 90);
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = 0;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("BlobRollerIdle");
		break;
	case ENEMY_MIMIC:
		maxCount = RND->getFromIntTo(30, 50);
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = 0;
		
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("MimicHide");
		break;
	case ENEMY_GOLEM:
		maxCount = RND->getFromIntTo(30, 90);

		enemy->getTagEnemy()->errorX = -20;
		enemy->getTagEnemy()->errorY = -10;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GolemIdle");
		break;
	case ENEMY_KNIGHT:
		maxCount = RND->getFromIntTo(30, 90);
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("KnightIdle");
		break;
	case ENEMY_KNIGHTBLUE:
		maxCount = RND->getFromIntTo(30, 90);
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("KnightIdle_blue");
		break;
	case ENEMY_KNIGHTRED:
		maxCount = RND->getFromIntTo(30, 90);
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("KnightIdle_red");
		break;
	case ENEMY_KNIGHTGREEN:
		maxCount = RND->getFromIntTo(30, 90);
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("KnightIdle_green");
		break;
	case ENEMY_SUMMONER:
		maxCount = RND->getFromIntTo(30, 110);
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerIdleDown");
		break;
	case ENEMY_SUMMONERBLUE:
		maxCount = RND->getFromIntTo(30, 110);
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerIdleDown_blue");
		break;
	case ENEMY_SUMMONERRED:
		maxCount = RND->getFromIntTo(30, 110);
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerIdleDown_red");
		break;
	case ENEMY_SUMMONERGREEN:
		maxCount = RND->getFromIntTo(30, 110);
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerIdleDown_green");
		break;
	case ENEMY_ORB:
		maxCount = 100;
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = 0;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("OrbChargeIdle");
		break;
	case BOSS_ICEBOSS:
		maxCount = RND->getFromIntTo(50, 100);
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("IceBossIdle");
		break;
	default:
		break;
	}
}

void enemyIdleState::update(enemy * enemy)
{
	if (enemy->getTagEnemy()->anglePlayer <= PI / 2 || enemy->getTagEnemy()->anglePlayer >= PI * 3 / 2)
		enemy->getTagEnemy()->isRight = true;
	else
		enemy->getTagEnemy()->isRight = false;
	count++;
	switch (enemy->getTagEnemy()->type)
	{
	case ENEMY_EARTHZONER:
		if (count % 10 == 0)
		{
			if (enemy->getTagEnemy()->image->getMaxFrameX() <= enemy->getTagEnemy()->frameX) enemy->getTagEnemy()->frameX = 0;
			else
				enemy->getTagEnemy()->frameX++;
		}
	default:
		break;
	}
}

void enemyIdleState::exit(enemy * enemy)
{
}
