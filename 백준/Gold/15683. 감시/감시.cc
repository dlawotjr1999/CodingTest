#include <bits/stdc++.h>

int dir1_x[4] = { 1,0,-1,0 };
int dir1_y[4] = { 0,1,0,-1 };

int dir2_x[2][2] = { {-1,1},{0,0} };
int dir2_y[2][2] = { {0,0}, {-1,1} };

int dir3_x[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
int dir3_y[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

int dir4_x[4][3] = { {-1,0,1}, {0,1,0}, {1,0,-1}, {0,-1,0} };
int dir4_y[4][3] = { {0,-1,0}, {-1,0,1}, {0,1,0}, {1,0,-1} };

int dir5_x[4] = { 1,0,-1,0 };
int dir5_y[4] = { 0,1,0,-1 };

int N, M;
int answer = 100;

int field[9][9];
int temp[9][9];

std::vector<std::pair<int, int>> cctv;

void Watch(int y, int x, int dy, int dx) {
	int nx = x + dx;
	int ny = y + dy;

	while (1) {
		if (nx < 1 || ny < 1 || nx > M || ny > N)
			break;
		if (temp[ny][nx] == 6)
			break;

		if (temp[ny][nx] == 0)
			temp[ny][nx] = -1;

		nx += dx;
		ny += dy;
	}
}

void DFS(int idx) {
	if (idx == cctv.size()) {
		int cnt = 0;

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				if (temp[i][j] == 0)
					cnt++;
			}
		}

		answer = std::min(answer, cnt);
		return;
	}

	int y = cctv[idx].first;
	int x = cctv[idx].second;
	int type = field[y][x];

	int cur_field[9][9];
	memcpy(cur_field, temp, sizeof(temp));

	if (type == 1) {
		for (int d = 0; d < 4; ++d) {
			Watch(y, x, dir1_y[d], dir1_x[d]);
			DFS(idx + 1);
			memcpy(temp, cur_field, sizeof(temp));
		}
	}
	else if (type == 2) {
		for (int d = 0; d < 2; ++d) {
			for (int k = 0; k < 2; ++k) {
				Watch(y, x, dir2_y[d][k], dir2_x[d][k]);
			}
			DFS(idx + 1);
			memcpy(temp, cur_field, sizeof(temp));
		}
	}
	else if (type == 3) {
		for (int d = 0; d < 4; ++d) {
			for (int k = 0; k < 2; ++k) {
				Watch(y, x, dir3_y[d][k], dir3_x[d][k]);
			}
			DFS(idx + 1);
			memcpy(temp, cur_field, sizeof(temp));
		}
	}
	else if (type == 4) {
		for (int d = 0; d < 4; ++d) {
			for (int k = 0; k < 3; ++k) {
				Watch(y, x, dir4_y[d][k], dir4_x[d][k]);
			}
			DFS(idx + 1);
			memcpy(temp, cur_field, sizeof(temp));
		}
	}
	else if (type == 5) {
		for (int d = 0; d < 4; ++d) {
			Watch(y, x, dir5_y[d], dir5_x[d]);
		}
		DFS(idx + 1);
		memcpy(temp, cur_field, sizeof(temp));
	}
}

int main() {
	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			std::cin >> field[i][j];

			if (1 <= field[i][j] && field[i][j] <= 5)
				cctv.emplace_back(i, j);
		}
	}

	memcpy(temp, field, sizeof(field));
	DFS(0);

	std::cout << answer << '\n';
	return 0;
}