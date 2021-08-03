#pragma once
#include "gameNode.h"
#include <vector>


// �̰� ���̾ �ñ״�ó


struct tagbubble
{
	dImage* skillImage;		// �̹��� 
	Vector2 _RL, _RR, _RT, _RB; //����Ʈ<- �浹�Ҷ� �������
	RECT rc;				// ��Ʈ
	RECT rc2;
	float x, y;				// ��ǥ(�ǽð�)
	float angle;			// ����
	float radius;			// ������
	float speed;			// ���ǵ�
	float fireX, fireY;		// �߻�� ó�� ��ǥ(�߻�� ��ǥ)
	bool isFire;			//�ߵ�
	int count;				// ������ī��Ʈ��
	int _time;
	int _r;
	int _count2;
	int _count3;
	bool _RNDOK;
	bool playerATK;

};

class bubble : public gameNode
{
private:
	vector<tagbubble>			_vSkill;
	vector<tagbubble>::iterator _viSkill;

	int _x2;
	float _range;
	int _SkillMax;
	float _angle;
	int _time;
	bool _go;


	int _r2;
public:
	bubble() {};
	~bubble() {};

	HRESULT init(int skillMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, bool playerATK);


	void move();
	void moveGo();

	void removeSkill(int arrNum);

	RECT returnRect() { return _viSkill->rc; }
	RECT returnRect2() { return _viSkill->rc2; }
	vector<tagbubble>* getVSkill() { return &_vSkill; }
	vector<tagbubble>::iterator getViSkill() { return _viSkill; }

};

