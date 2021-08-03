#pragma once
#include "gameNode.h"
#include <vector>


// �̰� ���̾ �ñ״�ó


struct tagiceSpear
{
	dImage* skillImage;		// �̹��� 
	Vector2 _RL, _RR, _RT, _RB; //����Ʈ<- �浹�Ҷ� �������
	RECT rc;				// ��Ʈ
	float x, y;				// ��ǥ(�ǽð�)
	float angle;			// ����
	float radius;			// ������
	float speed;			// ���ǵ�
	float fireX, fireY;		// �߻�� ó�� ��ǥ(�߻�� ��ǥ)
	bool isFire;			//�ߵ�
	int count;				// ������ī��Ʈ��
	RECT rc2;
	bool playerATK;
};

class iceSpear : public gameNode
{
private:
	vector<tagiceSpear>			_vSkill;
	vector<tagiceSpear>::iterator _viSkill;

	int _x2;
	float _range;
	int _SkillMax;
	float _angle;
	int _time;
	bool _go;
public:
	iceSpear() {};
	~iceSpear() {};

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
	vector<tagiceSpear>* getVSkill() { return &_vSkill; }
	vector<tagiceSpear>::iterator getViSkill() { return _viSkill; }

};