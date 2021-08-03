#include "stdafx.h"
#include "progressBar.h"

HRESULT progressBar::init(string _backGroundBar,string _frontBar, int _currentGuage, int _maxGuage , bool _isUseBeforeGuage)
{



	backGroundBarImg = IMAGEMANAGER->findDImage(_backGroundBar);
	frontBarImg = IMAGEMANAGER->findDImage(_frontBar);
	Hurt_frontBarImg = IMAGEMANAGER->findDImage("HurtHp");



	maxGuage = _maxGuage;
	currentGuage = _currentGuage;
	
	width = frontBarImg->getWidth() *  (float)currentGuage / (float)maxGuage;
	width_hurt = width;


	isUseBeforeGuage = _isUseBeforeGuage;



	return S_OK;
}

void progressBar::release()
{
}

void progressBar::update()
{
	if (isUseBeforeGuage)
	{
		if (width < width_hurt)  width_hurt -= 0.1f;			
		
		else width_hurt = width;
	}

	if (maxGuage < currentGuage) currentGuage = maxGuage;

}

void progressBar::render(int x, int y, int distanceX, int distanceY, float sizeX, float sizeY, float opacity)
{

	backGroundBarImg->scaleRender(x, y, sizeX, sizeY, opacity);

	if (isUseBeforeGuage)
	{
		Hurt_frontBarImg->scaleRender(x + distanceX, y + distanceY, 0, 0, width_hurt, Hurt_frontBarImg->getHeight(), sizeX, sizeY, opacity);
	}

	frontBarImg->scaleRender(x + distanceX, y + distanceY, 0, 0, width, frontBarImg->getHeight(), sizeX, sizeY, opacity);

}

void progressBar::setFrogressBar(int currentGuage, int maxGuage)
{
	

	float x = (float)currentGuage / (float)maxGuage;


 	width = x * (float)frontBarImg->getWidth();
	
}






