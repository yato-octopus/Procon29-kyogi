#include "InputOutputManager.h"

DrawMap *drawMap;
CreateMapClass *createMap;

InputOutputManager::InputOutputManager()
{
	//createMap->createMapClass();
}

void InputOutputManager::inputOuntputManager(void)
{
	//クラス変数の定義
	//CreateMapClass *createMap;

	//UpdateTurnInfo *updateTurn;
	//Interrupt *interrupt;
	//DrawMap,CreateMapClass,Interrupt,UpdateTurnInfoの制御
	drawMap->drawManager();
	//interrupt->interruptManager();
	//updateTurn->updateManager();
}
