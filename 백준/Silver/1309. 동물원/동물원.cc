#include <iostream>

int DP[100001][3];

int main() {
	int N;
	std::cin >> N;

	DP[1][0] = 1;
	DP[1][1] = 1;
	DP[1][2] = 1;

	for (int i = 2; i <= N; ++i) {
		DP[i][0] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % 9901;
		DP[i][1] = (DP[i - 1][0] + DP[i - 1][2]) % 9901;
		DP[i][2] = (DP[i - 1][0] + DP[i - 1][1]) % 9901;
	}

	int result = (DP[N][0] + DP[N][1] + DP[N][2]) % 9901;
	std::cout << result;

	return 0;
}