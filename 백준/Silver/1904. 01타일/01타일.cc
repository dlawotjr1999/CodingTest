#include <iostream>

int DP[1000001];

int main() {
	int N;
	std::cin >> N;

	DP[1] = 1; DP[2] = 2;
	for (int i = 3; i <= N; ++i) {
		DP[i] = (DP[i - 2] + DP[i - 1]) % 15746;
	}

	std::cout << DP[N];
	return 0;
}