#include <iostream>

// 다음을 구현하는 문제
// https://www.acmicpc.net/problem/17070

static constexpr int MAX = 16;

int N, answer;
int field[MAX][MAX];

void DFS(int x, int y, int dir) {
	// (N-1, N-1)에 도달하면 올바른 파이프 설치
	if (x == N - 1 && y == N - 1) {
		answer++;
		return;
	}

	// 이전 방향이 가로 또는 대각선일 경우에 가로 방향으로 놓을 수 있음
	if (dir == 0 || dir == 2) {
		int nx = x + 1, ny = y;
		if (nx < N && field[ny][nx] == 0)
			DFS(nx, ny, 0);
	}

	// 이전 방향이 세로 또는 대각선일 경우에 세로 방향으로 놓을 수 있음
	if (dir == 1 || dir == 2) {
		int nx = x, ny = y + 1;
		if (ny < N && field[ny][nx] == 0)
			DFS(nx, ny, 1);
	}

	// 이전 방향이 대각선일 경우 모든 방향을 놓을 수 있음
	// 대각선 방향에 놓을 경우, (x+1, y+1), (x, y+1), (x+1, y) 세 칸이 모두 비어있어야 함
	int nx = x + 1, ny = y + 1;
	if (nx < N && ny < N && field[ny][nx] == 0 && field[ny - 1][nx] == 0 && field[ny][nx - 1] == 0)
		DFS(nx, ny, 2);
}


int main() {
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> field[i][j];
		}
	}

	// 0-based로 하여 탐색 시작
	DFS(1, 0, 0);

	std::cout << answer;
	return 0;
}