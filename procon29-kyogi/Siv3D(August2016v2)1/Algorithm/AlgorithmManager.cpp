#include "AlgorithmManager.h"

void AlgorithmManager::algorithmManager(void)
{
	/*
	総当たりか数手先読みか判断して読み出す
	*/
	Setting *setting;
	setting = setting->getSetting();
	if (setting->bruteForce) {
		BruteForce bruteForce;
		bruteForce.bruteForce();
	} else {
		AddEvaluation addEvaluation;
		addEvaluation.addEvaluation();
	}
}