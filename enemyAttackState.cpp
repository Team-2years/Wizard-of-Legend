#include "stdafx.h"
#include "enemyAttackState.h"
#include "enemy.h"

enemyState * enemyAttackState::inputHandle(enemy * enemy)
{
	switch (enemy->getTagEnemy()->type)
	{
	case ENEMY_GHOUL:
	case ENEMY_EARTHZONER:
	case ENEMY_GOLEM:
	case ENEMY_KNIGHT:
	case ENEMY_KNIGHTBLUE:
	case ENEMY_KNIGHTRED:
	case ENEMY_KNIGHTGREEN:

		if (count > 30)
			return new enemyIdleState;
		break;
	case ENEMY_GHOULLARGE:
		if (count > 70)
			return new enemyIdleState;
		break;
	case ENEMY_FLAMEZONER:
		if (count > 50)
			return new enemyIdleState;
		break;
	case ENEMY_BLOBROLLER:
	case ENEMY_ORB:
		if (count == endCount) {
			enemy->getTagEnemy()->atkCheck = false;
			return new enemyIdleState;
		}
		break;
	case ENEMY_MIMIC:
		if (enemy->getTagEnemy()->distancePlayer > 200)
		{
			enemy->getTagEnemy()->atkCheck = false;
			return new enemyIdleState;
		}
		break;
	case ENEMY_SUMMONER:
	case ENEMY_SUMMONERBLUE:
	case ENEMY_SUMMONERRED:
	case ENEMY_SUMMONERGREEN:
		if (count > 100) {
			enemy->getTagEnemy()->isSummon = true;
			return new enemyIdleState;
		}
		break;
	case BOSS_ICEBOSS:
		switch (ptn)
		{
	
		default:
			if (count == endCount) {
				return new enemyIdleState;
			}
			break;
		}
		break;
	default:
		break;
	}
	return nullptr;
}

void enemyAttackState::enter(enemy * enemy)
{
	count = 0;
	enemy->getTagEnemy()->frameX = 0;
	enemy->getTagEnemy()->frameY = 0;
	switch (enemy->getTagEnemy()->type)
	{
	case ENEMY_GHOUL:
		maxCount = 10;
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GhoulAttack");
		if(enemy->getTagEnemy()->isRight)
		enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->x + 20, enemy->getTagEnemy()->y, 48, 48);
		else
		enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->x -48 , enemy->getTagEnemy()->y, 48, 48);
		break;
	case ENEMY_GHOULLARGE:
		maxCount = 7;
		switch (RND->getFromIntTo(0, 3))
		{
		case 0:
			enemy->getTagEnemy()->errorX = -18;
			enemy->getTagEnemy()->errorY = -8;
			enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GhoulLargeAttack0");
			
			break;
		case 1:
			enemy->getTagEnemy()->errorX = -22;
			enemy->getTagEnemy()->errorY = -12;
			enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GhoulLargeAttack1");
			break;
		case 2:
			enemy->getTagEnemy()->errorX = -15;
			enemy->getTagEnemy()->errorY = -16;
			enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GhoulLargeAttack2");
			break;
		default:
			break;
		}
		if (enemy->getTagEnemy()->isRight)
			enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->rc.left - 24, enemy->getTagEnemy()->rc.top - 16, 72, 48);
		else
			enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->rc.left - 24, enemy->getTagEnemy()->rc.top - 16, 72, 48);
		break;
	case ENEMY_EARTHZONER:
		maxCount = 10;
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("EarthZonerAttack");
		break;
	case ENEMY_FLAMEZONER:
		maxCount = 5;
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("FlameZonerAttack");
		break;
	case ENEMY_BLOBROLLER:
		maxCount = 4;
		endCount = RND->getFromIntTo(40, 100);
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = 0;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("BlobRollerRoll");
		angle = RND->getFromFloatTo(-PI / 4, PI / 4) + enemy->getTagEnemy()->anglePlayer;
		enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->rc.left, enemy->getTagEnemy()->rc.top - 16, 32, 48);
		enemy->getTagEnemy()->atkCheck = true;
		break;
	case ENEMY_MIMIC:
		maxCount = 4;
		enemy->getTagEnemy()->errorX = -7;
		enemy->getTagEnemy()->errorY = 0;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("MimicAttack");
		enemy->getTagEnemy()->atkCheck = true;
		break;
	case ENEMY_GOLEM:
		maxCount = 15;
		enemy->getTagEnemy()->errorX = -20;
		enemy->getTagEnemy()->errorY = -10;
		
		angle = enemy->getMiddleAngle();
		if (angle > PI*0.25 && angle < PI*0.75) 
		{
			enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->rc.left - 12, enemy->getTagEnemy()->rc.top - 48, 48, 72);

			enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GolemAttackUp0");
		}
		else if (angle > PI*0.75 && angle < PI*1.25)
		{
			enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->rc.left - 48, enemy->getTagEnemy()->rc.top - 16, 72, 48);

			enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GolemAttackRight0");
		}
		else if (angle > PI*1.25 && angle < PI*1.75)
		{
			enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->rc.left - 12, enemy->getTagEnemy()->rc.top, 48, 72);

			enemy->getTagEnemy()->isRight = true;
			enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GolemAttackDown0");
		}
		else 
		{
			enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->rc.left, enemy->getTagEnemy()->rc.top - 16, 72, 48);

			enemy->getTagEnemy()->isRight = true;
			enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GolemAttackRight0");
		}
		break;
	case ENEMY_KNIGHT:
		maxCount = 15;
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("KnightForehand");
		if (enemy->getTagEnemy()->isRight)
			enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->x + 20, enemy->getTagEnemy()->y, 48, 48);
		else
			enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->x - 48, enemy->getTagEnemy()->y, 48, 48);
		break;
	case ENEMY_KNIGHTBLUE:
		maxCount = 15;
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("KnightForehand_blue");
		if (enemy->getTagEnemy()->isRight)
			enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->x + 20, enemy->getTagEnemy()->y, 48, 48);
		else
			enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->x - 48, enemy->getTagEnemy()->y, 48, 48);
		break;
	case ENEMY_KNIGHTRED:
		maxCount = 15;
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("KnightForehand_red");
		if (enemy->getTagEnemy()->isRight)
			enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->x + 20, enemy->getTagEnemy()->y, 48, 48);
		else
			enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->x - 48, enemy->getTagEnemy()->y, 48, 48);
		break;
	case ENEMY_KNIGHTGREEN:
		maxCount = 15;
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("KnightForehand_green");
		if (enemy->getTagEnemy()->isRight)
			enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->x + 20, enemy->getTagEnemy()->y, 48, 48);
		else
			enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->x - 48, enemy->getTagEnemy()->y, 48, 48);
		break;
	case ENEMY_SUMMONER:
		maxCount = 15;
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerCast");

		break;
	case ENEMY_SUMMONERBLUE:
		maxCount = 15;
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerCast_blue");

		break;
	case ENEMY_SUMMONERRED:
		maxCount = 15;
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerCast_red");

		break;
	case ENEMY_SUMMONERGREEN:
		maxCount = 15;
		enemy->getTagEnemy()->errorX = -15;
		enemy->getTagEnemy()->errorY = -8;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerCast_green");

		break;
	case ENEMY_ORB:
		maxCount = 10;
		endCount = 100;
		enemy->getTagEnemy()->errorX = 0;
		enemy->getTagEnemy()->errorY = 0;
		enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("OrbChargeWindup");
		angle = enemy->getTagEnemy()->anglePlayer;
		enemy->getTagEnemy()->angle = angle;

		enemy->getTagEnemy()->attackRC = RectMake(enemy->getTagEnemy()->rc.left, enemy->getTagEnemy()->rc.top - 16, 32, 48);
		enemy->getTagEnemy()->atkCheck = true;
		break;
	case BOSS_ICEBOSS:
		ptn = RND->getFromIntTo(0, 4);
		switch (ptn)
		{
		case 0:
			maxCount = 20;
			endCount = 40;
			enemy->getTagEnemy()->errorX = -16;
			enemy->getTagEnemy()->errorY = -6;
			angle = enemy->getMiddleAngle();
			if (angle >= 0 && PI >= angle)
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("IceBossPointUp");
			else
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("IceBossPointDown");
			break;
		case 1:
			maxCount = 8;
			endCount = 45;
			enemy->getTagEnemy()->errorX = -16;
			enemy->getTagEnemy()->errorY = -6;
			angle = enemy->getMiddleAngle();
			// À§
			if (angle > PI*0.25 && angle < PI*0.75)
			{
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("IceBossRainbowCastUp");
			}
			else if (angle > PI*0.75 && angle < PI*1.25) // ¿Þ
			{
				enemy->getTagEnemy()->isRight = false;
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("IceBossRainbowCastRight");
			}
			else if (angle > PI*1.25 && angle < PI*1.75) //¾Æ
			{
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("IceBossRainbowCastDown");
			}
			else //¿À
			{
				enemy->getTagEnemy()->isRight = true;
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("IceBossRainbowCastRight");
			}
			break;
		case 2:
			maxCount = 8;
			endCount = enemy->getTagEnemy()->distancePlayer / enemy->getTagEnemy()->speed;
			enemy->getTagEnemy()->errorX = -16;
			enemy->getTagEnemy()->errorY = -6;
			angle = enemy->getMiddleAngle();
			if (angle > PI*0.25 && angle < PI*0.75)
			{
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("IceBossDashUp0");
			}
			else if (angle > PI*0.75 && angle < PI*1.25) // ¿Þ
			{
				enemy->getTagEnemy()->isRight = false;
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("IceBossDashRight0");
			}
			else if (angle > PI*1.25 && angle < PI*1.75) //¾Æ
			{
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("IceBossDashDown0");
			}
			else //¿À
			{
				enemy->getTagEnemy()->isRight = true;
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("IceBossDashRight0");
			}
			targetX = enemy->getTagEnemy()->playerX;
			targetY = enemy->getTagEnemy()->playerY;
			break;
		case 3:
			maxCount = 6;
			endCount = 66;
			enemy->getTagEnemy()->errorX = -16;
			enemy->getTagEnemy()->errorY = -6;
			enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("IceBossSpinFancy");
		default:
			break;
		}
	default:
		break;
	} 
}

void enemyAttackState::update(enemy * enemy)
{
	count++;
	if (count % maxCount == 0)
	{
		enemy->getTagEnemy()->frameX++;
		if (enemy->getTagEnemy()->image->getMaxFrameX()+1 <= enemy->getTagEnemy()->frameX) 
			switch (enemy->getTagEnemy()->type)
			{
			case ENEMY_GHOUL:
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GhoulIdle");
				break;
			case ENEMY_GHOULLARGE:
			case ENEMY_EARTHZONER:
				enemy->getTagEnemy()->frameX = enemy->getTagEnemy()->image->getMaxFrameX();
				
				break;
			case ENEMY_FLAMEZONER:
				enemy->getTagEnemy()->frameX = enemy->getTagEnemy()->image->getMaxFrameX() -1;
				break;
			case ENEMY_BLOBROLLER:
			case ENEMY_MIMIC:
				enemy->getTagEnemy()->frameX = 0;
				break;
			case ENEMY_GOLEM:
				if (angle > PI*1.25 && angle < PI*1.75)
				{
					enemy->getTagEnemy()->isRight = !enemy->getTagEnemy()->isRight;
				}
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("GolemAttackFollowThrough");
				break;
			case ENEMY_KNIGHT:
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("KnightIdle");
				break;
			case ENEMY_KNIGHTBLUE:
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("KnightIdle_blue");
				break;

			case ENEMY_KNIGHTRED:
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("KnightIdle_red");
				break;

			case ENEMY_KNIGHTGREEN:
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("KnightIdle_green");
				break;

			case ENEMY_SUMMONER:
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerIdleDown");
				break;
			case ENEMY_SUMMONERBLUE:
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerIdleDown_blue");
				break;
			case ENEMY_SUMMONERRED:
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerIdleDown_red");
				break;
			case ENEMY_SUMMONERGREEN:
				enemy->getTagEnemy()->image = IMAGEMANAGER->findDImage("SummonerIdleDown_green");
				break;
			case ENEMY_ORB:
				enemy->getTagEnemy()->frameX = enemy->getTagEnemy()->image->getMaxFrameX();
				break;
			case BOSS_ICEBOSS:
				switch (ptn)
				{

				default:
					enemy->getTagEnemy()->frameX = enemy->getTagEnemy()->image->getMaxFrameX();
					break;
				}
				break;
			}
	}
	switch (enemy->getTagEnemy()->type)
	{
	case ENEMY_GHOUL:
		if (count == 11)
		{
			enemy->getTagEnemy()->atkCheck = true;
		}
		else
			enemy->getTagEnemy()->atkCheck = false;
		break;
	case ENEMY_GHOULLARGE:
		if (count == 41)
		{
			enemy->getTagEnemy()->atkCheck = true;
		}else
			enemy->getTagEnemy()->atkCheck = false;
		break;
	case ENEMY_BLOBROLLER:
	
		enemy->getTagEnemy()->x += cosf(angle) * enemy->getTagEnemy()->speed;
		enemy->getTagEnemy()->y += -sinf(angle) * enemy->getTagEnemy()->speed;
		enemy->getTagEnemy()->attackRC = enemy->getTagEnemy()->rc;
		break;
	case ENEMY_MIMIC:
		if (enemy->getTagEnemy()->anglePlayer <= PI / 2 || enemy->getTagEnemy()->anglePlayer >= PI * 3 / 2)
			enemy->getTagEnemy()->isRight = true;
		else
			enemy->getTagEnemy()->isRight = false;
		if(count % 100 == 0)
			enemy->getTagEnemy()->atkCheck = true;
		enemy->getTagEnemy()->x += cosf(enemy->getTagEnemy()->anglePlayer) * enemy->getTagEnemy()->speed;
		enemy->getTagEnemy()->y += -sinf(enemy->getTagEnemy()->anglePlayer) * enemy->getTagEnemy()->speed;
		enemy->getTagEnemy()->attackRC = enemy->getTagEnemy()->rc;
		break;
	case ENEMY_GOLEM:
	case ENEMY_KNIGHT:
		if (count == 16)
		{
			enemy->getTagEnemy()->atkCheck = true;
		}
		else
			enemy->getTagEnemy()->atkCheck = false;
		break;
		//enemy->getTagEnemy()->attackRC.left + enemy->getTagEnemy()->attackRC.right) / 2,
		//(enemy->getTagEnemy()->attackRC.top + enemy->getTagEnemy()->attackRC.bottom) / 2
	case ENEMY_KNIGHTBLUE:
		if (count == 16)
		SKILLMANAGER->fire(9, (enemy->getTagEnemy()->attackRC.left + enemy->getTagEnemy()->attackRC.right) / 2,
			(enemy->getTagEnemy()->attackRC.top + enemy->getTagEnemy()->attackRC.bottom) / 2, 0, false);
		break;
	case ENEMY_KNIGHTRED:
		if (count == 16)
			SKILLMANAGER->fire(9, (enemy->getTagEnemy()->attackRC.left + enemy->getTagEnemy()->attackRC.right) / 2,
			(enemy->getTagEnemy()->attackRC.top + enemy->getTagEnemy()->attackRC.bottom) / 2, 0, false);
		break;
	case ENEMY_KNIGHTGREEN:
		break;
	case ENEMY_ORB: 
	if(enemy->getTagEnemy()->frameX == enemy->getTagEnemy()->image->getMaxFrameX())
	{
		enemy->getTagEnemy()->x += cosf(angle) * enemy->getTagEnemy()->speed;
		enemy->getTagEnemy()->y += -sinf(angle) * enemy->getTagEnemy()->speed; 
	}
	enemy->getTagEnemy()->attackRC = enemy->getTagEnemy()->rc;
	case BOSS_ICEBOSS:
		switch (ptn)
		{
		case 0:
			if (count == 16)
				SKILLMANAGER->fire(4, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2,
				(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2, 0, false);
			break;
		case 1:
			if (count == 16) {
				SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2,
					(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2, 0, false);
				if (angle > PI*0.25 && angle < PI*0.75)
				{
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2 - 50, 0, false);
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2 - 100, 0, false);
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2 - 150, 0, false);
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2 - 200, 0, false);
				}
				else if (angle > PI*0.75 && angle < PI*1.25) // ¿Þ
				{
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2 - 50,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2, 0, false);
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2 - 100,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2, 0, false);
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2 - 150,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2, 0, false);
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2 - 200,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2, 0, false);
				}
				else if (angle > PI*1.25 && angle < PI*1.75) //¾Æ
				{
					// x
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2 + 50, 0, false);
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2 + 100, 0, false);
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2 + 150, 0, false);
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2 + 200, 0, false);
				}
				else //¿À
				{
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2 + 50,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2, 0, false);
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2 + 100,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2, 0, false);
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2 + 150,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2, 0, false);
					SKILLMANAGER->fire(10, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2 + 200,
						(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2, 0, false);
				}
			}
			break;
		case 2:
			if(count % 3 == 0)
				SKILLMANAGER->fire(9, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2,
				(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2, 0, false);
			enemy->getTagEnemy()->x += cosf(angle) * enemy->getTagEnemy()->speed;
			enemy->getTagEnemy()->y += -sinf(angle) * enemy->getTagEnemy()->speed;
			break;
		case 3:
			if (count % 4 == 0)
				SKILLMANAGER->fire(9, (enemy->getTagEnemy()->rc.left + enemy->getTagEnemy()->rc.right) / 2 +RND->getFromIntTo(-150, 150),
				(enemy->getTagEnemy()->rc.top + enemy->getTagEnemy()->rc.bottom) / 2 + RND->getFromIntTo(-150, 150), 0, false);
			break;

		default:
			break;
		}
		break;
	default:
		break;
	}
}

void enemyAttackState::exit(enemy * enemy)
{
}
