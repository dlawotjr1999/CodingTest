#include <iostream>
#include <queue>

constexpr int MAX = 1000;

int field[MAX][MAX];
int dist[MAX][MAX][10];

int x_dir[4] = { -1, 0, 1, 0 };
int y_dir[4] = { 0, -1, 0, 1 };

int N, M, K;
int answer;

int BFS() {
	dist[0][0][0] = 1;

	std::queue<std::pair<std::pair<int, int>, int>> queue;
	queue.push({{ 0, 0 }, 0 });

	while (!queue.empty()) {
		int x = queue.front().first.first;
		int y = queue.front().first.second;
		int k = queue.front().second;
		queue.pop();

		if (x == N - 1 && y == M - 1)
			return dist[x][y][k];

		for (int i = 0; i < 4; i++) {
			int nx = x + x_dir[i];
			int ny = y + y_dir[i];
			int nk = k;

			if ((0 <= nx && nx < N) && (0 <= ny && ny < M) && !dist[nx][ny][nk]) {
				if (field[nx][ny] == 0) {
					dist[nx][ny][nk] = dist[x][y][nk] + 1;
					queue.push({ { nx, ny }, nk });
				}
				if (field[nx][ny] == 1 && k < K) {
					if (dist[nx][ny][k + 1])
						continue;
					dist[nx][ny][k + 1] = dist[x][y][k] + 1;
					queue.push({ { nx, ny }, nk + 1 });
				}
			}
		}
	}
	return -1;
}

int main() {
	std::cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		std::string input;
		std::cin >> input;

		for (int j = 0; j < M; j++) {
			field[i][j] = input[j] - '0';
		}
	}

	std::cout << BFS();
	return 0;
}