#include "stdafx.h"
#include "enemyDeathState.h"
#include "enemy.h"

enemyState * enemyDeathState::inputHandle(enemy * enemy)
{
	if (enemy->getTagEnemy()->image->getMaxFrameX() <= enemy->getTagEnemy()->frameX)
		return new enemyIdleState;
	return nullptr;
}

void enemyDeathState::enter(enemy * enemy)
{
	enemy->getTagEnemy()->frameX = 0;
	enemy->getTagEnemy()->frameY = 0;
	count = 0;
	switch (enemy->getTagEnemy()->type)
	{
	case ENEMY_GHOUL:
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GhoulDeath");
		break;
	case ENEMY_GHOULLARGE:
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GhoulLargeDead");
		break;
	case ENEMY_FLAMEZONER:
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("FlameZonerDead");
		break;
	case ENEMY_BLOBROLLER:
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = 0;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("BlobRollerDead");
		break;
	case ENEMY_GOLEM:
		enemy->getTagEnemy()->errorX = -22;
		enemy->getTagEnemy()->errorY = -7;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GolemDeath");
		break;
	case ENEMY_KNIGHT:
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -38;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("KnightDeath");
		break;
	case ENEMY_KNIGHTBLUE:
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -38;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("KnightDeath");
		break;
	case ENEMY_KNIGHTRED:
	case ENEMY_KNIGHTGREEN:

		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -38;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("KnightDeath");
		break;
	case ENEMY_SUMMONER:
	case ENEMY_SUMMONERBLUE:
	case ENEMY_SUMMONERRED:
	case ENEMY_SUMMONERGREEN:
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -38;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerDead");
		break;
	default:
		break;
	}
}

void enemyDeathState::update(enemy * enemy)
{
	count++;
	if (count % 7 == 0)
	{
			enemy->getTagEnemy()->frameX++;
	}
}

void enemyDeathState::exit(enemy * enemy)
{
}
