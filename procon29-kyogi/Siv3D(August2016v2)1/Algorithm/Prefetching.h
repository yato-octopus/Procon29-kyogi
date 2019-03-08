#pragma once
#include "../Data/Map.h"
#include "../Data/Masu.h"
#include "../Setting.h"
#include "../gneral.h"
#include "Candidate.h"
#include <vector>
#include <queue>
#define INF 1e09
#define MTURN 40

class Prefetching {
public:
	pair<int, int> prefetching(Agent, int);
	int evl(Candidate, bool enemy_visited[VERTICAL][WIDTH], int);
	static int caluculateAreaScore(Masu::StateOfMasu);
	static bool isVisited(vector<pair<Masu, pair<int, int>>> route, int newX, int newY, Masu::StateOfMasu st) {
		for (pair<Masu, pair<int, int>> p : route) {
			if (newX == p.second.first && newY == p.second.second  && p.first.Status != (st == Masu::EnemyTile ? Masu::FriendTile : Masu::EnemyTile)) return true;
		}
		return false;
	}
	int evl_params[5] = { 5, 3, 4, 3, 2}; //重み．順に，領域点，自チームの囲み，相手チームの囲み，エージェント間距離，自由度
private:

};