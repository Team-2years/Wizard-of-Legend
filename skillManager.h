#pragma once
#include "singletonBase.h"
#include "fireDash.h"
#include "fireCross.h"
#include "skill.h"
#include "iceSpear.h"
#include "waterZone.h"
#include "bubble.h"
#include "LightningWave.h"
#include "LightningJump.h"
#include "LightBeam.h"
#include "iceWall.h"
#include "frostWall.h"

class skillManager : public singletonBase<skillManager>
{
private:
	fireDash* _fireDash; //2번
	fireCross* _fireCross; //1번
	skill* _skill; // 0번
	iceSpear* _iceSpear; //3번
	waterZone* _waterZone; // 4번
	bubble* _bubble; //5번
	LightningWave* _LightningWave; //6번
	LightningJump* _LightningJump;
	LightBeam* _LightBeam;
	iceWall* _iceWall;
	frostWall* _frostWall;

	int _skillType;
public:

	skillManager() {};
	~skillManager() {};

	HRESULT init();
	void release();
	void update();
	void render();

	void fire(int SkillNum,float x, float y, float angle, bool playerATK);
	void keyUP();
	//void linkvEnemy(vector<enemy*>* ev) { _vEnemy = *ev; }

	vector<tagfireDash>* getFireDash() { return _fireDash->getVSkill(); }
	vector<tagfireCross>* getFireCross() { return _fireCross->getVSkill(); }
	vector<tagskill>* getSkill() { return _skill->getVSkill(); }
	vector<tagiceSpear>* getIceSpear() { return _iceSpear->getVSkill(); }
	vector<tagwaterZone>* getWaterZone() { return _waterZone->getVSkill(); }
	vector<tagbubble>* getBubble() { return _bubble->getVSkill(); }
	vector<tagLightningWave>* getLightningWave() { return _LightningWave->getVSkill(); }
	vector<tagLightningJump>* getLightningJump() { return _LightningJump->getVSkill(); }
	vector<tagLightBeam>* getLightBeam() { return _LightBeam->getVSkill(); }
	vector<tagiceWall>* getIceWall() { return _iceWall->getVSkill(); }
	vector<tagfrostWall>* getFrostWall() { return _frostWall->getVSkill(); }
};