#include "AlgorithmManager.h"

void AlgorithmManager::algorithmManager(void)
{
	/*
	総当たりか数手先読みか判断して読み出す
	*/
	if (turn < THRESHOLD)
	{
		BruteForce bruteForce;
		bruteForce.bruteForce();

	}
	else
	{
		Prefetching prefetching;
		prefetching.prefetching();

		AddEvaluation addEvaluation;
		addEvaluation.addEvaluation();
	}
}
