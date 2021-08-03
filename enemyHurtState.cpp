#include "stdafx.h"
#include "enemyHurtState.h"
#include "enemy.h"
enemyState * enemyHurtState::inputHandle(enemy * enemy)
{
	switch (enemy->getTagEnemy()->type)
	{
	case ENEMY_GHOUL:
	case ENEMY_GHOULLARGE:
	case ENEMY_EARTHZONER:
	case ENEMY_FLAMEZONER :
	case BOSS_ICEBOSS:

		if (count > 10)
			return new enemyIdleState;
		break;
	case ENEMY_BLOBROLLER:
	case ENEMY_MIMIC:
		if (enemy->getTagEnemy()->image->getMaxFrameX() <= enemy->getTagEnemy()->frameX)
			return new enemyIdleState;
		break;
	}
	return nullptr;
}

void enemyHurtState::enter(enemy * enemy)
{
	enemy->getTagEnemy()->frameX = 0;
	enemy->getTagEnemy()->frameY = 0;
	
	count = 0;
	switch (enemy->getTagEnemy()->type)
	{
	case ENEMY_GHOUL:
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GhoulHurt");
		break;
	case ENEMY_EARTHZONER:
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("EarthZonerHurt");
		break;
	case ENEMY_FLAMEZONER:
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("FlameZonerHurt");
		break;
	case ENEMY_BLOBROLLER:
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = 0;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("BlobRollerHurt");
		break;
	case ENEMY_MIMIC:
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = 0;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("MimicHurt");
		break;
	case BOSS_ICEBOSS:
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("IceBossHurt");

		break;
	default:
		break;
	}
}

void enemyHurtState::update(enemy * enemy)
{
	count++;
	switch (enemy->getTagEnemy()->type)
	{
	case ENEMY_BLOBROLLER:
		if (count % 5 == 0)
		{
			enemy->getTagEnemy()->frameX++;
		}
		break;
	
	case ENEMY_MIMIC:
		if (count % 8 == 0)
		{
			enemy->getTagEnemy()->frameX++;
		}
		break;
	default:
		break;
	}
}

void enemyHurtState::exit(enemy * enemy)
{
}
