#include <iostream>
#include <queue>

int N;
int answer = -1;

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

std::pair<int, bool> field[101][101];
bool visited[101][101];

void BFS(int y, int x) {
	std::queue<std::pair<int, int>> q;
	q.emplace(y, x);
	visited[y][x] = true;

	while (!q.empty()) {
		auto [cur_y, cur_x] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int dy = cur_y + dir_y[i];
			int dx = cur_x + dir_x[i];

			if (dy < 1 || dy > N || dx < 1 || dx > N) 
				continue;
			if (field[dy][dx].second) 
				continue;

			if (!visited[dy][dx]) {
				q.emplace(dy, dx);
				visited[dy][dx] = true;
			}
		}
	}
}

int main() {
	std::cin >> N;
	int max_h = -1;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			std::cin >> field[i][j].first;
			field[i][j].second = false;
			max_h = std::max(max_h, field[i][j].first);
		}
	}

	for (int h = 0; h <= max_h; ++h) {
		int cnt = 0;

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				field[i][j].second = (field[i][j].first <= h);
				visited[i][j] = false;
			}
		}

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (!field[i][j].second && !visited[i][j]) {
					BFS(i, j);
					cnt++;
				}
			}
		}
		answer = std::max(answer, cnt);
	}

	std::cout << answer;
	return 0;
}