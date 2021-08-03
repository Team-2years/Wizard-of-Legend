#include "stdafx.h"
#include "playGround.h"
#include "testScene.h"
#include "dg.h"
#include "home.h"
#include "village.h"
playGround::playGround()
{
}


playGround::~playGround()
{
}

//ÃÊ±âÈ­´Â ¿©±â´Ù ÇÏ¼¼¿ä Á¦¹ß
HRESULT playGround::init()
{
	gameNode::init(true);
	enemyImage();
	playerImage();
	UIandItemImage();
	IMAGEMANAGER->addFrameDImage("MapAir", L"img/mapSprite/MapTileset_Air.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("MapCastleBase", L"img/mapSprite/MapTileset_CastleBase.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("MapCastle", L"img/mapSprite/MapTileset_Castle.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("MapCourtyard", L"img/mapSprite/MapTileset_Courtyard.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("MapEarth", L"img/mapSprite/MapTileset_Earth.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("MapFire", L"img/mapSprite/MapTileset_Fire.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("MapHome", L"img/mapSprite/MapTileset_Home.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("MapIce", L"img/mapSprite/MapTileset_Ice.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("MapLightning", L"img/mapSprite/MapTileset_Lightning.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("MapMuseum", L"img/mapSprite/MapTileset_Museum.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("MapPlaza", L"img/mapSprite/MapTileset_Plaza.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("MapPrison", L"img/mapSprite/MapTileset_Prison.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("MapBlack", L"img/mapSprite/MapTileset_Black.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("Obj1", L"img/objSprite/obj1.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("Obj2", L"img/objSprite/obj2.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("ObjStore", L"img/objSprite/objStore.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("ObjWood", L"img/objSprite/objWood.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("ObjIce1", L"img/objSprite/objIce1.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("ObjIce2", L"img/objSprite/objIce2.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("ObjTrees", L"img/objSprite/objTrees.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameDImage("ObjStatue", L"img/objSprite/objStatue.png", 512, 512, SAMPLETILEX, SAMPLETILEY);


	//ÆÄÆ¼Å¬ ¹× ½ºÅ³
	EFFECTMANAGER->addEffect("½ºÅ³Æø¹ß", "ÇØ°ñ½ºÄÃ Æø¹ß.png", 7200, 540, 480, 540, 1, 0.5f, 5);
	PARTICLEMANAGER->addParticle("½ºÅ³Æø¹ß", "ÇØ°ñ½ºÄÃ Æø¹ß.png", 7200, 540, 480, 540, 1, 0.5f, 5);
	PARTICLEMANAGER->addParticle("ºÒ²É1", "skill/ºÒ²É1.png", 66, 13, 11, 13, 1, 0.5f, 5);
	PARTICLEMANAGER->addParticle("¹éºÒ²É1", "skill/ºÒ²É1_¹é.png", 66, 13, 11, 13, 1, 0.5f, 5);
	PARTICLEMANAGER->addParticle("È²ºÒ²É1", "skill/ºÒ²É1_È².png", 66, 13, 11, 13, 1, 0.5f, 5);
	PARTICLEMANAGER->addParticle("ºÒ²É2", "skill/ºÒ²É2.png", 54, 10, 9, 10, 1, 0.5f, 5);
	PARTICLEMANAGER->addParticle("¹éºÒ²É2", "skill/ºÒ²É2_¹é.png", 54, 10, 9, 10, 1, 0.5f, 5);
	PARTICLEMANAGER->addParticle("È²ºÒ²É2", "skill/ºÒ²É2_È².png", 54, 10, 9, 10, 1, 0.5f, 5);
	PARTICLEMANAGER->addParticle("ºÒ²É3", "skill/ºÒ²É3.png", 66, 13, 11, 13, 1, 0.5f, 5);
	PARTICLEMANAGER->addParticle("¹éºÒ²É3", "skill/ºÒ²É3_¹é.png", 66, 13, 11, 13, 1, 0.5f, 5);
	PARTICLEMANAGER->addParticle("È²ºÒ²É3", "skill/ºÒ²É3_È².png", 66, 13, 11, 13, 1, 0.5f, 5);
	PARTICLEMANAGER->addParticle("ºÒ²É4", "skill/ºÒ²É4.png", 60, 13, 10, 13, 1, 0.5f, 5);
	PARTICLEMANAGER->addParticle("¹éºÒ²É4", "skill/ºÒ²É4_¹é.png", 60, 13, 10, 13, 1, 0.5f, 5);
	PARTICLEMANAGER->addParticle("È²ºÒ²É4", "skill/ºÒ²É4_È².png", 60, 13, 10, 13, 1, 0.5f, 5);
	PARTICLEMANAGER->addParticle("È­¿°Æã", "skill/È­¿°Æã.png", 170, 81, 85, 81, 1, 0.5f, 50);
	PARTICLEMANAGER->addParticle("È­¿°±¸Æã", "skill/explosion.png", 384, 64, 64, 64, 1, 0.5f, 50);
	PARTICLEMANAGER->addParticle("¾óÀ½Æã", "skill/¾óÀ½Æã.png", 117, 40, 39, 40, 1, 0.3f, 5);
	PARTICLEMANAGER->addParticle("¹öºíÆã", "skill/¹öºíÅÍÁö±â.png", 128, 32, 32, 32, 1, 0.3f, 5);

	SCENEMANAGER->addScene("Å×½ºÆ®¾À", new testField);
	SCENEMANAGER->addScene("Å¸ÀÌÆ²¾À", new TitleScene);
	SCENEMANAGER->addScene("´øÀü¾À", new dg);
	SCENEMANAGER->addScene("Áý¾À", new home);
	SCENEMANAGER->addScene("¸¶À»¾À", new village);
	SCENEMANAGER->changeScene("Å¸ÀÌÆ²¾À");

	//_tile = new TileClass;
	//_tile->init();
	CAMERAMANAGER->setBackScreenSize(4500,4500);
	//_player = new player;
	//_player->init();
	return S_OK;
}

//¸Þ¸ð¸® ÇØÁ¦´Â ¿©±â´Ù ÇÏ¼¼¿ä Á¦¹ß
void playGround::release()
{
	gameNode::release();


}


void playGround::update()
{
	gameNode::update();
	//_tile->update();
	//_player->update();
	if (KEYMANAGER->isOnceKeyDown(VK_F6)) 
	{
		SCENEMANAGER->changeScene("Å¸ÀÌÆ²¾À");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F7))
	{
		SCENEMANAGER->changeScene("Å×½ºÆ®¾À");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F8))
	{
		SCENEMANAGER->changeScene("´øÀü¾À");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F9))
	{
		SCENEMANAGER->changeScene("Áý¾À");

	}
	if (KEYMANAGER->isOnceKeyDown(VK_F10))
	{
		SCENEMANAGER->changeScene("¸¶À»¾À");

	}
	SCENEMANAGER->update();
	PARTICLEMANAGER->update();
	EFFECTMANAGER->update();
	RENDERMANAGER->cameraUpdate();
	if (KEYMANAGER->isOnceKeyDown(VK_INSERT)) SCENEMANAGER->changeScene("Å¸ÀÌÆ²¾À");
}


void playGround::render()
{
	
	DTDMANAGER->beginDraw();
	//================Á¦¹ß ÀÌ »çÀÌ¿¡ Á» ±×¸³½Ã´Ù==========================

	SCENEMANAGER->render();
	EFFECTMANAGER->render();
	PARTICLEMANAGER->render();
	//_tile->render();
	//_player->render();
	DTDMANAGER->endDraw();
	//==================================================s
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	//CAMERAMANAGER->render(getHDC(), 0, 0, getMemDC());
	if (DTDMANAGER->getRender()) 
	{
		DTDMANAGER->renderEnd();
	}
	else 
	{
		DTDMANAGER->trueRender();
	}
}

void playGround::playerImage()
{
	// Image
	IMAGEMANAGER->addDImage("WizardIdleDown", L"img/player/WizardIdleDown.png", 20, 36);
	IMAGEMANAGER->addDImage("WizardIdleLeft", L"img/player/WizardIdleLeft.png", 16, 37);
	IMAGEMANAGER->addDImage("WizardIdleRight", L"img/player/WizardIdleRight.png", 16, 37);
	IMAGEMANAGER->addDImage("WizardIdleUp", L"img/player/WizardIdleUp.png", 20, 36);

	IMAGEMANAGER->addFrameDImage("WizardRunDown", L"img/player/WizardRunDown.png", 480, 48, 10, 1);
	IMAGEMANAGER->addFrameDImage("WizardRunLeft", L"img/player/WizardRunLeft.png", 480, 48, 10, 1);
	IMAGEMANAGER->addFrameDImage("WizardRunRight", L"img/player/WizardRunRight.png", 480, 48, 10, 1);
	IMAGEMANAGER->addFrameDImage("WizardRunUp", L"img/player/WizardRunUp.png", 480, 48, 10, 1);

	IMAGEMANAGER->addFrameDImage("WizardSlideLeft", L"img/player/WizardSlideLeft.png", 288, 48, 6, 1);
	IMAGEMANAGER->addFrameDImage("WizardSlideRight", L"img/player/WizardSlideRight.png", 288, 48, 6, 1);
	IMAGEMANAGER->addFrameDImage("SlideDown", L"img/player/SlideDown.png", 78, 36, 3, 1);
	IMAGEMANAGER->addFrameDImage("SlideUp", L"img/player/SlideUp.png", 52, 36, 2, 1);

	IMAGEMANAGER->addFrameDImage("WizardDashLeft", L"img/player/WizardDashLeft.png", 96, 48, 2, 1);
	IMAGEMANAGER->addFrameDImage("WizardDashRight", L"img/player/WizardDashRight.png", 96, 48, 2, 1);
	IMAGEMANAGER->addDImage("WizardDashUp", L"img/player/WizardDashUp.png", 32, 24);
	IMAGEMANAGER->addDImage("WizardDashDown", L"img/player/WizardDashDown.png", 28, 32);

	IMAGEMANAGER->addFrameDImage("WizardBackhandDown", L"img/player/WizardBackhandDown.png", 432, 48, 9, 1);
	IMAGEMANAGER->addFrameDImage("WizardBackhandLeft", L"img/player/WizardBackhandLeft.png", 324, 40, 9, 1);
	IMAGEMANAGER->addFrameDImage("WizardBackhandRight", L"img/player/WizardBackhandRight.png", 324, 40, 9, 1);
	IMAGEMANAGER->addFrameDImage("WizardBackhandUp", L"img/player/WizardBackhandUp.png", 528, 48, 11, 1);

	IMAGEMANAGER->addFrameDImage("WizardForehandDown", L"img/player/WizardForehandDown.png", 432, 48, 9, 1);
	IMAGEMANAGER->addFrameDImage("WizardForehandLeft", L"img/player/WizardForehandLeft.png", 288, 36, 8, 1);
	IMAGEMANAGER->addFrameDImage("WizardForehandRight", L"img/player/WizardForehandRight.png", 288, 36, 8, 1);
	IMAGEMANAGER->addFrameDImage("WizardForehandUp", L"img/player/WizardForehandUp.png", 576, 48, 12, 1);

	IMAGEMANAGER->addFrameDImage("WizardDeadDown1", L"img/player/WizardDeadDown1.png", 324, 50, 9, 1);
	IMAGEMANAGER->addDImage("WizardDeadDown", L"img/player/WizardDeadDown.png", 28, 25);

	IMAGEMANAGER->addDImage("WizardFallDown", L"img/player/WizardFallDown.png", 28, 40);
	IMAGEMANAGER->addFrameDImage("WizardFallLeft", L"img/player/WizardFallLeft.png", 64, 42, 2, 1);
	IMAGEMANAGER->addFrameDImage("WizardFallRight", L"img/player/WizardFallRight.png", 64, 42, 2, 1);
	IMAGEMANAGER->addDImage("WizardFallUp", L"img/player/WizardFallUp.png", 28, 42);

	IMAGEMANAGER->addFrameDImage("WizardGetUp", L"img/player/WizardGetUp.png", 84, 32, 3, 1);

	IMAGEMANAGER->addFrameDImage("WizardGroundSlamDown", L"img/player/WizardGroundSlamDown.png", 480, 48, 10, 1);
	IMAGEMANAGER->addFrameDImage("WizardGroundSlamUp", L"img/player/WizardGroundSlamUp.png", 480, 48, 10, 1);

	IMAGEMANAGER->addFrameDImage("WizardPBAoEDown", L"img/player/WizardPBAoEDown.png", 432, 48, 9, 1);
	IMAGEMANAGER->addFrameDImage("WizardPBAoELeft", L"img/player/WizardPBAoELeft.png", 576, 48, 12, 1);
	IMAGEMANAGER->addFrameDImage("WizardPBAoERight", L"img/player/WizardPBAoERight.png", 576, 48, 12, 1);
	IMAGEMANAGER->addFrameDImage("WizardPBAoEUp", L"img/player/WizardPBAoEUp.png", 528, 48, 11, 1);

	IMAGEMANAGER->addFrameDImage("WizardKickDown", L"img/player/WizardKickDown.png", 432, 48, 9, 1);
	IMAGEMANAGER->addFrameDImage("WizardKickLeft", L"img/player/WizardKickLeft.png", 432, 48, 9, 1);
	IMAGEMANAGER->addFrameDImage("WizardKickRight", L"img/player/WizardKickRight.png", 432, 48, 9, 1);
	IMAGEMANAGER->addFrameDImage("WizardKickUp", L"img/player/WizardKickUp.png", 432, 48, 9, 1);

	IMAGEMANAGER->addDImage("WizardHurtDown", L"img/player/WizardHurtDown.png", 22, 32);
	IMAGEMANAGER->addDImage("WizardHurtUp", L"img/player/WizardHurtUp.png", 20, 34);
	IMAGEMANAGER->addDImage("WizardHurtLeft", L"img/player/WizardHurtLeft.png", 20, 34);
	IMAGEMANAGER->addDImage("WizardHurtRight", L"img/player/WizardHurtRight.png", 20, 32);

	IMAGEMANAGER->addDImage("WizardJokePose", L"img/player/WizardJokePose.png", 30, 34);

	IMAGEMANAGER->addDImage("WizardSummonDown", L"img/player/WizardSummonDown.png", 30, 34);

	IMAGEMANAGER->addDImage("WizardJumpDown0", L"img/player/WizardJumpDown0.png", 28, 26);
	IMAGEMANAGER->addDImage("WizardJumpDown1", L"img/player/WizardJumpDown1.png", 22, 38);
	IMAGEMANAGER->addDImage("WizardJumpLeft0Alt", L"img/player/WizardJumpLeft0Alt.png", 20, 38);
	IMAGEMANAGER->addDImage("WizardJumpRight0Alt", L"img/player/WizardJumpRight0Alt.png", 20, 38);
	IMAGEMANAGER->addDImage("WizardJumpUp0", L"img/player/WizardJumpUp0.png", 26, 28);
	IMAGEMANAGER->addDImage("WizardJumpUp1", L"img/player/WizardJumpUp1.png", 22, 38);

	IMAGEMANAGER->addFrameDImage("WizardHood", L"img/player/WizardHood.png", 432, 48, 9, 1);

}

void playGround::UIandItemImage()
{

	IMAGEMANAGER->addDImage("fade", L"img/fade.png", WINSIZEX, WINSIZEY);
	IMAGEMANAGER->addDImage("BG", L"img/Background.png", WINSIZEX, WINSIZEY);
	IMAGEMANAGER->addDImage("logo", L"img/logo.png", 1000,220);
	IMAGEMANAGER->addDImage("ÄÁÆ®·Ñ·¯", L"img/Contingent99Logo.png", 400, 200);
	IMAGEMANAGER->addDImage("sideIcon", L"img/contingent99.png", 308/3, 220/3);
	IMAGEMANAGER->addDImage("¿É¼ÇÃ¢", L"img/Option.png", 400, 800);



	IMAGEMANAGER->addDImage("IconBackGround", L"img/UI/Panel.png", 40, 40);
	IMAGEMANAGER->addDImage("Icon", L"img/UI/PlayerInfo/picture_Player.png", 38, 40);

	IMAGEMANAGER->addDImage("InRect", L"img/UI/Inventory_InRect.png", 128, 56);
	IMAGEMANAGER->addDImage("OutRect", L"img/UI/Inventory_OutRect.png", 128, 56);


	IMAGEMANAGER->addDImage("Gaia_Shovel", L"img/Item/Relics/Attack_Relics/GaiaShovel.png", 97, 98);
	IMAGEMANAGER->addDImage("Ifrit_MatchStick", L"img/Item/Relics/Attack_Relics/IfritMatchStick.png", 97, 98);
	IMAGEMANAGER->addDImage("Rudra_Vane", L"img/Item/Relics/Attack_Relics/RudraVane.png", 97, 98);
	IMAGEMANAGER->addDImage("Shiva_Bottle", L"img/Item/Relics/Attack_Relics/ShivaBottle.png", 97, 98);
	IMAGEMANAGER->addDImage("Taranis_Battery", L"img/Item/Relics/Attack_Relics/TaranisBattery.png", 97, 98);





	IMAGEMANAGER->addDImage("PlayerHp", L"img/UI/PlayerInfo/HP_backGroundBar_Player.png", 130 * 1.5f, 20 * 1.5f);
	IMAGEMANAGER->addDImage("PlayerMp", L"img/UI/PlayerInfo/MP_backGroundBar_Player.png", 104 * 1.5f, 14 * 1.5f);
	IMAGEMANAGER->addDImage("HP", L"img/UI/HPBarFill.png", 124 * 1.5f, 14 * 1.5f);
	IMAGEMANAGER->addDImage("HurtHp", L"img/UI/HPBarHurtFill.png", 124 * 1.5f, 14 * 1.5f);
	IMAGEMANAGER->addDImage("MP", L"img/UI/MPBarFill.png", 70 * 2, 7 * 2);

	IMAGEMANAGER->addDImage("À¯¹°ÇÔ UI", L"img/RelicUITypePageBG.png", 648, 531);
	IMAGEMANAGER->addFrameDImage("À¯¹°ÇÔ", L"img/RelicUIDrawer.png", 2112, 192, 4, 1);
	IMAGEMANAGER->addFrameDImage("¼ÕÀâÀÌ", L"img/RelicUIKnob.png", 153, 65, 3, 1);
	IMAGEMANAGER->addDImage("À¯¹°¸ñ·Ï", L"img/RelicUISelectPageBG_2.png", 642, 549);


	IMAGEMANAGER->addDImage("°ø°ÝÀ¯¹° ¾ÆÀÌÄÜ", L"img/HomeRelicsIcon/RelicUIOffenseIcon.png", 48, 48);
	IMAGEMANAGER->addDImage("¹æ¾îÀ¯¹° ¾ÆÀÌÄÜ", L"img/HomeRelicsIcon/RelicUIDefenseIcon.png", 48, 48);
	IMAGEMANAGER->addDImage("±âÅ¸À¯¹° ¾ÆÀÌÄÜ", L"img/HomeRelicsIcon/RelicUIMiscIcon.png", 48, 48);

	IMAGEMANAGER->addDImage("¾Æ¸£Ä«³ª PANEL", L"img/HomeArcana/ArcanaPanel.png", 323*2.5f, 190*1.5f);
	IMAGEMANAGER->addDImage("¾Æ¸£Ä«³ª ¾Õ¸é",L"img/HomeArcana/ArcanaLargeFront.png",108,156);
	IMAGEMANAGER->addDImage("¾Æ¸£Ä«³ª µÞ¸é", L"img/HomeArcana/ArcanaBackImage.png", 108, 156);
	IMAGEMANAGER->addDImage("½ºÆçºÏ Á¤º¸", L"img/HomeArcana/SpellBookInfo.png", 627, 765);

	IMAGEMANAGER->addFrameDImage("¾ÆÀÌÄÜ_ºÒ"	,L"img/HomeArcana/Icon/Icon_Fire.png",48,36,2,1);
	IMAGEMANAGER->addFrameDImage("¾ÆÀÌÄÜ_¹°"	,L"img/HomeArcana/Icon/Icon_Water.png",48,30,2,1);
	IMAGEMANAGER->addFrameDImage("¾ÆÀÌÄÜ_¶¥"	,L"img/HomeArcana/Icon/Icon_Earth.png",48,30,2,1);
	IMAGEMANAGER->addFrameDImage("¾ÆÀÌÄÜ_¹Ù¶÷",L"img/HomeArcana/Icon/Icon_Wind.png",48,30,2,1);
	IMAGEMANAGER->addFrameDImage("¾ÆÀÌÄÜ_¹ø°³",L"img/HomeArcana/Icon/Icon_Thunder.png",48,30,2,1);

	IMAGEMANAGER->addDImage("Å×µÎ¸®_ºÒ", L"img/HomeArcana/SpellbookUIFirePage.png", 612, 750);
	IMAGEMANAGER->addDImage("Å×µÎ¸®_¹°", L"img/HomeArcana/SpellbookUIWaterPage.png", 612, 750);
	IMAGEMANAGER->addDImage("Å×µÎ¸®_¶¥", L"img/HomeArcana/SpellbookUIEarthPage.png", 612, 750);
	IMAGEMANAGER->addDImage("Å×µÎ¸®_¹Ù¶÷", L"img/HomeArcana/SpellbookUIAirPage.png", 612, 750);
	IMAGEMANAGER->addDImage("Å×µÎ¸®_¹ø°³", L"img/HomeArcana/SpellbookUILightningPage.png", 612, 750);

	IMAGEMANAGER->addFrameDImage("ÅÇ_ºÒ", L"img/HomeArcana/Tab/SpellBookTabFire.png", 108, 87, 2, 1);
	IMAGEMANAGER->addFrameDImage("ÅÇ_¹°", L"img/HomeArcana/Tab/SpellBookTabWater.png", 108, 87, 2, 1);
	IMAGEMANAGER->addFrameDImage("ÅÇ_¶¥", L"img/HomeArcana/Tab/SpellBookTabEarth.png", 108, 87, 2, 1);
	IMAGEMANAGER->addFrameDImage("ÅÇ_¹Ù¶÷", L"img/HomeArcana/Tab/SpellBookTabAir.png", 108, 87, 2, 1);
	IMAGEMANAGER->addFrameDImage("ÅÇ_¹ø°³", L"img/HomeArcana/Tab/SpellBookTabLightning.png", 108, 87, 2, 1);

	IMAGEMANAGER->addDImage("¿ÊÀå_BG", L"img/HomeCloset/WardrobeUIBG.png", 690, 750);
	IMAGEMANAGER->addDImage("¿Ê_BG", L"img/HomeCloset/ClothBackGround.png", 44, 44);
	IMAGEMANAGER->addDImage("¿Ê_ÀÚ¹°¼è", L"img/HomeCloset/ClothLocked.png", 44, 44);



	IMAGEMANAGER->addDImage("¿Ê_»¡°­", L"img/Item/Cloth/WizardOutfit_Red.png", 20*2, 30*2);
	IMAGEMANAGER->addDImage("¿Ê_ÆÄ¶û", L"img/Item/Cloth/WizardOutfit_blue.png", 20*2, 30*2);
	IMAGEMANAGER->addDImage("¿Ê_ÃÊ·Ï", L"img/Item/Cloth/WizardOutfit_mint.png", 20*2, 30*2);
	IMAGEMANAGER->addDImage("¿Ê_³ë¶û", L"img/Item/Cloth/WizardOutfit_yellow.png", 20*2, 30*2);


	IMAGEMANAGER->addDImage("VK_LBUTTON", L"img/Key/M0.png",16,16);
	IMAGEMANAGER->addDImage("VK_RBUTTON", L"img/Key/M1.png",16,16);
	IMAGEMANAGER->addDImage("VK_Q", L"img/Key/Q.png",16,16);
	IMAGEMANAGER->addDImage("VK_E", L"img/Key/E.png",16,16);
	IMAGEMANAGER->addDImage("VK_R", L"img/Key/R.png",16,16);
	IMAGEMANAGER->addDImage("VK_SPACE", L"img/Key/Space.png",16,16);
	IMAGEMANAGER->addDImage("VK_TAB", L"img/Key/Tab.png", 16, 16);
	IMAGEMANAGER->addDImage("VK_M", L"img/Key/M.png", 16, 16);



}

void playGround::enemyImage()
{
	// ±¸¿ï
	IMAGEMANAGER->addDImage("GhoulIdle", L"img/enemy/Ghoul/GhoulIdle.png", 48, 48);
	IMAGEMANAGER->addDImage("GhoulIdleLeft", L"img/enemy/Ghoul/GhoulIdle.png", 48, 48);
	IMAGEMANAGER->addDImage("GhoulHurt", L"img/enemy/Ghoul/GhoulHurt.png", 48, 48);
	IMAGEMANAGER->addFrameDImage("GhoulAttack", L"img/enemy/Ghoul/GhoulAttack.png", 96, 48, 2, 1);
	IMAGEMANAGER->addFrameDImage("GhoulDeath", L"img/enemy/Ghoul/GhoulDeath.png", 432, 48, 9, 1);
	IMAGEMANAGER->addFrameDImage("GhoulRunRight", L"img/enemy/Ghoul/GhoulRunRight.png", 288, 48, 6, 1);

	// ¶óÁö ±¸¿ï
	IMAGEMANAGER->addDImage("GhoulLargeIdle", L"img/enemy/GhoulLarge/GhoulLargeIdle.png", 48, 64);
	IMAGEMANAGER->addFrameDImage("GhoulLargeAttack0", L"img/enemy/GhoulLarge/GhoulLargeAttack0.png", 280, 64, 5, 1);
	IMAGEMANAGER->addFrameDImage("GhoulLargeAttack1", L"img/enemy/GhoulLarge/GhoulLargeAttack1.png", 280, 64, 5, 1);
	IMAGEMANAGER->addFrameDImage("GhoulLargeAttack2", L"img/enemy/GhoulLarge/GhoulLargeAttack2.png", 240, 72, 5, 1);
	IMAGEMANAGER->addFrameDImage("GhoulLargeDead", L"img/enemy/GhoulLarge/GhoulLargeDead.png", 288, 64, 6, 1);
	IMAGEMANAGER->addFrameDImage("GhoulLargeRunRight", L"img/enemy/GhoulLarge/GhoulLargeRunRight.png", 240, 64, 5, 1);

	// ¾î½º Á¶³Ê
	IMAGEMANAGER->addDImage("EarthZonerHurt", L"img/enemy/EarthZoner/EarthZonerHurt.png", 32, 48);
	IMAGEMANAGER->addFrameDImage("EarthZonerIdle", L"img/enemy/EarthZoner/EarthZonerIdle.png", 128, 48, 4, 1);
	IMAGEMANAGER->addFrameDImage("EarthZonerAttack", L"img/enemy/EarthZoner/EarthZonerAttack.png", 64, 48, 2, 1);

	// ÇÃ·¹ÀÓ Á¶³Ê
	IMAGEMANAGER->addDImage("FlameZonerIdle", L"img/enemy/FlameZoner/FlameZonerIdle.png", 32, 48);
	IMAGEMANAGER->addDImage("FlameZonerHurt", L"img/enemy/FlameZoner/FlameZonerHurt.png", 32, 48);
	IMAGEMANAGER->addFrameDImage("FlameZonerDead", L"img/enemy/FlameZoner/FlameZonerDead.png", 96, 48, 3, 1);
	IMAGEMANAGER->addFrameDImage("FlameZonerAttack", L"img/enemy/FlameZoner/FlameZonerAttack.png", 128, 48, 4, 1);

	// ºí·Ó ·Ñ·¯
	IMAGEMANAGER->addDImage("BlobRollerIdle", L"img/enemy/BlobRoller/BlobRollerIdle.png", 32, 32);
	IMAGEMANAGER->addFrameDImage("BlobRollerDead", L"img/enemy/BlobRoller/BlobRollerDead.png", 160, 32, 5, 1);
	IMAGEMANAGER->addFrameDImage("BlobRollerHurt", L"img/enemy/BlobRoller/BlobRollerHurt.png", 96, 32, 3, 1);
	IMAGEMANAGER->addFrameDImage("BlobRollerRoll", L"img/enemy/BlobRoller/BlobRollerRoll.png", 224, 32, 7, 1);
	//IMAGEMANAGER->addFrameDImage("FlameZonerDead", L"img/enemy/BlobRoller/FlameZonerDead.png", 96, 48, 3, 1);

	// ¹Ì¹Í
	IMAGEMANAGER->addDImage("MimicHide", L"img/enemy/Mimic/ChestMiniClosed.png", 32, 40);
	IMAGEMANAGER->addDImage("MimicIdle", L"img/enemy/Mimic/MimicIdle.png", 32, 40);
	IMAGEMANAGER->addFrameDImage("MimicHurt", L"img/enemy/Mimic/MimicHurt.png", 96, 40, 3, 1);
	IMAGEMANAGER->addFrameDImage("MimicAttack", L"img/enemy/Mimic/MimicAttack.png", 128, 40, 4, 1);

	//°ñ·½
	IMAGEMANAGER->addDImage("GolemIdle", L"img/enemy/Golem/GolemIdle.png", 50, 65);
	IMAGEMANAGER->addDImage("GolemAttackDown0", L"img/enemy/Golem/GolemAttackDown0.png", 48, 71);
	IMAGEMANAGER->addDImage("GolemAttackFollowThrough", L"img/enemy/Golem/GolemAttackFollowThrough.png", 48, 67);
	IMAGEMANAGER->addDImage("GolemAttackRight0", L"img/enemy/Golem/GolemAttackRight0.png", 46, 68);
	IMAGEMANAGER->addDImage("GolemAttackUp0", L"img/enemy/Golem/GolemAttackUp0.png", 45, 64);
	IMAGEMANAGER->addFrameDImage("GolemDeath", L"img/enemy/Golem/GolemDeath.png", 360, 62, 6, 1);
	IMAGEMANAGER->addFrameDImage("GolemRunRight", L"img/enemy/Golem/GolemRunRight.png", 366, 67, 6, 1);

	//³ªÀÌÆ®
	IMAGEMANAGER->addDImage("KnightIdle", L"img/enemy/Knight/KnightIdle.png", 48, 48);
	IMAGEMANAGER->addDImage("KnightBlock", L"img/enemy/Knight/KnightBlock.png", 48, 48);
	IMAGEMANAGER->addDImage("KnightLunge0", L"img/enemy/Knight/KnightLunge0.png", 48, 48);
	IMAGEMANAGER->addFrameDImage("KnightAttack", L"img/enemy/Knight/KnightAttack.png", 240, 48, 5, 1);
	IMAGEMANAGER->addFrameDImage("KnightCharge", L"img/enemy/Knight/KnightCharge.png", 144, 64, 3, 1);
	IMAGEMANAGER->addFrameDImage("KnightDeath", L"img/enemy/Knight/KnightDeath.png", 336, 80, 7, 1);
	IMAGEMANAGER->addFrameDImage("KnightForehand", L"img/enemy/Knight/KnightForehand.png", 96, 48, 2, 1);
	IMAGEMANAGER->addFrameDImage("KnightSwordPlant", L"img/enemy/Knight/KnightSwordPlant.png", 144, 48, 3, 1);
	IMAGEMANAGER->addFrameDImage("KnightThrow", L"img/enemy/Knight/KnightThrow.png", 96, 48, 2, 1);
	IMAGEMANAGER->addFrameDImage("RunRight", L"img/enemy/Knight/RunRight.png", 240, 48, 5, 1);
	// ºí·ç ³ªÀÌÆ®
	IMAGEMANAGER->addDImage("KnightIdle_blue", L"img/enemy/Knight/KnightIdle_blue.png", 48, 48);
	IMAGEMANAGER->addDImage("KnightBlock_blue", L"img/enemy/Knight/KnightBlock_blue.png", 48, 48);
	IMAGEMANAGER->addDImage("KnightLunge0_blue", L"img/enemy/Knight/KnightLunge0_blue.png", 48, 48);
	IMAGEMANAGER->addFrameDImage("KnightAttack_blue", L"img/enemy/Knight/KnightAttack_blue.png", 240, 48, 5, 1);
	IMAGEMANAGER->addFrameDImage("KnightCharge_blue", L"img/enemy/Knight/KnightCharge_blue.png", 144, 64, 3, 1);
	IMAGEMANAGER->addFrameDImage("KnightDeath_blue", L"img/enemy/Knight/KnightDeath_blue.png", 336, 80, 7, 1);
	IMAGEMANAGER->addFrameDImage("KnightForehand_blue", L"img/enemy/Knight/KnightForehand_blue.png", 96, 48, 2, 1);
	IMAGEMANAGER->addFrameDImage("KnightSwordPlant_blue", L"img/enemy/Knight/KnightSwordPlant_blue.png", 144, 48, 3, 1);
	IMAGEMANAGER->addFrameDImage("KnightThrow_blue", L"img/enemy/Knight/KnightThrow_blue.png", 96, 48, 2, 1);
	IMAGEMANAGER->addFrameDImage("RunRight_blue", L"img/enemy/Knight/RunRight_blue.png", 240, 48, 5, 1);

	// ·¹µå ³ªÀÌÆ®
	IMAGEMANAGER->addDImage("KnightIdle_red", L"img/enemy/Knight/KnightIdle_red.png", 48, 48);
	IMAGEMANAGER->addDImage("KnightBlock_red", L"img/enemy/Knight/KnightBlock_red.png", 48, 48);
	IMAGEMANAGER->addDImage("KnightLunge0_red", L"img/enemy/Knight/KnightLunge0_red.png", 48, 48);
	IMAGEMANAGER->addFrameDImage("KnightAttack_red", L"img/enemy/Knight/KnightAttack_red.png", 240, 48, 5, 1);
	IMAGEMANAGER->addFrameDImage("KnightCharge_red", L"img/enemy/Knight/KnightCharge_red.png", 144, 64, 3, 1);
	IMAGEMANAGER->addFrameDImage("KnightDeath_red", L"img/enemy/Knight/KnightDeath_red.png", 336, 80, 7, 1);
	IMAGEMANAGER->addFrameDImage("KnightForehand_red", L"img/enemy/Knight/KnightForehand_red.png", 96, 48, 2, 1);
	IMAGEMANAGER->addFrameDImage("KnightSwordPlant_red", L"img/enemy/Knight/KnightSwordPlant_red.png", 144, 48, 3, 1);
	IMAGEMANAGER->addFrameDImage("KnightThrow_red", L"img/enemy/Knight/KnightThrow_red.png", 96, 48, 2, 1);
	IMAGEMANAGER->addFrameDImage("RunRight_red", L"img/enemy/Knight/RunRight_red.png", 240, 48, 5, 1);

	// ±×¸° ³ªÀÌÆ®
	IMAGEMANAGER->addDImage("KnightIdle_green", L"img/enemy/Knight/KnightIdle_green.png", 48, 48);
	IMAGEMANAGER->addDImage("KnightBlock_green", L"img/enemy/Knight/KnightBlock_green.png", 48, 48);
	IMAGEMANAGER->addDImage("KnightLunge0_green", L"img/enemy/Knight/KnightLunge0_green.png", 48, 48);
	IMAGEMANAGER->addFrameDImage("KnightAttack_green", L"img/enemy/Knight/KnightAttack_green.png", 240, 48, 5, 1);
	IMAGEMANAGER->addFrameDImage("KnightCharge_green", L"img/enemy/Knight/KnightCharge_green.png", 144, 64, 3, 1);
	IMAGEMANAGER->addFrameDImage("KnightDeath_green", L"img/enemy/Knight/KnightDeath_green.png", 336, 80, 7, 1);
	IMAGEMANAGER->addFrameDImage("KnightForehand_green", L"img/enemy/Knight/KnightForehand_green.png", 96, 48, 2, 1);
	IMAGEMANAGER->addFrameDImage("KnightSwordPlant_green", L"img/enemy/Knight/KnightSwordPlant_green.png", 144, 48, 3, 1);
	IMAGEMANAGER->addFrameDImage("KnightThrow_green", L"img/enemy/Knight/KnightThrow_green.png", 96, 48, 2, 1);
	IMAGEMANAGER->addFrameDImage("RunRight_green", L"img/enemy/Knight/RunRight_green.png", 240, 48, 5, 1);

	// ¼­¸ð³Ê
	IMAGEMANAGER->addDImage("SummonerIdleDown", L"img/enemy/summoner/SummonerIdleDown.png", 48, 48);
	IMAGEMANAGER->addDImage("SummonerHurt", L"img/enemy/summoner/SummonerHurt.png", 48, 48);
	IMAGEMANAGER->addFrameDImage("SummonerRunRight", L"img/enemy/summoner/SummonerRunRight.png", 144, 48, 3, 1);
	IMAGEMANAGER->addFrameDImage("SummonerCast", L"img/enemy/summoner/SummonerCast.png", 288, 48, 6, 1);
	IMAGEMANAGER->addFrameDImage("SummonerDead", L"img/enemy/summoner/SummonerDead.png", 288, 64, 6, 1);

	// ¿Àºê
	IMAGEMANAGER->addDImage("OrbChargeIdle", L"img/enemy/summoner/OrbChargeIdle.png", 16, 16);
	IMAGEMANAGER->addFrameDImage("OrbChargeWindup", L"img/enemy/summoner/OrbChargeWindup.png", 64, 22, 4, 1);

	// ¼­¸ð³Ê ºí·ç
	IMAGEMANAGER->addDImage("SummonerIdleDown_blue", L"img/enemy/summoner/SummonerIdleDown_blue.png", 48, 48);
	IMAGEMANAGER->addDImage("SummonerHurt_blue", L"img/enemy/summoner/SummonerHurt_blue.png", 48, 48);
	IMAGEMANAGER->addFrameDImage("SummonerRunRight_blue", L"img/enemy/summoner/SummonerRunRight_blue.png", 144, 48, 3, 1);
	IMAGEMANAGER->addFrameDImage("SummonerCast_blue", L"img/enemy/summoner/SummonerCast_blue.png", 288, 48, 6, 1);

	// ¼­¸ð³Ê ·¹µå
	IMAGEMANAGER->addDImage("SummonerIdleDown_red", L"img/enemy/summoner/SummonerIdleDown_red.png", 48, 48);
	IMAGEMANAGER->addDImage("SummonerHurt_red", L"img/enemy/summoner/SummonerHurt_red.png", 48, 48);
	IMAGEMANAGER->addFrameDImage("SummonerRunRight_red", L"img/enemy/summoner/SummonerRunRight_red.png", 144, 48, 3, 1);
	IMAGEMANAGER->addFrameDImage("SummonerCast_red", L"img/enemy/summoner/SummonerCast_red.png", 288, 48, 6, 1);

	// ¼­¸ð³Ê ±×¸°
	IMAGEMANAGER->addDImage("SummonerIdleDown_green", L"img/enemy/summoner/SummonerIdleDown_green.png", 48, 48);
	IMAGEMANAGER->addDImage("SummonerHurt_green", L"img/enemy/summoner/SummonerHurt_green.png", 48, 48);
	IMAGEMANAGER->addFrameDImage("SummonerRunRight_green", L"img/enemy/summoner/SummonerRunRight_green.png", 144, 48, 3, 1);
	IMAGEMANAGER->addFrameDImage("SummonerCast_green", L"img/enemy/summoner/SummonerCast_green.png", 288, 48, 6, 1);

	// ¾ÆÀÌ½º º¸½º
	IMAGEMANAGER->addDImage("IceBossIdle", L"img/Boss/IceBoss/IceBossIdle.png", 48, 64);
	IMAGEMANAGER->addDImage("IceBossTwoHandCastDown3", L"img/Boss/IceBoss/IceBossTwoHandCastDown3.png", 48, 64);
	IMAGEMANAGER->addDImage("IceBossTwoHandCastRight3", L"img/Boss/IceBoss/IceBossTwoHandCastRight3.png", 48, 64);
	IMAGEMANAGER->addDImage("IceBossDead", L"img/Boss/IceBoss/IceBossDead.png", 48, 64);
	IMAGEMANAGER->addDImage("IceBossDashUp0", L"img/Boss/IceBoss/IceBossDashUp0.png", 48, 64);
	IMAGEMANAGER->addDImage("IceBossDashRight0", L"img/Boss/IceBoss/IceBossDashRight0.png", 48, 64);
	IMAGEMANAGER->addDImage("IceBossDashDown0", L"img/Boss/IceBoss/IceBossDashDown0.png", 48, 64);
	IMAGEMANAGER->addDImage("IceBossBackhandDown0", L"img/Boss/IceBoss/IceBossBackhandDown0.png", 48, 64);
	IMAGEMANAGER->addDImage("IceBossArmsCrossed", L"img/Boss/IceBoss/IceBossArmsCrossed.png", 32, 64);
	IMAGEMANAGER->addFrameDImage("IceBossCast", L"img/Boss/IceBoss/IceBossCast.png", 96, 64, 2, 1);
	IMAGEMANAGER->addFrameDImage("IceBossCrossArmCast", L"img/Boss/IceBoss/IceBossCrossArmCast.png", 240, 64, 5, 1);
	IMAGEMANAGER->addFrameDImage("IceBossHurt", L"img/Boss/IceBoss/IceBossHurt.png", 144, 64, 3, 1);
	IMAGEMANAGER->addFrameDImage("IceBossLaugh", L"img/Boss/IceBoss/IceBossLaugh.png", 144, 64, 3, 1);
	IMAGEMANAGER->addFrameDImage("IceBossMultiCast", L"img/Boss/IceBoss/IceBossMultiCast.png", 144, 64, 3, 1);
	IMAGEMANAGER->addFrameDImage("IceBossPointDown", L"img/Boss/IceBoss/IceBossPointDown.png", 96, 64, 2, 1);
	IMAGEMANAGER->addFrameDImage("IceBossPointUp", L"img/Boss/IceBoss/IceBossPointUp.png", 96, 64, 2, 1);
	IMAGEMANAGER->addFrameDImage("IceBossSummon", L"img/Boss/IceBoss/IceBossSummon.png", 96, 64, 2, 1);
	IMAGEMANAGER->addFrameDImage("IceBossRainbowCastDown", L"img/Boss/IceBoss/IceBossRainbowCastDown.png", 144, 64, 3, 1);
	IMAGEMANAGER->addFrameDImage("IceBossRainbowCastRight", L"img/Boss/IceBoss/IceBossRainbowCastRight.png", 144, 64, 3, 1);
	IMAGEMANAGER->addFrameDImage("IceBossRainbowCastUp", L"img/Boss/IceBoss/IceBossRainbowCastUp.png", 144, 64, 3, 1);
	IMAGEMANAGER->addFrameDImage("IceBossReady", L"img/Boss/IceBoss/IceBossReady.png", 240, 64, 5, 1);
	IMAGEMANAGER->addFrameDImage("IceBossSpin", L"img/Boss/IceBoss/IceBossSpin.png", 384, 64, 8, 1);
	IMAGEMANAGER->addFrameDImage("IceBossSpinFancy", L"img/Boss/IceBoss/IceBossSpinFancy.png", 528, 64, 11, 1);
	IMAGEMANAGER->addFrameDImage("IceBossSpinRight", L"img/Boss/IceBoss/IceBossSpinRight.png", 336, 64, 7, 1);

}