#include <bits/stdc++.h>

const int MAX = 1000;
const int MOD = 1000000009;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// n을 m개의 숫자로 만들기
	std::vector<std::vector<int>> DP(MAX + 1, std::vector<int>(MAX + 1, 0));

	DP[1][1] = 1;

	DP[2][1] = 1;
	DP[2][2] = 1;

	DP[3][1] = 1;
	DP[3][2] = 2;
	DP[3][3] = 1;

	for (int i = 4; i <= MAX; ++i) {
		for (int j = 1; j <= MAX; ++j) {
			DP[i][j] = (1LL * DP[i - 1][j - 1] + DP[i - 2][j - 1] + DP[i - 3][j - 1]) % MOD;
		}
	}

	int T; std::cin >> T;
	
	while (T--) {
		int n, m;
		std::cin >> n >> m;
		std::cout << DP[n][m] << '\n';
	}

	return 0;
}