#pragma once
#include "gameNode.h"
#include <vector>
#include "burn.h"


struct tagfireCross
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
	int _time;
	RECT rc2;
	bool playerATK;
};

class fireCross : public gameNode
{
private:
	vector<tagfireCross>			_vSkill;
	vector<tagfireCross>::iterator _viSkill;

	int _x2;
	float _range;
	int _SkillMax;
	float _angle;
	int _time;
	burn* _burn;
public:
	fireCross() {};
	~fireCross() {};

	HRESULT init(int skillMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, bool playerATK);


	void move();


	void removeSkill(int arrNum);

	RECT returnRect() { return _viSkill->rc; }
	RECT returnRect2() { return _viSkill->rc2; }
	vector<tagfireCross>* getVSkill() { return &_vSkill; }
	vector<tagfireCross>::iterator getViSkill() { return _viSkill; }

};