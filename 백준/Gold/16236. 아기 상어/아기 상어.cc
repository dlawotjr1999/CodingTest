#include <bits/stdc++.h>

const int dir_x[4] = { 0,1,0,-1 };
const int dir_y[4] = { -1,0,1,0 };

struct Info {
	int dist; int y; int x;
};

int field[21][21];

int N;
int answer;

Info BFS(int sy, int sx, int size) {
	std::queue<std::pair<int, int>> q;
	std::vector<std::vector<int>> dist(N + 1, std::vector<int>(N + 1, -1));
	std::vector<Info> coords;

	q.emplace(sy, sx);
	dist[sy][sx] = 0;

	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];

			if (ny < 1 || ny > N || nx < 1 || nx > N)
				continue;
			if (dist[ny][nx] != -1) 
				continue;
			if (field[ny][nx] > size) 
				continue;

			dist[ny][nx] = dist[y][x] + 1;
			q.emplace(ny, nx);

			if (field[ny][nx] != 0 && field[ny][nx] < size) {
				coords.push_back({ dist[ny][nx], ny, nx });
			}
		}
	}

	if (coords.empty()) {
		return { -1, -1, -1 };
	}

	std::sort(coords.begin(), coords.end(), [](const auto& l, const auto& r) {
		if (l.dist != r.dist)
			return l.dist < r.dist;
		if (l.y != r.y)
			return l.y < r.y;
		return l.x < r.x;
	});

	return coords[0];
}

int main() {
	std::cin >> N;
	int sy = 0, sx = 0;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			std::cin >> field[i][j];
			
			if (field[i][j] == 9) { sy = i; sx = j; field[i][j] = 0; }
		}
	}

	int cur_size = 2;
	int cur_eat = 0;

	while (true) {
		Info fish = BFS(sy, sx, cur_size);

		if (fish.dist == -1) 
			break;
		answer += fish.dist;

		sx = fish.x; sy = fish.y;
		field[sy][sx] = 0;
		cur_eat++;

		if (cur_eat == cur_size) {
			cur_size++;
			cur_eat = 0;
		}
	}

	std::cout << answer;
	return 0;
}