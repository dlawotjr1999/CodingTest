#include <iostream>
#define MAX 100

// N x N 게임판에 수가 적혀으며, 이 게임의 목표는 가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 점프를 해서 가는 것
// 0은 더 이상 진행을 막는 종착점이며, 항상 현재 칸에 적혀있는 수만큼 오른쪽이나 아래로 가야 하며, 한 번 점프를 할 때 방향을 바꾸면 안 된다
// 이 때 가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 이동할 수 있는 경로의 갯수를 구하는 문제

int field[MAX][MAX];
long long dp[MAX][MAX]; // = { -1, };

int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> field[i][j];
		}
	}

	// 시작 지점(0,0)에서 시작하는 방법은 한 가지
	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			// 만약 field[i][j]가 0이라면, 해당 칸은 점프할 수 없으므로 건너뛰기
			if (field[i][j] == 0)
				continue;

			// i + field[i][j]가 범위를 벗어나지 않으면
			// 현재 칸에서 점프할 수 있는 칸 (아래쪽)으로 이동 가능
			if (i + field[i][j] < N)
				dp[i + field[i][j]][j] += dp[i][j];

			// j + field[i][j]가 범위를 벗어나지 않으면
			// 현재 칸에서 점프할 수 있는 칸 (오른쪽)으로 이동 가능
			if (j + field[i][j] < N)
				dp[i][j + field[i][j]] += dp[i][j];
		}
	}

	std::cout << dp[N - 1][N - 1];
	// std::cout << DFS(0, 0);

	return 0;
}

// DFS(완전탐색)을 활용한 다른 풀이
/*
long long dfs(int x, int y) {
	if (x >= N || y >= N) return 0;			// (x, y)가 (N-1, N-1) 이후로 넘어가면 경로가 존재하지 않음
	if (x == N - 1 && y == N - 1) return 1; // (x, y)가 도착 지점 (N-1, N-1)이라면 1개의 경로를 찾은 것

	if (dp[x][y] != -1) return dp[x][y];	// 이미 계산된 값이 있으면 그 값을 반환 (메모이제이션)

	dp[x][y] = 0;	// DFS는 경로를 탐색하며 재귀적으로 경로 수를 누적하는 방식이기 때문에 경로 수를 계산하기 전에 0으로 초기화하고, 그 후에 경로를 갱신해야 함

	int jump = field[x][y];
	if (jump == 0) return 0;

	dp[x][y] += dfs(x + jump, y); // 아래쪽
	dp[x][y] += dfs(x, y + jump); // 오른쪽

	return dp[x][y];
}
*/