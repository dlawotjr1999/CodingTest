#include <bits/stdc++.h>

// 2���� �迭���� ���� �ȼ��� 0, �� �ȼ��� 1�� ǥ���� �� ��Ʈ���� ������ �Ʒ��� ����
// � �� ���� �ȼ�(p1)�� ���� ���� ����� �� �ȼ�(p2)�� ���Ͽ� d(p1,p2)=|i_1-i_2|+|j_1-j_2|, p1 = (i_1, j_1), p2 = (i_2, j_2)
// �� ��, �� �ȼ��� ���Ͽ� ���� ����� �� �ȼ����� �Ÿ����� ���ϴ� ����

int m, n;
int INF = 10e6;

bool input_field[183][183];
int output_field[183][183];

// ������ ���Ͽ� d�� ���ϴ� �������� Manhattan distance ���
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, -1, 0, 1 };

void BFS(int x, int y) {
	std::queue<std::pair<int, int>> q;

	// output_field���� �� �ȼ��� 0����, ���� �ȼ��� INF�� �ʱ�ȭ
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

	// �� �ȼ��鿡 ���� �� ĭ�� �̵��ϸ鼭 ���� ����� �� �ȼ����� �Ÿ� ���� 
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