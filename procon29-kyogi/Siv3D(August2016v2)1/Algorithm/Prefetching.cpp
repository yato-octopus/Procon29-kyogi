#include "Prefetching.h"

pair<int, int> Prefetching::prefetching(Agent agent)
{
	Map *map;
	map = map->getMap();
	pair<int, int> ans;
	queue<Candidate*> candidates;
	Candidate initialCand(agent.position.second, agent.position.first, 0, nullptr);
	unordered_map<string, Candidate> visited;
	Candidate best = initialCand;
	candidates.push(&initialCand);
	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	Candidate c;

	int bestEvl = -INF;

	// TODO: (x, y)順序バラバラ問題の最終的解決

	while (!candidates.empty()) {
		c = *(candidates.front()); Candidate* c_pt = candidates.front(); candidates.pop();
		for (int i = 0; i < 8; ++i) {
			pair<int, int> pos = make_pair(c.pos.first + dx[i], c.pos.second + dy[i]);
			if (pos.first >= 0 && pos.first < map->Width) {
				if (pos.second >= 0 && pos.second < map->Vertical) {
					Candidate* nextCand = new Candidate();
					nextCand->pos = pos;
					nextCand->step = c.step + 1;
					nextCand->before = c_pt;
					int newEvl = -INF;

					if (c.step < SEARCH_DEPTH) {
						newEvl = evl(*nextCand);
						candidates.push(nextCand);
						if (newEvl > bestEvl) {
							best = *nextCand;
							bestEvl = newEvl;
						}
					}
				}
			}
		}
	}

	if (best.before == nullptr) {
		return make_pair(agent.position.first, agent.position.second);
	}

	do{
		best = *(best.before);
	} while (best.before->step > 0);

	return make_pair(best.pos.second, best.pos.first);
}

int Prefetching::evl(Candidate c) {
	int point = 0;
	Map *map;
	map = map->getMap();

	// TODO: 獲得済みタイルを計算に含めない
	while (c.before != nullptr) {
		point += map->board[c.pos.second][c.pos.first].TilePoint;
		c = *(c.before);
	}
	
	return point;
}

void Prefetching::caluculateEncircle(vector<pair<Masu, pair<int, int>>> route, int nowX, int nowY, vector< vector<int> >& visited, Masu::StateOfMasu st)
{
	int dy[] = { 1, 0, -1, 0 };
	int dx[] = { 0, 1, 0, -1 };

	//経路 route をとったときの，stチームによる囲み判定をする
	Map map = *(Map::getMap());

	//水を4近傍にドバーッと流す
	for (int i = 0; i < 4; ++i) {
		visited[nowY][nowX] = 1;
		int newX = nowX + dx[i];
		int newY = nowY + dy[i];
		//4近傍に水が流れ込む処理．マップ範囲内で，なおかつ経路に含まれてなく，タイルが置かれてない
		if (newX >= 0 && newX <= map.Width + 1 && newY >= 0 && newY <= map.Vertical + 1) {
			if (!visited[newY][newX] && !isVisited(route, newX, newY, st) && map.board[newY][newX].Status != st) {
				caluculateEncircle(route, newX, newY, visited, st);
			}
		}
	}
}
