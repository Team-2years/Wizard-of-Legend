#include "stdafx.h"
#include "BinaryMapTree.h"
#include "TileClass.h"

BinaryMapTree::BinaryMapTree() :
	_maxWidth(TILESIZEX), _level(0), _maxIndexX(TILEX), _maxIndexY(TILEX)
{
}

BinaryMapTree::~BinaryMapTree()
{
}

void BinaryMapTree::createMap()
{
	if (_level == 4)
		return;

	int tmpX = RND->getFromIntTo(_maxIndexX * 0.4, _maxIndexX * 0.6);
	int tmpY = RND->getFromIntTo(_maxIndexY * 0.4, _maxIndexY * 0.6);

	_leftTree = new BinaryMapTree;
	_leftTree->setTileAddress(_tile);
	_leftTree->setLevel(_level + 1);
	_leftTree->setParentTree(this);
	if (_level % 2 == 0)
	{
		_leftTree->setIndexX(tmpX);
		for (int i = 0; i < tmpX; i++)
		{
			for (int j = 0; j < _leftTree->getMaxIndexY(); ++j)
			{
				_tile->setTileImage(i, j, 10, 3);
			}
		}
		_leftTree->setMaxIndexX(tmpX);
	}
	else
	{
		_leftTree->setIndexY(tmpY);
		_leftTree->setMaxIndexY(tmpY);
		for (int i = 0; i < _leftTree->getMaxIndexX(); i++)
		{
			for (int j = 0; j < tmpY; ++j)
			{
				_tile->setTileImage(i, j, 13, 3);
			}
		}
	}
	_leftTree->createMap();

	_rightTree = new BinaryMapTree;
	_rightTree->setTileAddress(_tile);
	_rightTree->setLevel(_level + 1);
	_rightTree->setParentTree(this);
	if (_level % 2 == 0)
	{
		_rightTree->setIndexX(_maxIndexX - tmpX);
		for (int i = tmpX; i < _rightTree->getMaxIndexX(); i++)
		{
			for (int j = tmpY; j < _rightTree->getMaxIndexY(); ++j)
			{
				_tile->setTileImage(i, j, 8, 7);
			}
		}
		_rightTree->setMaxIndexX(_maxIndexX - tmpX);
	}
	else
	{
		_rightTree->setIndexY(tmpY);
		_rightTree->setMaxIndexY(tmpY);
		for (int i = tmpX; i < _maxIndexX; i++)
		{
			for (int j = tmpY; j < _maxIndexY; ++j)
			{
				_tile->setTileImage(i, j, 5, 1);
			}
		}
	}
	_rightTree->createMap();
}

void BinaryMapTree::deleteAllTree()
{
	if (_leftTree == nullptr && _rightTree == nullptr)
		return;

	_leftTree->deleteAllTree();
	_rightTree->deleteAllTree();
	SAFE_DELETE(_leftTree);
	SAFE_DELETE(_rightTree);
}
