#pragma once
#include "stdafx.h"
#include "gameNode.h"
class progressBar :
	public gameNode
{
private:

	dImage* backGroundBarImg;
	dImage* frontBarImg;
	dImage* Hurt_frontBarImg;

	int maxGuage;
	int currentGuage;
	int Guage;

	float width;
	float width_hurt;

	bool isUseBeforeGuage;



public:

	 HRESULT init(string _backGroundBar, string _frontBar, int _currentGuage,int _maxGuage, bool _isUseBeforeGuage);
	 void release();
	 void update();
	 void render(int x, int y ,int distanceX=0, int distanceY=0, float sizeX = 1.0f, float sizeY=1.0f ,float opacity = 1.0f);

	 dImage* getbackGroundBar() { return backGroundBarImg; }
	 dImage* getfrontBarImg() { return frontBarImg; }

	 float getCurrentGuage() { return currentGuage; }


	void setFrogressBar(int currentGuage,int maxGuage);



};

