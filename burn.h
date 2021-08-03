#pragma once
#include "gameNode.h"
#include <vector>

// �̰� ���̾ �ñ״�ó


struct tagburn
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

};

class burn : public gameNode
{
private:
	vector<tagburn>			_vSkill;
	vector<tagburn>::iterator _viSkill;

	int _x2;
	float _range;
	int _SkillMax;
	float _angle;
	int _time;
	int _frame;
public:
	burn() {};
	~burn() {};

	HRESULT init(int skillMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, int frame ,float angle);

	void move();


	void removeSkill(int arrNum);

	RECT returnRect() { return _viSkill->rc; }
	RECT returnRect2() { return _viSkill->rc2; }
	vector<tagburn> getVSkill() { return _vSkill; }
	vector<tagburn>::iterator getViSkill() { return _viSkill; }

};