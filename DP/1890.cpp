#include <iostream>
#define MAX 100

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

	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (field[i][j] == 0)
				continue;
			if (i + field[i][j] < N)
				dp[i + field[i][j]][j] += dp[i][j];
			if (j + field[i][j] < N)
				dp[i][j + field[i][j]] += dp[i][j];
		}
	}

	std::cout << dp[N - 1][N - 1];
	// std::cout << DFS(0, 0);

	return 0;
}

/*
long long dfs(int x, int y) {
	if (x >= N || y >= N) return 0;
	if (x == N - 1 && y == N - 1) return 1;

	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	int jump = field[x][y];
	if (jump == 0) return 0;

	dp[x][y] += dfs(x + jump, y); // 아래쪽
	dp[x][y] += dfs(x, y + jump); // 오른쪽

	return dp[x][y];
}
*/