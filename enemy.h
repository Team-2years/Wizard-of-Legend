#pragma once
#include "gameNode.h"
#include "enemyIdleState.h"

enum enemyType 
{
	ENEMY_GHOUL,
	ENEMY_GHOULLARGE,
	ENEMY_EARTHZONER,
	ENEMY_FLAMEZONER,
	ENEMY_BLOBROLLER,
	ENEMY_MIMIC,
	ENEMY_GOLEM,
	ENEMY_KNIGHT,
	ENEMY_KNIGHTBLUE,
	ENEMY_KNIGHTRED,
	ENEMY_KNIGHTGREEN,
	ENEMY_SUMMONER,
	ENEMY_SUMMONERBLUE,
	ENEMY_SUMMONERRED,
	ENEMY_SUMMONERGREEN,
	ENEMY_ORB,
	BOSS_FIREBOSS,
	BOSS_ICEBOSS

};

struct tagEnemy
{
	dImage* image;
	float x, y, z;
	int frameX, frameY;
	float radius;
	int damage;
	float speed;
	float angle;
	float anglePlayer;
	float distancePlayer;
	float hp;
	RECT rc;				//��Ʈ
	int count;				//�����ӷ����� ��
	int maxCount;
	enemyType type;			// ���� ���ʹ� �ΰ�?
	int rndCount;			//�߻� ī��Ʈ ��
	int rndFireCount;		//���� �߻� ī��Ʈ ��
	bool isRight;
	enemyState* state;
	float playerX, playerY;
	float errorX, errorY;
	RECT playerRc;
	RECT attackRC;
	bool atkCheck;
	bool isSummon; // ��ȯ�� �����Ѱ�
	int summonNum; // �ִ� ��ȯ����
};

class enemy :
	public gameNode
{
protected:
	tagEnemy _tagEnemy;

public:
	enemy() {}
	~enemy() {}

	virtual HRESULT init();
	virtual HRESULT init(POINT position);
	virtual void release();
	virtual void update();
	virtual void render();

	void move();
	void draw();

	bool patternCount();

	tagEnemy* getTagEnemy() { return &_tagEnemy; }
	void setPlayerAngle() { _tagEnemy.anglePlayer = getAngle(_tagEnemy.rc.left, _tagEnemy.rc.top, _tagEnemy.playerX, _tagEnemy.playerY); }
	float getMiddleAngle() { return getAngle((_tagEnemy.rc.right + _tagEnemy.rc.left) / 2,
		(_tagEnemy.rc.top + _tagEnemy.rc.bottom) / 2,
		_tagEnemy.playerX, _tagEnemy.playerY); }
	void setPlayerDistance() { _tagEnemy.distancePlayer = getDistance(_tagEnemy.rc.left, _tagEnemy.rc.top, _tagEnemy.playerX, _tagEnemy.playerY); }
	void inputHandle();
	void changeState(enemyState* state);
	RECT getRect() { return _tagEnemy.rc; };
};

