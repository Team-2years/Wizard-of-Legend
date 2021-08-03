#include "stdafx.h"
#include "Home_Arcana.h"

#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

HRESULT Home_Arcana::init()
{
	first = RectMake(35, 190, WINSIZEX / 2, 313);
	//35,190
	//35,513
	PanelPoint = PointMake(35, 190);
	//SpellBookPoint = PointMake(125, 40);
	SpellBookPoint = PointMake(-700, 40);

	for (int i = 0; i < 4; i++)
	{
		HomeUI_Arcana[i].firstCard_xy = PointMake( PanelPoint.x + 49 + (130)*i ,PanelPoint.y + 65);
		HomeUI_Arcana[i].firstCardImg = IMAGEMANAGER->findDImage("�Ƹ�ī�� �ո�");
		HomeUI_Arcana[i].ArcanaBookImg = IMAGEMANAGER->findDImage("����� ����");		
		HomeUI_Arcana[i].isOpenSpellBook = false;		
		HomeUI_Arcana[i].isSelect_firstCard = false;

		HomeUI_Arcana[i].ArcanaElements = FIRE;

		switch (i)
		{
		case 0:	HomeUI_Arcana[i].Kind = Arcana_Kind_Basic;
			HomeUI_Arcana[i].isSelect_firstCard = true;
			break;
		case 1: HomeUI_Arcana[i].Kind = Arcana_Kind_Movement;
			break;
		case 2: HomeUI_Arcana[i].Kind = Arcana_Kind_Standard;
			break;
		case 3: HomeUI_Arcana[i].Kind = Arcana_Kind_Signiture;
			break;
		}
		
		for (int j = ELEMENT_MIN; j < ELEMENT_MAX; j++)
		{
			switch (j)
			{
			case 0: HomeUI_Arcana[i].ArcanaList[j].ArcanaBookElementIconImg = IMAGEMANAGER->findDImage("������_��");
				HomeUI_Arcana[i].ArcanaList[j].ArcanaBookElementImg = IMAGEMANAGER->findDImage("�׵θ�_��");
				HomeUI_Arcana[i].ArcanaList[j].ArcanaBookTabImage = IMAGEMANAGER->findDImage("��_��");
				HomeUI_Arcana[i].ArcanaList[j].index = 0;

				//HomeUI_Arcana[i].ArcanaList[j].ArcanaCardImage = IMAGEMANAGER->findDImage("�Ƹ�ī�� �ո�");

				break;
			case 1: HomeUI_Arcana[i].ArcanaList[j].ArcanaBookElementIconImg = IMAGEMANAGER->findDImage("������_�ٶ�");
				HomeUI_Arcana[i].ArcanaList[j].ArcanaBookElementImg = IMAGEMANAGER->findDImage("�׵θ�_�ٶ�");
				HomeUI_Arcana[i].ArcanaList[j].ArcanaBookTabImage = IMAGEMANAGER->findDImage("��_�ٶ�");
				HomeUI_Arcana[i].ArcanaList[j].index = 0;

				//HomeUI_Arcana[i].ArcanaList[j].ArcanaCardImage = IMAGEMANAGER->findDImage("�Ƹ�ī�� �ո�");
				break;
			case 2: HomeUI_Arcana[i].ArcanaList[j].ArcanaBookElementIconImg = IMAGEMANAGER->findDImage("������_��");
				HomeUI_Arcana[i].ArcanaList[j].ArcanaBookElementImg = IMAGEMANAGER->findDImage("�׵θ�_��");
				HomeUI_Arcana[i].ArcanaList[j].ArcanaBookTabImage = IMAGEMANAGER->findDImage("��_��");
				HomeUI_Arcana[i].ArcanaList[j].index = 0;

			//	HomeUI_Arcana[i].ArcanaList[j].ArcanaCardImage = IMAGEMANAGER->findDImage("�Ƹ�ī�� �ո�");
				break;
			case 3: HomeUI_Arcana[i].ArcanaList[j].ArcanaBookElementIconImg = IMAGEMANAGER->findDImage("������_����");
				HomeUI_Arcana[i].ArcanaList[j].ArcanaBookElementImg = IMAGEMANAGER->findDImage("�׵θ�_����");
				HomeUI_Arcana[i].ArcanaList[j].ArcanaBookTabImage = IMAGEMANAGER->findDImage("��_����");
				HomeUI_Arcana[i].ArcanaList[j].index = 0;

				//HomeUI_Arcana[i].ArcanaList[j].ArcanaCardImage = IMAGEMANAGER->findDImage("�Ƹ�ī�� �ո�");
				break;
			case 4: HomeUI_Arcana[i].ArcanaList[j].ArcanaBookElementIconImg = IMAGEMANAGER->findDImage("������_��");
				HomeUI_Arcana[i].ArcanaList[j].ArcanaBookElementImg = IMAGEMANAGER->findDImage("�׵θ�_��");
				HomeUI_Arcana[i].ArcanaList[j].ArcanaBookTabImage = IMAGEMANAGER->findDImage("��_��");
				HomeUI_Arcana[i].ArcanaList[j].index = 0;

				//HomeUI_Arcana[i].ArcanaList[j].ArcanaCardImage = IMAGEMANAGER->findDImage("�Ƹ�ī�� �ո�");
				break;
			}
		}
	
	}

	currentArcanaIndex = 0;
	currentArcanaElement = FIRE;




	currentCard.ArcanaCardImage = IMAGEMANAGER->findDImage("�Ƹ�ī�� �ո�");
	currentCard.ArcanaStartPosition = PointMake(SpellBookPoint.x + 255,SpellBookPoint.y + 200);
	currentCard.ArcanaCurrentPosition = currentCard.ArcanaStartPosition;
	currentCard.isPickUpCard = false;
	currentCard.isDrop = false;

	//125,40
	//380,240

	//94,255
	//199,255
	//94,510
	/*
	ī�� ���� 104

	���� 255

	�Ƹ�ī�� �ո�
	*/

	return S_OK;
}

void Home_Arcana::release()
{
}

void Home_Arcana::update()
{

	//����� ����
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) HomeUI_Arcana[currentArcanaIndex].isOpenSpellBook = HomeUI_Arcana[currentArcanaIndex].isOpenSpellBook ? false : true;

	//=========================����� ���½� �����̰� �ϴ� �Լ�===========================
	if (HomeUI_Arcana[currentArcanaIndex].isOpenSpellBook)
	{
		if (PanelPoint.y < WINSIZEY + 10)
		{
			PanelPoint.y += 60;
			for(int i=0; i<4;i++) HomeUI_Arcana[i].firstCard_xy = PointMake(PanelPoint.x + 49 + (70+130)*i, PanelPoint.y + 65);
		}

		if (SpellBookPoint.x < 125) SpellBookPoint.x += 60;
		else SpellBookPoint.x = 125;		
	}
	else
	{
		if (PanelPoint.y > 190) PanelPoint.y -= 60;
		else
		{
			PanelPoint.y = 190;
			moveSpeed = PointMake(currentCard.ArcanaCurrentPosition.x - HomeUI_Arcana[currentArcanaIndex].firstCard_xy.x,
				currentCard.ArcanaCurrentPosition.y - HomeUI_Arcana[currentArcanaIndex].firstCard_xy.y);
		}
		for (int i = 0; i < 4; i++) HomeUI_Arcana[i].firstCard_xy = PointMake(PanelPoint.x + 49 + (70+130)*i, PanelPoint.y + 65);

		if (SpellBookPoint.x > -700) SpellBookPoint.x -= 60;
		else SpellBookPoint.x = -700;
	}
	//===================================================================================

	if (HomeUI_Arcana[currentArcanaIndex].isOpenSpellBook)
	{
		HomeUI_Arcana[currentArcanaIndex].ArcanaList[currentArcanaElement].index = 1;


		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			if (!currentCard.isPickUpCard) currentCard.isPickUpCard = true;
			currentCard.ArcanaEndPosition = HomeUI_Arcana[currentArcanaIndex].firstCard_xy;
		}
		
	}
	
	if (!currentCard.isPickUpCard)
	{
		currentCard.ArcanaStartPosition = PointMake(SpellBookPoint.x + 255, SpellBookPoint.y + 200);
		currentCard.ArcanaCurrentPosition = currentCard.ArcanaStartPosition;
	}
	else
	{
		

		if (!currentCard.isDrop)
		{
			if (currentCard.ArcanaStartPosition.y - currentCard.ArcanaCurrentPosition.y < 250)
			{
				currentCard.ArcanaCurrentPosition.y -= 10;
			}
			else
			{
				currentCard.ArcanaCurrentPosition.y = currentCard.ArcanaStartPosition.y - 250;
				currentCard.isDrop = true;

	

				HomeUI_Arcana[currentArcanaIndex].isOpenSpellBook = false;
			}
		}
		else
		{
			if (PanelPoint.y == 190)
			{


				if (getDistance(HomeUI_Arcana[currentArcanaIndex].firstCard_xy.x, HomeUI_Arcana[currentArcanaIndex].firstCard_xy.y,
					currentCard.ArcanaCurrentPosition.x, currentCard.ArcanaCurrentPosition.y) > 30)
				{
					currentCard.ArcanaCurrentPosition.x -= (moveSpeed.x / 10);
					currentCard.ArcanaCurrentPosition.y -= (moveSpeed.y / 10);
				}
				else
				{
					currentCard.ArcanaCurrentPosition = HomeUI_Arcana[currentArcanaIndex].firstCard_xy;
					currentCard.isDrop = false;
					currentCard.isPickUpCard = false;
				}
			}
		}
	}

	//420,172
	//125
	


	//============================���Һ� �Ƹ�ī�� ����=================================================
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (currentArcanaElement > ELEMENT_MIN)
		{
			HomeUI_Arcana[currentArcanaIndex].ArcanaList[currentArcanaElement].index = 0;
			currentArcanaElement--;
		}
		else currentArcanaElement = ELEMENT_MIN;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (currentArcanaElement < ELEMENT_MAX - 1)
		{
			HomeUI_Arcana[currentArcanaIndex].ArcanaList[currentArcanaElement].index = 0;
			currentArcanaElement++;
		}
		else currentArcanaElement = ELEMENT_MAX-1;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		currentArcanaIndex = currentArcanaIndex < 3 ? currentArcanaIndex +1 : currentArcanaIndex = 3;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		currentArcanaIndex = currentArcanaIndex > 0 ? currentArcanaIndex - 1 : currentArcanaIndex = 0;
	}
	//==============================================================================================

}

void Home_Arcana::render()
{
	//DTDMANAGER->Rectangle(first);
	IMAGEMANAGER->findDImage("�Ƹ�ī�� PANEL")->render(PanelPoint.x,PanelPoint.y,0.6f);
	

	//ī��
	for (int i = 0; i < 4; i++) HomeUI_Arcana[i].firstCardImg->render(HomeUI_Arcana[i].firstCard_xy.x, HomeUI_Arcana[i].firstCard_xy.y, 0.6f);
	

	//å
	HomeUI_Arcana[currentArcanaIndex].ArcanaBookImg->render(SpellBookPoint.x, SpellBookPoint.y);

		//��� ����
		if (currentArcanaElement == FIRE)
		{
			HomeUI_Arcana[currentArcanaIndex].ArcanaList[currentArcanaElement].ArcanaBookElementIconImg->frameRender(SpellBookPoint.x + 297, SpellBookPoint.y + 128-5,
				HomeUI_Arcana[currentArcanaIndex].ArcanaList[currentArcanaElement].index, 0);
		}
		else
		{
			HomeUI_Arcana[currentArcanaIndex].ArcanaList[currentArcanaElement].ArcanaBookElementIconImg->frameRender(SpellBookPoint.x + 297, SpellBookPoint.y + 128,
				HomeUI_Arcana[currentArcanaIndex].ArcanaList[currentArcanaElement].index, 0);
		}

		//��
		for (int i = 0; i < ELEMENT_MAX; i++)
		{
			HomeUI_Arcana[currentArcanaIndex].ArcanaList[i].ArcanaBookTabImage->frameRender(SpellBookPoint.x + 601,
				SpellBookPoint.y + 95 + (87+10) * i, HomeUI_Arcana[currentArcanaIndex].ArcanaList[i].index, 0);
		}

		//�׵θ�
		HomeUI_Arcana[currentArcanaIndex].ArcanaList[currentArcanaElement].ArcanaBookElementImg->render(SpellBookPoint.x, SpellBookPoint.y);
		currentCard.ArcanaCardImage->render(currentCard.ArcanaCurrentPosition.x, currentCard.ArcanaCurrentPosition.y);

		cout << "���� �Ƹ�ī�� �ε��� : " << currentArcanaIndex << endl;

}


