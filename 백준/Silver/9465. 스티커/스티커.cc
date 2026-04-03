#include <bits/stdc++.h>

int main() {
	int T;	std::cin >> T;

	while (T--) {
		int n;	std::cin >> n;

		std::vector<std::vector<int>> sticker(2, std::vector<int>(n, 0));
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < n; ++j) {
				std::cin >> sticker[i][j];
			}
		}

		std::vector<std::vector<int>> DP(3, std::vector<int>(n, 0));
		DP[0][0] = 0; DP[1][0] = sticker[0][0]; DP[2][0] = sticker[1][0];
		for (int i = 1; i < n; ++i) {
			DP[0][i] = std::max(DP[1][i - 1], DP[2][i - 1]);
			DP[1][i] = std::max(DP[0][i - 1], DP[2][i - 1]) + sticker[0][i];
			DP[2][i] = std::max(DP[0][i - 1], DP[1][i - 1]) + sticker[1][i];
		}

		int answer = std::max({ DP[0][n - 1], DP[1][n - 1], DP[2][n - 1] });
		std::cout << answer << '\n';
	}
}
