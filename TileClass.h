#pragma once
#include "gameNode.h"

#define TILESIZE 16
#define SAMPLETILEX 32
#define SAMPLETILEY 32
#define TILEX 100	//가로 타일 갯수
#define TILEY 100	//세로 타일 갯수
#define TILESIZEX TILESIZE * TILEX	//640 32 * 20
#define TILESIZEY TILESIZE * TILEY	//640 32 * 20
#define WIDTHDUNGEONNUM 3
#define LENGTHDUNGEONNUM 2
#define IMAGENUM 21
#define OBJLEVEL 3

enum CTRL
{
	CTRL_SAVE,			//세이브		버튼
	CTRL_LOAD,			//로드		버튼
	CTRL_TERRAINDRAW,	//지형		버튼
	CTRL_OBJDRAW,		//오브젝트	버튼
	CTRL_ERASER,		//지우개		버튼
	CTRL_END
};
//지형
enum TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};

//오브젝트
enum OBJECT
{
	OBJ_JAR,
	OBJ_FRAME,
	OBJ_TREE,
	OBJ_RUG,
	OBJ_NONE
};


//타일 움직일때 얼마나 움직일건가
enum MOVENUM
{
	ONE,
	TEN,
	HUNDRED
};
//움직일 방향
enum MOVEDIRECTION
{
	DIRECTION_UP,
	DIRECTION_LEFT,
	DIRECTION_DOWN,
	DIRECTION_RIGHT
};
enum ATTRIBUTE_ID
{
	ATTR_NORMAL,
	ATTR_UNMOVE,
	ATTR_FALL,
	ATTR_NONE
};

//타일 정보 담은 구조체
struct tagTile
{
	dImage*		objImage[OBJLEVEL];
	TERRAIN		terrain;
	OBJECT		obj;
	RECT		rc;
	int			attrID;
	int			tileObjZOrder[OBJLEVEL];
	int			terrainImageIndex;
	int			objImageIndex[OBJLEVEL];
	int			terrainFrameX;
	int			terrainFrameY;
	int			objFrameX[OBJLEVEL];
	int			objFrameY[OBJLEVEL];
};

struct tagDungeonTileIndex
{
	int startX;
	int lastX;
	int startY;
	int lastY;
};

class TileClass : public gameNode
{

private:
	vector<pair<int, int>> _vWidthDungeonStartPoint;
	vector<pair<int, int>> _vLengthDungeonStartPoint;
	const char * _mapfileName;
	dImage* _tileImage[IMAGENUM];
	tagTile _tiles[TILEX][TILEY];
	tagTile _tmpTile[TILEX][TILEY];
	const char* _fileName;
	RECT _allMapRc;
	int _selectMapIndex;
	tagDungeonTileIndex _dungeonShape[WIDTHDUNGEONNUM];
	tagDungeonTileIndex _dungeonShape2[LENGTHDUNGEONNUM];
	tagDungeonTileIndex _dungeonShape3;
	pair<int, int> _pairBossDungeonStartPoint;
public:
	virtual HRESULT init(const char* fileName);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void setup();
	virtual void setMap();

	virtual void save(const char * name);
	virtual void load(const char * name);
	void setBossDungeon(const char* name);
	void setRandomDungeon(const char* name);
};

