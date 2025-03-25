#include <iostream>
#include <queue>

int N, M;

int box[1000][1000];
int x_dir[4] = { -1, 0, 1, 0 };
int y_dir[4] = { 0, 1, 0, -1 };

std::queue<std::pair<int, int>> queue;

void BFS() {
	while (!queue.empty()) {
		int x = queue.front().first;
		int y = queue.front().second;
		queue.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = x + x_dir[i];
			int new_y = y + y_dir[i];

			if ((0 <= new_x && new_x < N) && (0 <= new_y && new_y < M)) {
				if (box[new_x][new_y] == 0) {
					box[new_x][new_y] = box[x][y] + 1;
					queue.emplace(new_x, new_y);
				}

			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> box[i][j];
			if (box[i][j] == 1) {
				queue.emplace(i, j);
			}
		}
	}

	BFS();

	int days = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {
				std::cout << -1 << std::endl;
				return 0;
			}
			days = std::max(days, box[i][j]);
		}
	}

	std::cout << days - 1 << std::endl;

	return 0;
}