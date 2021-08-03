#pragma once

#define RENDERCOUNT		0.05
#define RENDERCOUNT2	RENDERCOUNT * 2

class gameNode
{
private:
	bool _managerInit;

public:
	gameNode();
	virtual ~gameNode();

	//HRESULT ���� ���� ��ȯ�����ε�
	//S_OK, E_FAIL, SUCCEDED
	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual HRESULT init(bool managerInit);
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� �Լ�
	virtual void render();			//�׸��� �Լ�

	void cursorOnWindow();
	//����� ������
	//void setBackBufferSize(float width, float height){ _backBuffer->setwidth}

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);
};