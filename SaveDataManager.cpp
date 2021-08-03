#include "stdafx.h"
#include "SaveDataManager.h"
#include "ItemBasic.h"



HRESULT SaveDataManager::init()
{
	//Load_Attack_Relics();
	//Load_Defense_Relics();
	//Load_Other_Relics();

	
	for (int i = 0; i < MAXRELICS; i++)
	{
		Data.Attack_Relics_Data[i] = 99999;
		Data.Defense_Relics_Data[i] = 99999;
		Data.Other_Relics_Data[i] = 99999;
	}
	
	
	Data.Jewel = 0;

	return S_OK;
}

void SaveDataManager::release()
{
}

void SaveDataManager::update()
{	
	//if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) this->save();	
	//if (KEYMANAGER->isOnceKeyDown(VK_RETURN)) this->load();
}



void SaveDataManager::DataSave_Attack_Relics(vector<ItemBasic*> that)
{

	for (int i = 0; i < that.size(); i++)
	{
		Data.Attack_Relics_Data[i] = that[i]->getItemNumber();
	}
	save_Attack_Relics();
}

void SaveDataManager::DataSave_Defense_Relics(vector<ItemBasic*> that)
{
	for (int i = 0; i < that.size(); i++)
	{
		Data.Defense_Relics_Data[i] = that[i]->getItemNumber();
	}
	save_Defense_Relics();
}

void SaveDataManager::DataSave_Other_Relics(vector<ItemBasic*> that)
{
	for (int i = 0; i < that.size(); i++)
	{
		Data.Other_Relics_Data[i] = that[i]->getItemNumber();
	}
	save_Other_Relics();
}



void SaveDataManager::deleteData()
{

}


void SaveDataManager::save_Attack_Relics()
{
	HANDLE file;
	DWORD write;

	file = CreateFile("Data_Attack_Relics.map", GENERIC_WRITE, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, &Data.Attack_Relics_Data, sizeof(int) * MAXRELICS, &write, NULL);

	CloseHandle(file);
}

void SaveDataManager::save_Defense_Relics()
{
	HANDLE file;
	DWORD write;

	file = CreateFile("Data_Defense_Relics.map", GENERIC_WRITE, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, &Data.Defense_Relics_Data, sizeof(int) * MAXRELICS, &write, NULL);

	CloseHandle(file);

}

void SaveDataManager::save_Other_Relics()
{
	HANDLE file;
	DWORD write;

	file = CreateFile("Data_Other_Relics.map", GENERIC_WRITE, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, &Data.Other_Relics_Data, sizeof(int) * MAXRELICS, &write, NULL);

	CloseHandle(file);

}



void SaveDataManager::Load_Attack_Relics()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("Data_Attack_Relics.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, &Data.Attack_Relics_Data, sizeof(int) * MAXRELICS, &read, NULL);

	CloseHandle(file);

}

void SaveDataManager::Load_Defense_Relics()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("Data_Defense_Relics.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, &Data.Attack_Relics_Data, sizeof(int) * MAXRELICS, &read, NULL);

	CloseHandle(file);

}

void SaveDataManager::Load_Other_Relics()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("Data_Other_Relics.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, &Data.Attack_Relics_Data, sizeof(int) * MAXRELICS, &read, NULL);

	CloseHandle(file);

}
