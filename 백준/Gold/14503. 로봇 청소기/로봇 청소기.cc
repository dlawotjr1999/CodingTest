#include <bits/stdc++.h>

int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };

int N, M;
int answer;
std::pair<int, bool> field[50][50];

int cur_r, cur_c;
int cur_dir;

bool isInArea(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

int main() {
	std::cin >> N >> M;

	int r, c, d;
	std::cin >> r >> c >> d;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int elm; std::cin >> elm;
			field[i][j] = { elm, false };
		}
	}

	cur_r = r, cur_c = c;
	cur_dir = d;

	while (true) {
		if (!field[cur_r][cur_c].second) {
			field[cur_r][cur_c].second = true;
			answer++;
		}

		bool moved = false;

		for (int i = 0; i < 4; ++i) {
			cur_dir = (cur_dir + 3) % 4;
			int nr = cur_r + dir_y[cur_dir];
			int nc = cur_c + dir_x[cur_dir];

			// 사방에 청소되지 않은 빈 칸 탐색
			if (isInArea(nr, nc) && field[nr][nc].first == 0 && !field[nr][nc].second) {
				cur_r = nr;
				cur_c = nc;
				moved = true;
				break;
			}
		}

		// 사방에 청소되지 않은 빈 칸이 없는 경우
		if (!moved) {
			int back_dir = (cur_dir + 2) % 4;
			int nr = cur_r + dir_y[back_dir];
			int nc = cur_c + dir_x[back_dir];

			if (isInArea(nr, nc) && field[nr][nc].first == 0) {
				cur_r = nr;
				cur_c = nc;
			}
			else	
				break;
		}
	}

	std::cout << answer;
	return 0;
}