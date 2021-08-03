#pragma once
#include "progressBar.h"
#include "skillManager.h"
#include "gameNode.h"


enum KeyKind
{
	KEY_SKILL,
	KEY_INVEN,
	KEY_MAP,
};

struct tagKey
{
	RECT rc;
	dImage* image;
	dImage* Icon;
	KeyKind key;
	int KeyInt;
	float opacity;
	//나중에 키값 관련 변수 추가하기
};

class UIManager : public gameNode
{
private:

	
	//=============화면에 뜨는 설정===============

	dImage* _playerPicture;//플레이어 아이콘
	dImage* backGroundPicture;//플레이어 아이콘 뒤의 백그라운드
	
	progressBar* HP_Progress;//HP
	progressBar* MP_Progress;//MP

	//===========================================
	
	tagKey _key[8];//키관련

	

	 int MpCount;//초당 mp줄어드는거

	 //========================

	 int testint;

public:


	//virtual HRESULT init(playerInfo _playerInfo);
	virtual HRESULT init(int maxHp, int currentHp, int maxMp, int currentMp, int Jewel, int gold);
	virtual void release();
	virtual void update();
	virtual void render();




	
	progressBar* getHpProgressBar() { return HP_Progress; }
	progressBar* getMpProgressBar() { return MP_Progress; }
	

};

