#include <bits/stdc++.h>

const int dir_x[4][3] = { {0,0,-1},{0,0,1},{0,-1,0},{0,1,0} };
const int dir_y[4][3] = { {0,-1,0},{0,-1,0},{0,0,1},{0,0,1} };

int field[4][4];

int K;
int x, y;

int N;
bool isCompleted;

void DFS(int num, int cnt) {
	if (isCompleted)
		return;

	if (cnt == ((N * N) - 1) / 3) {
		for (int i = (N - 1); i >= 0; --i) {
			for (int j = 0; j < N; ++j) {
				std::cout << field[i][j] << ' ';
			}
			std::cout << '\n';
		}

		isCompleted = true;
		return;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (field[i][j] == 0) {

				for (int d = 0; d < 4; ++d) {
					bool isPossible = true;

					for (int e = 0; e < 3; ++e) {
						int dx = j + dir_x[d][e];
						int dy = i + dir_y[d][e];

						if (dx < 0 || dx >= N || dy < 0 || dy >= N || field[dy][dx] != 0) {
							isPossible = false;
							break;
						}
					}

					if (isPossible) {
						for (int e = 0; e < 3; ++e) {
							int dx = j + dir_x[d][e];
							int dy = i + dir_y[d][e];
							
							field[dy][dx] = num;
						}

						DFS(num + 1, cnt + 1);

						for (int e = 0; e < 3; ++e) {
							int dx = j + dir_x[d][e];
							int dy = i + dir_y[d][e];

							field[dy][dx] = 0;
						}
					}
				}
			}
		}
	}
}

int main() {
	std::cin >> K;
	std::cin >> x >> y;
	N = 1 << K;

	field[y - 1][x - 1] = -1;
	DFS(1, 0);

	return 0;
}