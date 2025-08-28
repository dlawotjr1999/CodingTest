#include <iostream>

long long DP[1001][10];

int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < 10; ++i) {
		DP[1][i] = 1;
	}

	for (int i = 2; i <= 1000; ++i) {
		long long temp = 0;
		
		for (int j = 0; j < 10; ++j) {
			temp = (temp + DP[i - 1][j]) % 10007;
			DP[i][j] = temp;
		}
	}

	long long answer = 0;
	for (int i = 0; i < 10; ++i) {
		long long num = DP[N][i] % 10007;
		answer += num;
	}

	std::cout << answer % 10007;
}