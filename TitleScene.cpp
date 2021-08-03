#include "stdafx.h"
#include "TitleScene.h"

HRESULT TitleScene::init()
{

	first_opacity = backGround_opacity = title_opacity = 0.0f;
	logo_opacity = 1.0f; 
	fade = false;
	titleOn = false;
	logoY = 0;
	titleRect = RectMakeCenter(WINSIZEX / 2 ,WINSIZEY/2,
		IMAGEMANAGER->findDImage("logo")->getWidth(), IMAGEMANAGER->findDImage("logo")->getHeight());

	mouseRect = RectMakeCenter(_ptMouse.x, _ptMouse.y, 5, 5);

	MenuRect = RectMake(WINSIZEX / 2-100, titleRect.bottom, 200+20, 600);

	OptionUIrect = RectMake(WINSIZEX / 2 - 200, 20, (WINSIZEX / 3) * 2, WINSIZEY-20);

	GameStartRect = dRectMake(MenuRect.left-30, MenuRect.top, 230, 40);
	DoublePlayerRect=dRectMake(MenuRect.left-30, GameStartRect.top,230,40);
	FightRect = dRectMake(MenuRect.left - 30, DoublePlayerRect.top, 230, 40) ;
	OptionRect = dRectMake(MenuRect.left - 30, FightRect.top, 230, 40);
	ProducerRect = dRectMake(MenuRect.left - 30, OptionRect.top, 230, 40);
	ExitRect = dRectMake(MenuRect.left - 30, ExitRect.top, 230, 40);

	isClickOption = false;

	SelectMenu = false;
	return S_OK;
}

void TitleScene::release()
{
}

void TitleScene::update()
{

	//=======================맨첫화면===================================
	if (first_opacity > 1.0f) fade = true;

	if(!fade) first_opacity += 0.01f;
	else if(first_opacity >0.0f) first_opacity -= 0.01f;
	
	if (first_opacity < 0.0f && !titleOn)
	{
		if (title_opacity < 1.0f)
		{
			title_opacity += 0.01f;
			backGround_opacity += 0.01f;
		}
		else
		{
			titleOn = true;
			title_opacity = 1.0f;
			backGround_opacity = 1.0f;

		}
	}

	//=================================================================

	if (titleOn)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (!SelectMenu && !isClickOption) SelectMenu = true;

			if (logoY == -LOGOY)
			{
				RECT temp;

				if (isClickOption)
				{

				}
				
				else
				{
					if (IntersectRect(&temp, &mouseRect, &changeRect(GameStartRect))) SCENEMANAGER->changeScene("집씬");
					if (IntersectRect(&temp, &mouseRect, &changeRect(OptionRect))) isClickOption = true;
					if (IntersectRect(&temp, &mouseRect, &changeRect(ExitRect))) PostQuitMessage(0);
				}
			}
		}

		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			if (isClickOption) isClickOption = false;
			else
			{
				if (SelectMenu) SelectMenu = false;
			}
		}
		
	}

	//타이틀 들어왔을경우 
	if (titleOn)
	{
		if (SelectMenu)
		{
			//로고 올라가면서 fadeIn 되는거
			if (logoY > -LOGOY) logoY -= 10;
			else logoY = -LOGOY;
			if (backGround_opacity > 0.3f) backGround_opacity -= 0.05f;
		}
		else
		{
			//로고 내려가면서 fadeOut되는거
			if (logoY < 0)logoY += 10;
			else logoY = 0;
			if (backGround_opacity < 1.0f) backGround_opacity += 0.05f;
		}


	}

	titleRect = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2 + logoY + 50 ,
		IMAGEMANAGER->findDImage("logo")->getWidth(), IMAGEMANAGER->findDImage("logo")->getHeight());
	mouseRect = RectMakeCenter(_ptMouse.x, _ptMouse.y, 5, 5);

	if (logoY == -LOGOY)
	{
		MenuRect = RectMake(WINSIZEX / 2 - 100, titleRect.bottom+20, 200, 400);
		GameStartRect = dRectMake(MenuRect.left - 30, MenuRect.top+20, 230, 40);
		DoublePlayerRect = dRectMake(MenuRect.left - 30, GameStartRect.bottom + 20, 230, 40);
		FightRect = dRectMake(MenuRect.left - 30, DoublePlayerRect.bottom + 20, 230, 40);
		OptionRect = dRectMake(MenuRect.left - 30, FightRect.bottom + 20, 230, 40);
		ProducerRect = dRectMake(MenuRect.left - 30, OptionRect.bottom + 20, 230, 40);
		ExitRect = dRectMake(MenuRect.left - 30, ProducerRect.bottom + 20, 230, 40);
	}
} 

void TitleScene::render()
{
	IMAGEMANAGER->findDImage("fade")->render(0,0);
	IMAGEMANAGER->findDImage("컨트롤러")->render(WINSIZEX / 2 - IMAGEMANAGER->findDImage("컨트롤러")->getWidth() / 2,
												WINSIZEY / 2 - IMAGEMANAGER->findDImage("컨트롤러")->getHeight() / 2,
											first_opacity);

	if (first_opacity < 0.0f)
	{
		IMAGEMANAGER->findDImage("BG")->render(0,0,backGround_opacity);
		IMAGEMANAGER->findDImage("logo")->render(titleRect.left, titleRect.top, title_opacity);
		
		if (titleOn) IMAGEMANAGER->findDImage("sideIcon")->render(WINSIZEX - 150, WINSIZEY - 200, 1.0f);
		else IMAGEMANAGER->findDImage("sideIcon")->render(WINSIZEX - 150, WINSIZEY - 200, title_opacity);

		if (SelectMenu)
		{
			DTDMANAGER->Rectangle(titleRect);
			DTDMANAGER->Rectangle(MenuRect);
			DTDMANAGER->Rectangle(GameStartRect);
			DTDMANAGER->Rectangle(DoublePlayerRect);
			DTDMANAGER->Rectangle(FightRect);
			DTDMANAGER->Rectangle(OptionRect);
			DTDMANAGER->Rectangle(ProducerRect);
			DTDMANAGER->Rectangle(ExitRect);


			 if(logoY==-LOGOY)DTDMANAGER->printText_LT(L"싱글 플레이어", GameStartRect.left +25, GameStartRect.top,230,40);

			 if (isClickOption)
			 {
				 DTDMANAGER->Rectangle(OptionUIrect);
				 IMAGEMANAGER->findDImage("옵션창")->render(OptionUIrect.left, OptionUIrect.top);
			 }
		}

	}


	DTDMANAGER->Rectangle(mouseRect);
}
