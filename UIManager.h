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
	//���߿� Ű�� ���� ���� �߰��ϱ�
};

class UIManager : public gameNode
{
private:

	
	//=============ȭ�鿡 �ߴ� ����===============

	dImage* _playerPicture;//�÷��̾� ������
	dImage* backGroundPicture;//�÷��̾� ������ ���� ��׶���
	
	progressBar* HP_Progress;//HP
	progressBar* MP_Progress;//MP

	//===========================================
	
	tagKey _key[8];//Ű����

	

	 int MpCount;//�ʴ� mp�پ��°�

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

