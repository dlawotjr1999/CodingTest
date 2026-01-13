#include <bits/stdc++.h>

int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };

const int MAX = 125;
const int INF = 100000;

struct info {
	int cost, x, y;

	bool operator<(const info& other) const {
		return cost > other.cost;
	}
};

int N;
int field[MAX][MAX];

int Dijkstra() {
	std::vector<std::vector<int>> dist(N, std::vector<int>(N, INF));

	std::priority_queue<info> pq;
	pq.push({field[0][0], 0, 0});
	dist[0][0] = field[0][0];

	while (!pq.empty()) {
		auto [cost, x, y] = pq.top();
		pq.pop();

		if (cost > dist[y][x])
			continue;

		for (int i = 0; i < 4; ++i) {
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;

			int next_cost = cost + field[ny][nx];

			if (next_cost < dist[ny][nx]) {
				dist[ny][nx] = next_cost;
				pq.push({ next_cost, nx, ny });
			}
		}
	}

	return dist[N - 1][N - 1];
}

int main() {
	int seq = 1;

	while (true) {
		std::cin >> N;
		if (N == 0)
			break;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				std::cin >> field[i][j];
			}
		}
		printf("Problem %d: %d\n", seq, Dijkstra());
		
		memset(field, 0, sizeof(field));
		seq++;
	}

	return 0;
}