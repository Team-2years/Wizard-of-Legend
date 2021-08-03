#pragma once
#include "stdafx.h"
#include "gameNode.h"
#include "ItemBasic.h"
#include "singletonBase.h"

#define MAXRELICS 24
#define MAXCLOTH 16



struct SaveData
{

	int Jewel;


	//vector<ItemBasic> Data_Relics;
	//vector<ItemBasic> Data_Cloth;
	//vector<ItemBasic> Basic_Arcana;
	//vector<ItemBasic> Movement_Arcana;
	//vector<ItemBasic> Standard_Arcana;
	//vector<ItemBasic> Signiture_Arcana;
	
	int Attack_Relics_Data[MAXRELICS];
	int Defense_Relics_Data[MAXRELICS];
	int Other_Relics_Data[MAXRELICS];


	
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																		
};


class SaveDataManager : public singletonBase<SaveDataManager>
{
private:

	SaveData Data;

	

public:


	virtual HRESULT init();
	virtual void release();
	virtual void update();
	
	SaveData getData() { return Data; }


	
	void setJewel(int a) { Data.Jewel = a; }

	void DataSave_Attack_Relics(vector<ItemBasic*> that);
	void DataSave_Defense_Relics(vector<ItemBasic*> that);
	void DataSave_Other_Relics(vector<ItemBasic*> that);

	/*
	스킬 구분할 변수 타입 int //추후 변동 가능성 있음
	*/
	
	//디버깅용. 데이터 삭제 
	void deleteData();
	





	void save_Attack_Relics();
	void save_Defense_Relics();
	void save_Other_Relics();



	void Load_Attack_Relics();
	void Load_Defense_Relics();
	void Load_Other_Relics();

};

