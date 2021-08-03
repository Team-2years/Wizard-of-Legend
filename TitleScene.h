#pragma once
#include "stdafx.h"
#include "gameNode.h"

#define LOGOY 180

class TitleScene :
	public gameNode
{
private:

	float first_opacity;
	float backGround_opacity;
	float title_opacity;
	float logo_opacity;
	bool fade;
	bool titleOn;
	bool SelectMenu;
	
	RECT titleRect;
	RECT mouseRect;

	bool isClickOption;
	RECT OptionUIrect;
	

	RECT MenuRect;
	D2D1_RECT_F GameStartRect;
	D2D1_RECT_F DoublePlayerRect;
	D2D1_RECT_F FightRect;
	D2D1_RECT_F OptionRect;
	D2D1_RECT_F ProducerRect;
	D2D1_RECT_F ExitRect;


	D2D1_RECT_F titleText;

	int logoY;
	

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


};

