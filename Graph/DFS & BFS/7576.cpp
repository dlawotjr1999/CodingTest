#include <iostream>
#include <queue>

int N, M;

int box[1000][1000];
int x_dir[4] = { -1, 0, 1, 0 };
int y_dir[4] = { 0, 1, 0, -1 };

// 시작 지점이 한 군데가 아니므로 전역적으로 queue를 선언하여 구해야 함
std::queue<std::pair<int, int>> queue;

// 모든 토마토가 익는 '최소 시간', 즉 최단성을 요구하므로 BFS로 풀어야 함
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
					// 다음 날에 인접한 토마토를 익힌 다음, 익기까지의 걸린 날짜를 기록함
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

	// 시작이 1이기 때문에 걸린 날짜는 그 최댓값에서 1을 빼주어야한다
	std::cout << days - 1 << std::endl;

	return 0;
}