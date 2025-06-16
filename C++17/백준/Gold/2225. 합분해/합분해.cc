#include <iostream>

int N, K;
long long DP[201][201];

int main() {
	std::cin >> N >> K;

	for (int i = 0; i <= N; ++i) {
		DP[1][i] = 1;
	}
	for (int i = 1; i <= K; ++i) {
		DP[i][0] = 1;
	}

	for (int i = 2; i <= K; ++i) {
		for (int j = 1; j <= N; ++j) {
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
			DP[i][j] %= 1000000000;
		}
	}
	std::cout << DP[K][N];

	return 0;
}