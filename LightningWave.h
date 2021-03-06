#pragma once
#include "gameNode.h"
#include <vector>



struct tagLightningWave
{
	dImage* skillImage;		// 이미지 
	Vector2 _RL, _RR, _RT, _RB; //포인트<- 충돌할때 사용해줘
	RECT rc;				// 렉트
	float x, y;				// 좌표(실시간)
	float angle;			// 각도
	float radius;			// 반지름
	float speed;			// 스피드
	float fireX, fireY;		// 발사시 처음 좌표(발사된 좌표)
	bool isFire;			//발동
	int count;				// 프레임카운트용
	int _time;
	RECT rc2;
	bool playerATK;
};

class LightningWave : public gameNode
{
private:
	vector<tagLightningWave>			_vSkill;
	vector<tagLightningWave>::iterator _viSkill;

	int _x2;
	float _range;
	int _SkillMax;
	float _angle;
	int _time;
	burn* _burn;
public:
	LightningWave() {};
	~LightningWave() {};

	HRESULT init(int skillMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, bool playerATK);


	void move();


	void removeSkill(int arrNum);

	RECT returnRect() { return _viSkill->rc; }
	RECT returnRect2() { return _viSkill->rc2; }
	vector<tagLightningWave>* getVSkill() { return &_vSkill; }
	vector<tagLightningWave>::iterator getViSkill() { return _viSkill; }

};