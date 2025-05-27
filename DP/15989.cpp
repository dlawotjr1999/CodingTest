#include <iostream>

int DP[10001][3];

int main() {
	int T;
	std::cin >> T;

	DP[1][0] = 1;
	DP[2][0] = 1;
	DP[2][1] = 1;
	DP[3][0] = 1;
	DP[3][1] = 1;
	DP[3][2] = 1;

	for (int i = 4; i < 10001; i++) {
		DP[i][0] = 1;
		DP[i][1] = DP[i - 2][0] + DP[i - 2][1];
		DP[i][2] = DP[i - 3][0] + DP[i - 3][1] + DP[i - 3][2];
	}

	while (T--) {
		int n;
		std::cin >> n;
		std::cout << DP[n][0] + DP[n][1] + DP[n][2] << '\n';
	}

	return 0;
}