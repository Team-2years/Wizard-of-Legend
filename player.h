#pragma once
#include "gameNode.h"
#include "idleState.h"

//=========형준==================

#include "Inventory.h"
#include "UIManager.h"
#include "SaveDataManager.h"
#include "DateBaseManager.h"

#define BASIC_DAMAGE_PER 1.00f
#define BASIC_MAX_HP 500
//==============================


#define DASHSPEED 8.0f
#define SPEED 5.0f

enum playerStateEnum  
{
	STATE_LEFT_IDLE,
	STATE_RIGHT_IDLE,
	STATE_UP_IDLE,
	STATE_DOWN_IDLE,
	STATE_LEFT_WALK,
	STATE_RIGHT_WALK,
	STATE_UP_WALK,
	STATE_DOWN_WALK,
	STATE_LEFT_SLIDE,
	STATE_RIGHT_SLIDE,
	STATE_UP_SLIDE,
	STATE_DOWN_SLIDE,
	STATE_UP_DASH,
	STATE_DOWN_DASH,
	STATE_LEFTUP_DASH,
	STATE_LEFTDOWN_DASH,
	STATE_RIGHTUP_DASH,
	STATE_RIGHTDOWN_DASH,
	STATE_RIGHT_DASH,
	STATE_LEFT_DASH,
	STATE_LEFT_FALL,
	STATE_RIGHT_FALL,
	STATE_DOWN_FALL,
	STATE_UP_FALL,
	STATE_LEFT_BACKHAND,
	STATE_RIGHT_BACKHAND,
	STATE_UP_BACKHAND,
	STATE_DOWN_BACKHAND,
	STATE_LEFT_FOREHAND,
	STATE_RIGHT_FOREHAND,
	STATE_DOWN_FOREHAND,
	STATE_UP_FOREHAND,
	STATE_DOWN_GROUNDSLAM,
	STATE_UP_GROUNDSLAM,
	STATE_LEFT_PBAOE,
	STATE_RIGHT_PBAOE,
	STATE_DOWN_PBAOE,
	STATE_UP_PBAOE,
	STATE_LEFT_KICK,
	STATE_RIGHT_KICK,
	STATE_DOWN_KICK,
	STATE_UP_KICK,
	STATE_LEFT_HURT,
	STATE_RIGHT_HURT,
	STATE_DOWN_HURT,
	STATE_UP_HURT,
	STATE_JOKEPOSE,
	STATE_SUMMON,
	STATE_DOWN_JUMP,
	STATE_UP_JUMP,
	STATE_RIGHT_JUMP,
	STATE_LEFT_JUMP,
	STATE_SKILL,
	STATE_HIT,
	STATE_DOWN,
	STATE_DEAD,
	STATE_GETUP,
	STATE_HOOD
};

struct tagPlayer
{
	dImage* image;
	state* state;
	playerStateEnum stateEnum;
	RECT rc;
	RECT attackRect;
	float x, y, z;
	int time;
	int hp;
	float gravity;
	float jumpPower;
	float sumg;
	float angle;
	int frameX;
	int frameY;
	float speed;
	int moveCommandInput;
	float errorX, errorY;
	int dashCount;
	bool atkHand;
	float damaged;
	int hitCount;
	//임시로 만들어둔것  추후 상의해서 바꿀예정임

	float PlayerBasicDamage;
	float PlayerEarthDamage;
	float PlayerThunderDamage;
	float PlayerWaterDamage;
	float PlayerFireDamage;
	float PlayerWindDamage;

	int gold;
	int jewel;
	
	int currentHp;
	int maxHp;

	int currentMp;
	int maxMp;


};

class player :
    public gameNode
{
private:
	tagPlayer _playerData;

	//=============형준===============

	DateBaseManager* DataBase;

	SaveDataManager* _saveData;

	int mpCount;

	Inventory* _Inven;
	UIManager* _UI;

	//===============================
public:
    virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	tagPlayer* getPlayerData() { return &_playerData; }
	void changeState(state* state);
	void inputHandle();
	
	//==================형준=========================


	void setPlayerEarthDamage(float currentDamage) { _playerData.PlayerEarthDamage = currentDamage; }
	void setPlayerFireDamaage(float currentDamage) { _playerData.PlayerFireDamage = currentDamage; }
	void setPlayerThunderDamage(float currentDamage) { _playerData.PlayerThunderDamage = currentDamage; }
	void setPlayerWaterDamage(float currentDamage) { _playerData.PlayerWaterDamage = currentDamage; }
	void setPlayerWindDamage(float currentDamage) { _playerData.PlayerWindDamage = currentDamage; }

	Inventory* getInven() { return _Inven; }
	UIManager* getUI() { return _UI; }

	//HP
	void setPlayerHp(int _num)
	{
		if (_playerData.currentHp < 0) _playerData.currentHp = 0;
		else if (_playerData.currentHp > _playerData.maxHp) _playerData.currentHp = _playerData.maxHp;
		else _playerData.currentHp = _num;

		_UI->getHpProgressBar()->setFrogressBar(_playerData.currentHp, _playerData.maxHp);
	}
	void setPlayerMaxHp(int _num) { _playerData.maxHp = _num; }

	//MP

	void setPlayerMp(int _num)
	{
		if (_playerData.currentMp > _playerData.maxMp) _playerData.currentMp = _playerData.maxMp;
		else _playerData.currentMp = _num;

		_UI->getMpProgressBar()->setFrogressBar(_playerData.currentMp, _playerData.maxMp);
	}

};

