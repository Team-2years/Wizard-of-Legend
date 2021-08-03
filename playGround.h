#pragma once
#include "gameNode.h"
//#include "TileClass.h"
//#include "BinaryMapTree.h"
//#include "player.h"

#include "TitleScene.h"
#include "testField.h"


class playGround : public gameNode
{
private:
	//player* _player;
	//TileClass* _tile;
	//BinaryMapTree* _binary;
	//bool _debug;


public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void playerImage();
	void UIandItemImage();
	void enemyImage();


};