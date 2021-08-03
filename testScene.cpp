#include "stdafx.h"
#include "testScene.h"

HRESULT testScene::init()
{
	CAMERAMANAGER->setBackScreenSize(3840, 2160);

	_back = IMAGEMANAGER->addDImage("back", L"img/sample1.jpg", 3840, 2160);
	_moveImg = IMAGEMANAGER->addFrameDImage("booster", L"img/idle1.png", 156, 54, 3, 1);

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;

	_frameX = 0;
	_frameY = 0;
	_angle = 0;
	return S_OK;
}

void testScene::release()
{
}

void testScene::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		_x -= 5;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		_x += 5;
	if (KEYMANAGER->isStayKeyDown(VK_UP))
		_y -= 5;
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		_y += 5;

	_rc = RectMakeCenter(_x, _y, 100, 300);
	_rc2 = RectMakeCenter(_ptMouse.x, _ptMouse.y, 100, 100);

	CAMERAMANAGER->updateScreen(_x, _y);
	_angle++;
	_angle = (int)_angle % 360;

	RECT temp;
	if (IntersectRect(&temp, &_rc2, &_rc))
	{
		DTDMANAGER->setBrushColor(ColorF(ColorF::Red));
	}
	else
	{
		DTDMANAGER->setBrushColor(ColorF(ColorF::Aqua));
	}

}


void testScene::render()
{
	controlFrame();

	
	_back->render();
	DTDMANAGER->setRotation(_angle, _x, _y);
	_moveImg->frameRender(_rc.left, _rc.top, _frameX, _frameY);

	DTDMANAGER->setRotation(-_angle, _x, _y);
	DTDMANAGER->Rectangle(_rc);

	DTDMANAGER->resetRotation();
	DTDMANAGER->Rectangle(_rc2);
}

void testScene::changeScene()
{
}

void testScene::controlFrame()
{
	_count++;

	if (_count > 5) {
		if (_frameX >= _moveImg->getMaxFrameX())
			_frameX = 0;
		else
			_frameX++;

		_count = 0;
	}
}
