#include <iostream>
#include <queue>

// 7576번 문제의 3차원 버전
// NOTE : 배열 내 index의 보정을 유의해야 함 

constexpr int MAX = 100;
int box[MAX][MAX][MAX];
std::queue<std::pair<int, std::pair<int, int>>> q;

int M, N, H;

int x_dir[6] = { -1, 0, 1, 0, 0, 0 };
int y_dir[6] = { 0, 1, 0, -1, 0, 0 };
int z_dir[6] = { 0, 0, 0, 0, 1, -1 };

void BFS() {
	while (!q.empty()) {
		int z = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int new_x = x + x_dir[i];
			int new_y = y + y_dir[i];
			int new_z = z + z_dir[i];

			if ((0 <= new_x && new_x < M) && (0 <= new_y && new_y < N) && (0 <= new_z && new_z < H)) {
				if (box[new_z][new_y][new_x] == 0) {
					box[new_z][new_y][new_x] = box[z][y][x] + 1;
					q.push({ new_z, { new_y, new_x } });
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				std::cin >> box[i][j][k];

				if (box[i][j][k] == 1) {
					q.push({ i, {j, k} });
				}
			}
		}
	}

	BFS();

	int days = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[i][j][k] == 0) {
					std::cout << -1 << std::endl;
					return 0;
				}
				days = std::max(days, box[i][j][k]);
			}
		}
	}

	std::cout << days - 1;
	return 0;
}