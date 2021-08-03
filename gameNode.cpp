#include "stdafx.h"
#include "gameNode.h"

gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}

HRESULT gameNode::init()
{
	_managerInit = false;

	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_managerInit = managerInit;

	if (_managerInit)
	{
		//SetTimer(_hWnd, 1, 10, NULL);
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		CAMERAMANAGER->init(WINSIZEX, WINSIZEY);
		TIMEMANAGER->init();
		PRINTMANAGER->init();
		STREAMMANAGER->init();
		DTDMANAGER->init();
		RENDERMANAGER->init();
		SAVEDATAMANAGER->init();
	}

	return S_OK;
}

void gameNode::release()
{
	if (_managerInit)
	{
		//KillTimer(_hWnd, 1);
		KEYMANAGER->release();
		KEYMANAGER->releaseSingleton();

		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();

		CAMERAMANAGER->release();
		CAMERAMANAGER->releaseSingleton();

		TIMEMANAGER->release();
		TIMEMANAGER->releaseSingleton();

		PRINTMANAGER->release();
		PRINTMANAGER->releaseSingleton();

		STREAMMANAGER->release();
		STREAMMANAGER->releaseSingleton();

		DTDMANAGER->release();
		DTDMANAGER->releaseSingleton();

		RENDERMANAGER->release();
		RENDERMANAGER->releaseSingleton();

		SAVEDATAMANAGER->release();
		SAVEDATAMANAGER->releaseSingleton();
	}
}

void gameNode::update()
{
}

void gameNode::render()
{
}

void gameNode::cursorOnWindow()
{
	RECT rc;
	//������ ũ�� RECT ����
	GetClientRect(_hWnd, &rc);

	POINT pt1, pt2;

	//������ LeftTop, RightTop�� ��ǥ
	pt1.x = rc.left;
	pt1.y = rc.top;
	pt2.x = rc.right;
	pt2.y = rc.bottom;

	//��ȯ
	ClientToScreen(_hWnd, &pt1);
	ClientToScreen(_hWnd, &pt2);

	//����
	rc.left = pt1.x;
	rc.top = pt1.y;
	rc.right = pt2.x;
	rc.bottom = pt2.y;

	//���콺 ����
	ClipCursor(&rc);
}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	PAINTSTRUCT ps;
	HDC         hdc; //�� �� �߿��մ�...
	RECT rc;
	GetWindowRect(_hWnd, &rc);
	DTDMANAGER->resetWindowSize(rc.right - rc.left, rc.bottom - rc.top);
	float WX = WINSIZEX - 17;
	float WY = WINSIZEY - 40;
	float OX = ORIGINWINSIZEX;
	float OY = ORIGINWINSIZEY;
	switch (iMessage)
	{
		//���콺 �����̸� ���⼭ �޼��� �߻�
	case WM_MOUSEMOVE:
		_ptMouse.x = static_cast<float>(LOWORD(lParam)) * (OX / WX) + CAMERAMANAGER->getOScreen().left;
		_ptMouse.y = static_cast<float>(HIWORD(lParam)) * (OY / WY) + CAMERAMANAGER->getOScreen().top;
		//	_ptMouse.x *= (WINSIZEX / ORIGINWINSIZEX); 
		//	_ptMouse.y *= (WINSIZEY / ORIGINWINSIZEY); 

		break;

	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;

	case WM_ACTIVATEAPP:
		//cursorOnWindow();
		break;

		//������ â �ν���(?) 
	case WM_DESTROY:
		//������ �����Լ�
		PostQuitMessage(0);
		return 0;

		//������â ũ�Ⱑ ���ϸ� �޽��� �߻�
	case WM_SIZE:
		UINT width = LOWORD(lParam);
		UINT height = HIWORD(lParam);
		RECT rc;
		GetWindowRect(_hWnd, &rc);
		DTDMANAGER->resetWindowSize(rc.right - rc.left, rc.bottom - rc.top);

		break;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}