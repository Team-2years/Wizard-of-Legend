#include "stdafx.h"
#include "enemyManager.h"
#include "player.h"
#include "hurtState.h"

enemyManager::enemyManager()
{
}

enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	return S_OK;
}

void enemyManager::release()
{

}

void enemyManager::update()
{
	for (int i = 0; i < _vEnemy.size(); i++) 
	{
		if (_vEnemy[i]->getTagEnemy()->isSummon && _vEnemy[i]->getTagEnemy()->summonNum < 5)
		{
			float x = _vEnemy[i]->getTagEnemy()->x + RND->getFromIntTo(-100, 100);
			float y = _vEnemy[i]->getTagEnemy()->y + RND->getFromIntTo(-100, 100);
			float intervalX;
			float intervalY;
			switch (_vEnemy[i]->getTagEnemy()->type)
			{
			case ENEMY_SUMMONER:
			 intervalX = 50 * RND->getFromIntTo(1, 3);
			 intervalY = 10*RND->getFromIntTo(-5,5);
				setOrb(PointMake(x , y));
				setOrb(PointMake(x + intervalX, y + intervalY));
				setOrb(PointMake(x + intervalX*2, y + intervalY *2));
				_vEnemy[i]->getTagEnemy()->isSummon = false;
				_vEnemy[i]->getTagEnemy()->summonNum++;
				break;
			case ENEMY_SUMMONERBLUE:
				setGhoul(PointMake(x, y));
				_vEnemy[i]->getTagEnemy()->isSummon = false;
				_vEnemy[i]->getTagEnemy()->summonNum++;
				break;
			case ENEMY_SUMMONERRED:
				setFlameZoner(PointMake(x, y));
				_vEnemy[i]->getTagEnemy()->isSummon = false;
				_vEnemy[i]->getTagEnemy()->summonNum++;
				break;
			case ENEMY_SUMMONERGREEN:
				setEarthZoner(PointMake(x, y));
				_vEnemy[i]->getTagEnemy()->isSummon = false;
				_vEnemy[i]->getTagEnemy()->summonNum++;
				break;
			default:
				break;
			}
			
		}
		_vEnemy[i]->getTagEnemy()->playerX = _player->getPlayerData()->x;
		_vEnemy[i]->getTagEnemy()->playerY = _player->getPlayerData()->y;
		_vEnemy[i]->setPlayerAngle();
		_vEnemy[i]->setPlayerDistance();
		_vEnemy[i]->getTagEnemy()->playerRc = _player->getPlayerData()->rc;
		_vEnemy[i]->inputHandle();
		_vEnemy[i]->update();
		if (_vEnemy[i]->getTagEnemy()->atkCheck) 
		{
			if (IntersectRect(&temp, &_vEnemy[i]->getTagEnemy()->attackRC, &_vEnemy[i]->getTagEnemy()->playerRc)) 
			{
				_player->getPlayerData()->damaged = _vEnemy[i]->getTagEnemy()->damage;
				_player->changeState(new hurtState);
				_vEnemy[i]->getTagEnemy()->atkCheck = false;
			}
		}
	}
}

void enemyManager::render()
{
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		_vEnemy[i]->render();
	}
}

void enemyManager::setGhoul(POINT position)
{
	enemy* _enemy = new ghoul;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setGhoulLarge(POINT position)
{
	enemy* _enemy = new ghoulLarge;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setEarthZoner(POINT position)
{
	enemy* _enemy = new EarthZoner;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setFlameZoner(POINT position)
{
	enemy* _enemy = new flameZoner;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setBlobRoller(POINT position)
{
	enemy* _enemy = new blobRoller;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setMimic(POINT position)
{
	enemy* _enemy = new mimic;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setGolem(POINT position)
{
	enemy* _enemy = new golem;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setKnight(POINT position)
{
	enemy* _enemy = new knight;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setBlueKnight(POINT position)
{
	enemy* _enemy = new blueKnight;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setRedKnight(POINT position)
{
	enemy* _enemy = new redKnight;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setGreenKnight(POINT position)
{
	enemy* _enemy = new greenKnight;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setSummoner(POINT position)
{
	enemy* _enemy = new summoner;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setBlueSummoner(POINT position)
{
	enemy* _enemy = new blueSummoner;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setRedSummoner(POINT position)
{
	enemy* _enemy = new redSummoner;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setGreenSummoner(POINT position)
{
	enemy* _enemy = new greenSummoner;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setOrb(POINT position)
{
	enemy* _enemy = new orb;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

void enemyManager::setIceBoss(POINT position)
{
	enemy* _enemy = new iceBoss;
	_enemy->init(position);
	_vEnemy.push_back(_enemy);
}

