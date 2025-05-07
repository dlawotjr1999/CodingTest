#include <iostream>

// �˰��� ��ü�� �¾����� C++ ���� BigInteger ����� �����Ƿ� Python���� ��ü�Ͽ� ���� 

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