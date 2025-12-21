#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int MAX = 100;

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

int M, N, K;
std::vector<std::vector<std::pair<bool, bool>>> field;
std::vector<int> areas;

void BFS(int x, int y) {
	std::queue<std::pair<int, int>> q;

	q.emplace(x, y);
	field[y][x].second = true;
	int area = 1;

	while (!q.empty()) {
		auto [c, r] = q.front();
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int nx = c + dir_x[k];
			int ny = r + dir_y[k];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (field[ny][nx].first || field[ny][nx].second)
				continue;   

			field[ny][nx].second = true;
			area++;
			q.emplace(nx, ny);
		}
	}
	areas.push_back(area);
}

int main() {
	std::cin >> M >> N >> K;
	field.resize(MAX, std::vector<std::pair<bool, bool>>(MAX, { false, false }));

	for (int i = 0; i < K; ++i) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;

		for (int i = b; i < d; ++i) {
			for (int j = a; j < c; ++j) {
				if (field[i][j].first)
					continue;
				field[i][j].first = true;
			}
		}
	}

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!field[i][j].first && !field[i][j].second) {
				BFS(j, i);
			}
		}
	}

	std::sort(areas.begin(), areas.end());
	std::cout << areas.size() << '\n';
	for (int area : areas) 
		std::cout << area << ' ';
	
	return 0;
}