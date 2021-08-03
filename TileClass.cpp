#include "stdafx.h"
#include "TileClass.h"

HRESULT TileClass::init(const char* name)
{
	_tileImage[0] = IMAGEMANAGER->findDImage("MapAir");
	_tileImage[1] = IMAGEMANAGER->findDImage("MapCastleBase");
	_tileImage[2] = IMAGEMANAGER->findDImage("MapCastle");
	_tileImage[3] = IMAGEMANAGER->findDImage("MapCourtyard");
	_tileImage[4] = IMAGEMANAGER->findDImage("MapEarth");
	_tileImage[5] = IMAGEMANAGER->findDImage("MapFire");
	_tileImage[6] = IMAGEMANAGER->findDImage("MapHome");
	_tileImage[7] = IMAGEMANAGER->findDImage("MapIce");
	_tileImage[8] = IMAGEMANAGER->findDImage("MapLightning");
	_tileImage[9] = IMAGEMANAGER->findDImage("MapMuseum");
	_tileImage[10] = IMAGEMANAGER->findDImage("MapPlaza");
	_tileImage[11] = IMAGEMANAGER->findDImage("MapBlack");
	_tileImage[12] = IMAGEMANAGER->findDImage("Obj1");
	_tileImage[13] = IMAGEMANAGER->findDImage("Obj2");
	_tileImage[14] = IMAGEMANAGER->findDImage("ObjStore");
	_tileImage[15] = IMAGEMANAGER->findDImage("ObjWood");
	_tileImage[16] = IMAGEMANAGER->findDImage("MapPrison");
	_tileImage[17] = IMAGEMANAGER->findDImage("ObjIce1");
	_tileImage[18] = IMAGEMANAGER->findDImage("ObjIce2");
	_tileImage[19] = IMAGEMANAGER->findDImage("ObjTrees");
	_tileImage[20] = IMAGEMANAGER->findDImage("ObjStatue");
	_fileName = name;
	_selectMapIndex = 0;

	setup();
	return S_OK;
}

void TileClass::release()
{
}

void TileClass::update()
{
	setMap();
}

void TileClass::render()
{
	//지형 그리기
	for (int i = 0; i < TILEX; ++i)
	{
		for (int j = 0; j < TILEY; ++j)
		{
			_tileImage[_tiles[i][j].terrainImageIndex]->frameRender(i * TILESIZE, j * TILESIZE,
				_tiles[i][j].terrainFrameX,
				_tiles[i][j].terrainFrameY,
				TILESIZE, TILESIZE);
			if (_tiles[i][j].obj == OBJ_NONE) continue;
			for (int k = 0; k < OBJLEVEL; ++k)
			{
				if (_tiles[i][j].objImage[k] == nullptr) continue;
				RENDERMANAGER->push_BackFrameRenderInfo(
					_tiles[i][j].tileObjZOrder[k],
					_tiles[i][j].objImage[k],
					i * TILESIZE, j * TILESIZE,
					_tiles[i][j].objFrameX[k],
					_tiles[i][j].objFrameY[k],
					TILESIZE, TILESIZE);
			}
		}
	}

}

void TileClass::setup()
{
	load(_fileName);
}

void TileClass::setMap()
{

}



void TileClass::save(const char * name)
{
	HANDLE file;
	DWORD write;

	file = CreateFile(name, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &write, NULL);
	CloseHandle(file);
}

void TileClass::load(const char * name)
{
	HANDLE file;
	DWORD read;
	file = CreateFile(name, GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	for (int i = 0; i < TILEX; ++i)
	{
		for (int j = 0; j < TILEY; ++j)
		{
			for (int k = 0; k < OBJLEVEL; ++k)
			{
				if (_tiles[i][j].objImageIndex[k] != 100)
					_tiles[i][j].objImage[k] = _tileImage[_tiles[i][j].objImageIndex[k]];
			}
		}
	}
	CloseHandle(file);
}

void TileClass::setBossDungeon(const char * name)
{
	HANDLE file;
	DWORD read;

	file = CreateFile(name, GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, _tmpTile, sizeof(tagTile) * TILEX * TILEY, &read, NULL);

	CloseHandle(file);
	for (int i = 0; i < TILEX; ++i)
	{
		for (int j = 0; j < TILEY; ++j)
		{
			for (int k = 0; k < OBJLEVEL; ++k)
			{
				if (_tmpTile[i][j].objImageIndex[k] != 100)
					_tmpTile[i][j].objImage[k] = _tileImage[_tmpTile[i][j].objImageIndex[k]];
			}
		}
	}

	_dungeonShape3.startX = 38;
	_dungeonShape3.lastX = 69;
	_dungeonShape3.startY = 24;
	_dungeonShape3.lastY = 99;
	for (int i = 0; i < TILEX; ++i)
	{
		for (int j = 0; j < TILEY; ++j)
		{
			if (_tiles[i][j].attrID == ATTR_NONE &&
				_tiles[i][j].terrainImageIndex == 14)
			{
				if (_tiles[i][j].terrainFrameX == 1 &&
					_tiles[i][j].terrainFrameY == 1)
				{
					_pairBossDungeonStartPoint.first = i;
					_pairBossDungeonStartPoint.second = j;
				}
			}
		}
	}
	for (int i = 0; i <= _dungeonShape3.lastX - _dungeonShape3.startX; ++i)
	{
		for (int j = 0; j <= _dungeonShape3.lastY - _dungeonShape3.startY; ++j)
		{
			_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].attrID = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].attrID;
			_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].obj = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].obj;
			_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].terrain = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].terrain;
			_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].terrainFrameX = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].terrainFrameX;
			_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].terrainFrameY = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].terrainFrameY;
			_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].terrainImageIndex = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].terrainImageIndex;
			for (int k = 0; k < OBJLEVEL; ++k)
			{
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objImage[k] = nullptr;
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objImageIndex[k] = 100;
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objFrameX[k] = 0;
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objFrameY[k] = 0;
				if (_tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].objImage[k] == nullptr) continue;

				if (_tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].tileObjZOrder[k] != 0)
					_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].tileObjZOrder[k] = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].tileObjZOrder[k] + (_pairBossDungeonStartPoint.second - _dungeonShape3.startY);
				else
					_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].tileObjZOrder[k] = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].tileObjZOrder[k];
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objImage[k] = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].objImage[k];
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objFrameX[k] = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].objFrameX[k];
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objFrameY[k] = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].objFrameY[k];
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objImageIndex[k] = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].objImageIndex[k];
			}
		}
	}
}


void TileClass::setRandomDungeon(const char * name)
{
	HANDLE file;
	DWORD read;

	file = CreateFile(name, GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, _tmpTile, sizeof(tagTile) * TILEX * TILEY, &read, NULL);

	CloseHandle(file);
	for (int i = 0; i < TILEX; ++i)
	{
		for (int j = 0; j < TILEY; ++j)
		{
			for (int k = 0; k < OBJLEVEL; ++k)
			{
				if (_tmpTile[i][j].objImageIndex[k] != 100)
					_tmpTile[i][j].objImage[k] = _tileImage[_tmpTile[i][j].objImageIndex[k]];
			}
		}
	}
	for (int i = 0; i < TILEX; ++i)
	{
		for (int j = 0; j < TILEY; ++j)
		{
			if (_tiles[i][j].attrID == ATTR_NONE &&
				_tiles[i][j].terrainImageIndex == 14)
			{
				if (_tiles[i][j].terrainFrameX == 0 &&
					_tiles[i][j].terrainFrameY == 0)
				{
					_vWidthDungeonStartPoint.push_back(make_pair(i, j));
				}
				else if (_tiles[i][j].terrainFrameX == 1 &&
					_tiles[i][j].terrainFrameY == 0)
				{
					_vLengthDungeonStartPoint.push_back(make_pair(i, j));
				}
				else if (_tiles[i][j].terrainFrameX == 0 &&
					_tiles[i][j].terrainFrameY == 1)
				{
					_pairBossDungeonStartPoint.first = i;
					_pairBossDungeonStartPoint.second = j;
				}
			}
		}
	}
	for (int i = 0; i < WIDTHDUNGEONNUM; ++i)
	{
		_dungeonShape[i].startX = 22 * i;
		_dungeonShape[i].lastX = _dungeonShape[i].startX + 21;
		_dungeonShape[i].startY = 0;
		_dungeonShape[i].lastY = 9;
	}
	for (int i = 0; i < LENGTHDUNGEONNUM; ++i)
	{
		_dungeonShape2[i].startX = 10 * i;
		_dungeonShape2[i].lastX = _dungeonShape2[i].startX + 9;
		_dungeonShape2[i].startY = 10;
		_dungeonShape2[i].lastY = 31;
	}
	_dungeonShape3.startX = 0;
	_dungeonShape3.lastX = 14;
	_dungeonShape3.startY = 40;
	_dungeonShape3.lastY = 58;
	for (int i = 0; i < _vWidthDungeonStartPoint.size(); ++i)
	{
		int tmp = RND->getInt(WIDTHDUNGEONNUM);
		for (int j = 0; j <= _dungeonShape[tmp].lastX - _dungeonShape[tmp].startX; ++j)
		{
			for (int k = 0; k <= _dungeonShape[tmp].lastY - _dungeonShape[tmp].startY; ++k)
			{
				_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].attrID = _tmpTile[_dungeonShape[tmp].startX + j][_dungeonShape[tmp].startY + k].attrID;
				_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].obj = _tmpTile[_dungeonShape[tmp].startX + j][_dungeonShape[tmp].startY + k].obj;
				_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].terrain = _tmpTile[_dungeonShape[tmp].startX + j][_dungeonShape[tmp].startY + k].terrain;
				_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].terrainFrameX = _tmpTile[_dungeonShape[tmp].startX + j][_dungeonShape[tmp].startY + k].terrainFrameX;
				_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].terrainFrameY = _tmpTile[_dungeonShape[tmp].startX + j][_dungeonShape[tmp].startY + k].terrainFrameY;
				_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].terrainImageIndex = _tmpTile[_dungeonShape[tmp].startX + j][_dungeonShape[tmp].startY + k].terrainImageIndex;
				for (int l = 0; l < OBJLEVEL; ++l)
				{
					_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].objImage[l] = nullptr;
					_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].objImageIndex[l] = 100;
					_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].objFrameX[l] = 0;
					_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].objFrameY[l] = 0;
					if (_tmpTile[_dungeonShape[tmp].startX + j][_dungeonShape[tmp].startY + k].objImage[l] == nullptr) continue;

					if (_tmpTile[_dungeonShape[tmp].startX + j][_dungeonShape[tmp].startY + k].tileObjZOrder[l] != 0)
						_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].tileObjZOrder[l] = _tmpTile[_dungeonShape[tmp].startX + j][_dungeonShape[tmp].startY + k].tileObjZOrder[l] + (_vWidthDungeonStartPoint[i].second - _dungeonShape[tmp].startY);
					else
						_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].tileObjZOrder[l] = _tmpTile[_dungeonShape[tmp].startX + j][_dungeonShape[tmp].startY + k].tileObjZOrder[l];

					_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].objImage[l] = _tmpTile[_dungeonShape[tmp].startX + j][_dungeonShape[tmp].startY + k].objImage[l];
					_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].objFrameX[l] = _tmpTile[_dungeonShape[tmp].startX + j][_dungeonShape[tmp].startY + k].objFrameX[l];
					_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].objFrameY[l] = _tmpTile[_dungeonShape[tmp].startX + j][_dungeonShape[tmp].startY + k].objFrameY[l];
					_tiles[_vWidthDungeonStartPoint[i].first + j][_vWidthDungeonStartPoint[i].second + k].objImageIndex[l] = _tmpTile[_dungeonShape[tmp].startX + j][_dungeonShape[tmp].startY + k].objImageIndex[l];
				}
			}
		}
	}
	for (int i = 0; i < _vLengthDungeonStartPoint.size(); ++i)
	{
		int tmp = RND->getInt(WIDTHDUNGEONNUM);

		for (int j = 0; j <= _dungeonShape2[tmp].lastX - _dungeonShape2[tmp].startX; ++j)
		{
			for (int k = 0; k <= _dungeonShape2[tmp].lastY - _dungeonShape2[tmp].startY; ++k)
			{
				_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].attrID = _tmpTile[_dungeonShape2[tmp].startX + j][_dungeonShape2[tmp].startY + k].attrID;
				_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].obj = _tmpTile[_dungeonShape2[tmp].startX + j][_dungeonShape2[tmp].startY + k].obj;
				_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].terrain = _tmpTile[_dungeonShape2[tmp].startX + j][_dungeonShape2[tmp].startY + k].terrain;
				_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].terrainFrameX = _tmpTile[_dungeonShape2[tmp].startX + j][_dungeonShape2[tmp].startY + k].terrainFrameX;
				_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].terrainFrameY = _tmpTile[_dungeonShape2[tmp].startX + j][_dungeonShape2[tmp].startY + k].terrainFrameY;
				_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].terrainImageIndex = _tmpTile[_dungeonShape2[tmp].startX + j][_dungeonShape2[tmp].startY + k].terrainImageIndex;
				for (int l = 0; l < OBJLEVEL; ++l)
				{
					_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].objImage[l] = nullptr;
					_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].objImageIndex[l] = 100;
					_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].objFrameX[l] = 0;
					_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].objFrameY[l] = 0;
					if (_tmpTile[_dungeonShape2[tmp].startX + j][_dungeonShape2[tmp].startY + k].objImage[l] == nullptr) continue;

					if (_tmpTile[_dungeonShape2[tmp].startX + j][_dungeonShape2[tmp].startY + k].tileObjZOrder[l] !=0)
						_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].tileObjZOrder[l] = _tmpTile[_dungeonShape2[tmp].startX + j][_dungeonShape2[tmp].startY + k].tileObjZOrder[l] + (_vLengthDungeonStartPoint[i].second - _dungeonShape[tmp].startY);
					else
						_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].tileObjZOrder[l] = _tmpTile[_dungeonShape2[tmp].startX + j][_dungeonShape2[tmp].startY + k].tileObjZOrder[l];
					_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].objImage[l] = _tmpTile[_dungeonShape2[tmp].startX + j][_dungeonShape2[tmp].startY + k].objImage[l];
					_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].objFrameX[l] = _tmpTile[_dungeonShape2[tmp].startX + j][_dungeonShape2[tmp].startY + k].objFrameX[l];
					_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].objFrameY[l] = _tmpTile[_dungeonShape2[tmp].startX + j][_dungeonShape2[tmp].startY + k].objFrameY[l];
					_tiles[_vLengthDungeonStartPoint[i].first + j][_vLengthDungeonStartPoint[i].second + k].objImageIndex[l] = _tmpTile[_dungeonShape2[tmp].startX + j][_dungeonShape2[tmp].startY + k].objImageIndex[l];
				}
			}
		}
	}
	for (int i = 0; i <= _dungeonShape3.lastX - _dungeonShape3.startX; ++i)
	{
		for (int j = 0; j <= _dungeonShape3.lastY - _dungeonShape3.startY; ++j)
		{
			_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].attrID = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].attrID;
			_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].obj = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].obj;
			_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].terrain = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].terrain;
			_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].terrainFrameX = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].terrainFrameX;
			_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].terrainFrameY = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].terrainFrameY;
			_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].terrainImageIndex = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].terrainImageIndex;
			for (int k = 0; k < OBJLEVEL; ++k)
			{
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objImage[k] = nullptr;
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objImageIndex[k] = 100;
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objFrameX[k] = 0;
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objFrameY[k] = 0;
				if (_tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].objImage[k] == nullptr) continue;

				if (_tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].tileObjZOrder[k] != 0)
					_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].tileObjZOrder[k] = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].tileObjZOrder[k] + (_pairBossDungeonStartPoint.second - _dungeonShape3.startY);
				else
					_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].tileObjZOrder[k] = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].tileObjZOrder[k];
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objImage[k] = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].objImage[k];
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objFrameX[k] = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].objFrameX[k];
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objFrameY[k] = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].objFrameY[k];
				_tiles[_pairBossDungeonStartPoint.first + i][_pairBossDungeonStartPoint.second + j].objImageIndex[k] = _tmpTile[_dungeonShape3.startX + i][_dungeonShape3.startY + j].objImageIndex[k];
			}
		}
	}
	_vWidthDungeonStartPoint.clear();
	_vLengthDungeonStartPoint.clear();
}
