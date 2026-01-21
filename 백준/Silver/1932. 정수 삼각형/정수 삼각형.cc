#include <bits/stdc++.h>

int DP[501][501];

int main() {
	int n; std::cin >> n;

	std::vector<std::vector<int>> triangle(n + 1);
	for (int i = 1; i <= n; ++i) {
		triangle[i].resize(i + 1);

		for (int j = 1; j <= i; ++j) {
			std::cin >> triangle[i][j];
		}
	}

	DP[1][1] = triangle[1][1];
	for (int i = 1; i <= n; ++i) {
		DP[i][1] = DP[i - 1][1] + triangle[i][1];
		DP[i][i] = DP[i - 1][i - 1] + triangle[i][i];

		for (int j = 2; j < i; ++j) {
			DP[i][j] = std::max(DP[i - 1][j - 1], DP[i - 1][j]) + triangle[i][j];
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; ++i)
		answer = std::max(answer, DP[n][i]);

	std::cout << answer;
	return 0;
}