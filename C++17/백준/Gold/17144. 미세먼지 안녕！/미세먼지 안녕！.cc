#include <iostream>
#include <vector>
#include <queue>

int R, C, T;
int answer;

std::vector<std::vector<int>> field;
std::vector<std::pair<int, int>> purifier_coord;

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

void Diffuse() {
	std::vector<std::vector<int>> tmp(R, std::vector<int>(C, 0));

	for (auto& p : purifier_coord)
		tmp[p.first][p.second] = -1;

	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {

			if (field[y][x] > 0) {
				int spread = field[y][x] / 5;
				int cnt = 0;

				for (int i = 0; i < 4; ++i) {
					int nx = x + dir_x[i];
					int ny = y + dir_y[i];

					if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
					if (field[ny][nx] == -1) continue;

					tmp[ny][nx] += spread;
					cnt++;
				}

				tmp[y][x] += field[y][x] - spread * cnt;
			}
		}
	}

	field = tmp;
}


void Rotate() {
	int top = purifier_coord[0].first;
	int bottom = purifier_coord[1].first;

	for (int i = top - 1; i > 0; --i)
		field[i][0] = field[i - 1][0];

	for (int i = 0; i < C - 1; ++i)
		field[0][i] = field[0][i + 1];

	for (int i = 0; i < top; ++i)
		field[i][C - 1] = field[i + 1][C - 1];

	for (int i = C - 1; i > 1; --i)
		field[top][i] = field[top][i - 1];

	field[top][1] = 0; 

	for (int i = bottom + 1; i < R - 1; ++i)
		field[i][0] = field[i + 1][0];

	for (int i = 0; i < C - 1; ++i)
		field[R - 1][i] = field[R - 1][i + 1];

	for (int i = R - 1; i > bottom; --i)
		field[i][C - 1] = field[i - 1][C - 1];

	for (int i = C - 1; i > 1; --i)
		field[bottom][i] = field[bottom][i - 1];

	field[bottom][1] = 0;
}

int main() {
	std::cin >> R >> C >> T;
	field.resize(R, std::vector<int>(C));

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			std::cin >> field[i][j];
			
			if (field[i][j] == -1)
				purifier_coord.emplace_back(i, j);
		}
	}

	while (T--) {
		Diffuse();
		Rotate();
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (field[i][j] > 0)
				answer += field[i][j];
		}
	}

	std::cout << answer;
	return 0;
}