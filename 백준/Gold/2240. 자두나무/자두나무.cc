#include <bits/stdc++.h>

int answer;
int DP[1001][31][2];

int main() {
	int T, W;
	std::cin >> T >> W;

	std::vector<int> vec(T + 1);
	for (int i = 1; i <= T; ++i) {
		std::cin >> vec[i];
	}

	for (int i = 1; i <= T; ++i) {
		for (int j = 0; j <= W; ++j) {
			if (j == 0) {
				DP[i][0][0] = DP[i - 1][0][0] + (vec[i] == 1 ? 1 : 0);
				continue;
			}
			
			if (vec[i] == 1) {
				DP[i][j][0] = std::max(DP[i - 1][j][0], DP[i - 1][j - 1][1]) + 1;
				DP[i][j][1] = std::max(DP[i - 1][j - 1][0], DP[i - 1][j][1]);
			}
			else {
				DP[i][j][0] = std::max(DP[i - 1][j][0], DP[i - 1][j - 1][1]);
				DP[i][j][1] = std::max(DP[i - 1][j - 1][0], DP[i - 1][j][1]) + 1;
			}
		}
	}

	for (int w = 0; w <= W; ++w) {
		int temp = std::max(DP[T][w][0], DP[T][w][1]);
		answer = std::max(temp, answer);
	}

	std::cout << answer;
	return 0;
}