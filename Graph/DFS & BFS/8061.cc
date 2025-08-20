#include <bits/stdc++.h>

// 2차원 배열에서 검은 픽셀은 0, 흰 픽셀은 1로 표시할 때 비트맵의 공식은 아래와 같음
// 어떤 한 검은 픽셀(p1)에 대해 가장 가까운 흰 픽셀(p2)에 대하여 d(p1,p2)=|i_1-i_2|+|j_1-j_2|, p1 = (i_1, j_1), p2 = (i_2, j_2)
// 이 때, 각 픽셀에 대하여 가장 가까운 흰 픽셀과의 거리들을 구하는 문제

int m, n;
int INF = 10e6;

bool input_field[183][183];
int output_field[183][183];

// 문제에 의하여 d를 구하는 공식으로 Manhattan distance 사용
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, -1, 0, 1 };

void BFS(int x, int y) {
	std::queue<std::pair<int, int>> q;

	// output_field에서 흰 픽셀은 0으로, 검은 픽셀은 INF로 초기화
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (input_field[i][j]) {
				output_field[i][j] = 0;
				q.emplace(i, j);
			}
			else {
				output_field[i][j] = INF;
			}
		}
	}

	// 각 픽셀들에 대해 한 칸씩 이동하면서 가장 가까운 흰 픽셀과의 거리 갱신 
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int cur_x = x + dir_x[i];
			int cur_y = y + dir_y[i];

			if (cur_x < 1 || cur_x > n || cur_y < 1 || cur_y > m) continue;
			if (output_field[cur_x][cur_y] > output_field[x][y] + 1) {
				output_field[cur_x][cur_y] = output_field[x][y] + 1;
				q.emplace(cur_x, cur_y);
			}
		}
	}
}

int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		std::string input;
		std::cin >> input;

		for (int j = 1; j <= m; ++j) {
			input_field[i][j] = input[j - 1] - '0';
		}
	}

	BFS(n, m);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			std::cout << output_field[i][j] << (j == m ? '\n' : ' ');
		}
	}

	return 0;
}