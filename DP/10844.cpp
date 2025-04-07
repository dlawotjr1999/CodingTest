#include <iostream>
#include <vector>
#define M 1000000000

long long DP[101][10];

int main() {
	int N;
	std::cin >> N;

	for (int i = 1; i <= 9; i++) {
		DP[1][i] = 1;
	}
	DP[1][0] = 0;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0)
				DP[i][j] = DP[i - 1][j + 1] % M;
			else if (j == 9)
				DP[i][j] = DP[i - 1][j - 1] % M;
			else
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % M;
		}
	}
	
	long long cnt = 0;
	for (int i = 0; i <= 9; i++) {
		cnt += DP[N][i];
	}

	std::cout << cnt % M << std::endl;

	return 0;
}