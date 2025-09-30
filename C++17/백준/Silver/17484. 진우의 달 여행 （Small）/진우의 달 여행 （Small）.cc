#include <iostream>
#include <vector>
#include <climits>

int N, M;
int answer = INT_MAX;

int board[7][7];
int dx[3] = { -1, 0, 1 };

void DFS(int y, int x, int fuel, int last) {
	if (y == N - 1) {
		answer = std::min(answer, fuel);
		return;
	}

	for (int i = 0; i < 3; ++i) {
		int cur_x = x + dx[i];

		if (last == i)
			continue;

		if (0 <= cur_x && cur_x < M) {
			DFS(y + 1, cur_x, fuel + board[y + 1][cur_x], i);
		}
	}
}

int main() {
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> board[i][j];
		}
	}

	for (int i = 0; i < M; ++i) {
		DFS(0, i, board[0][i], -1);
	}

	std::cout << answer;
	return 0;
}