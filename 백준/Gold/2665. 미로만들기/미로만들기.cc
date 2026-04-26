#include <bits/stdc++.h>

const int MAX = 50;
const int INF = 1e9;

const int dir_x[4] = { 0,1,0,-1 };
const int dir_y[4] = { -1,0,1,0 };

struct info {
	int cost;
	int y, x;

	bool operator>(const auto& other) const {
		return cost > other.cost;
	}
};

int N;
int answer;

int field[MAX + 1][MAX + 1];

int Dijkstra() {
	std::vector<std::vector<int>> dist(N + 1, std::vector<int>(N + 1, INF));
	std::priority_queue<info, std::vector<info>, std::greater<info>> pq;
	
	pq.push({ 0, 1, 1 });
	dist[1][1] = 0;

	while (!pq.empty()) {
		auto [cur_cost, cur_y, cur_x] = pq.top();
		pq.pop();

		if (dist[cur_y][cur_x] < cur_cost)
			continue;

		for (int i = 0; i < 4; ++i) {
			int ny = cur_y + dir_y[i];
			int nx = cur_x + dir_x[i];

			if (ny < 1 || ny > N || nx < 1 || nx > N)
				continue;

			int next_cost = cur_cost + field[ny][nx];

			if (next_cost < dist[ny][nx]) {
				dist[ny][nx] = next_cost;
				pq.push({ next_cost, ny, nx });
			}
		}
	}

	return dist[N][N];
}

int main() {
	std::cin >> N;

	for (int i = 1; i <= N; ++i) {
		std::string row; 
		std::cin >> row;

		for (int j = 1; j <= row.length(); ++j) {
			field[i][j] = (row[j - 1] == '0' ? 1 : 0);
		}
	}

	std::cout << Dijkstra();
	return 0;
}