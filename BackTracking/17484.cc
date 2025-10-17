#include <iostream>
#include <vector>
#include <climits>

// N * M 격자에서 위에서 아래로 이동하며 연료의 합이 최소가 되도록 경로를 찾는 문제
// 단, 아래, 왼쪽 아래, 오른쪽 아래로만 이동할 수 있으며, 같은 방향으로 두 번 연속 이동할 수는 없음

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

		// 이전과 같은 방향일 경우 무시
		if (last == i)
			continue;

		// 다음 단계로 진입
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

	// y좌표, x좌표, 누적 연료양, 방향을 인자로 하여 탐색 진행
	for (int i = 0; i < M; ++i) {
		DFS(0, i, board[0][i], -1);
	}

	std::cout << answer;
	return 0;
}