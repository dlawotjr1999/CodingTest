#include <iostream>
#include <vector>
#include <deque>
#include <climits>

int M, N;

int field[101][101];
int dist[101][101];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

void BFS(int y, int x) {
	std::deque<std::pair<int, int>> dq;
	dq.emplace_back(y, x);
	dist[y][x] = 0;

	while (!dq.empty()) {
		auto [cur_y, cur_x] = dq.front();
		dq.pop_front();

		for (int d = 0; d < 4; d++) {
			int ny = cur_y + dir_y[d];
			int nx = cur_x + dir_x[d];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N) 
				continue;

			int cost = dist[cur_y][cur_x] + field[ny][nx];
			if (cost < dist[ny][nx]) {
				dist[ny][nx] = cost;
				if (field[ny][nx] == 1)
					dq.emplace_back(ny, nx);
				else
					dq.emplace_front(ny, nx);
			}
		}
	}
}

int main() {
	std::cin >> M >> N;

	for (int i = 0; i < N; ++i) {
		std::string input;
		std::cin >> input;

		for (int j = 0; j < M; ++j) {
			field[i][j] = input[j] - '0';
			dist[i][j] = INT_MAX;
		}
	}

	BFS(0, 0);
	std::cout << dist[N - 1][M - 1];
	return 0;
}