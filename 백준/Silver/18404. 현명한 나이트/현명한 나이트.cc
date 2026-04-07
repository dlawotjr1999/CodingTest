#include <bits/stdc++.h>

const int dir_x[8] = { 1,2,2,1,-1,-2,-2,-1 };
const int dir_y[8] = { 2,1,-1,-2,-2,-1,1,2 };

int N, M;
std::vector<std::pair<int, int>> enemy;
std::vector<std::vector<int>> dist;

void BFS(int sy, int sx) {
	std::queue<std::pair<int, int>> q;

	q.emplace(sy, sx);
	dist[sy][sx] = 0;

	while (!q.empty()) {
		auto [cur_y, cur_x] = q.front();
		q.pop();

		for (int i = 0; i < 8; ++i) {
			int dx = cur_x + dir_x[i];
			int dy = cur_y + dir_y[i];

			if (dx < 1 || dx > N || dy < 1 || dy > N)
				continue;
			if (dist[dy][dx] != -1)
				continue;

			dist[dy][dx] = dist[cur_y][cur_x] + 1;
			q.emplace(dy, dx);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M;
	
	int sy, sx;
	std::cin >> sy >> sx;

	dist.resize(N + 1, std::vector<int>(N + 1, -1));
	BFS(sy, sx);

	std::vector<int> answers;
	for (int i = 0; i < M; ++i) {
		int ey, ex;
		std::cin >> ey >> ex;
		answers.push_back(dist[ey][ex]);
	}

	for (int num : answers) {
		std::cout << num << ' ';
	}
	return 0;
}