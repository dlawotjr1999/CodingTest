#include <iostream>

// 알고리즘 자체는 맞았으나 C++ 내에 BigInteger 기능이 없으므로 Python으로 대체하여 제출 

constexpr int MAX = 1001;
long long DP[MAX];

int main() {
	int N;
	std::cin >> N;

	for (int i = 2; i <= N; i++) {
		if (i % 2 == 0) {
			DP[i] = 2 * DP[i - 1] + 1;
		}
		else {
			DP[i] = 2 * DP[i - 1] - 1;
		}
	}

	std::cout << DP[N];

	return 0;
}

// MAX = 1001
// dp = [0] * MAX
//
// n = int(input())
//
// for i in range(2, n + 1) :
//	 if i % 2 == 0 :
//		 dp[i] = 2 * dp[i - 1] + 1
//	 else :
//		 dp[i] = 2 * dp[i - 1] - 1
//
//		 print(dp[n])