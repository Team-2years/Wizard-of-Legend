#pragma once
#include "Scene.h"

class testScene : public Scene
{
private:
	float _x, _y;
	RECT _rc;
	RECT _rc2;

	dImage* _back;
	dImage* _moveImg;

	int _frameX;
	int _frameY;
	float _angle;

	int _count;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void changeScene();
	void controlFrame();
};

