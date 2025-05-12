#include <iostream>

// 0과 1로 구성된 이진수가 있을 때, 이 이진수에서 0을 10으로, 1을 01로 동시에 치환하면 길이가 두 배인 이진수를 얻을 수 있음
// 이러한 이진수들을 차례로 나열하면 하나의 이진수 수열이 되는데, 이 때 N번째 이진수에서 연속된 0들의 그룹이 몇 개나 있는지를 구하는 문제

// 알고리즘 자체는 맞았으나 C++ 내에 BigInteger 기능이 없으므로 Python으로 대체하여 제출 

constexpr int MAX = 1001;
long long DP[MAX];

int main() {
	int N;
	std::cin >> N;

	/*
	N = 1일 때 : 1 -> 0개
	N = 2일 때 : 01 -> 1개
	N = 3일 때 : 1001 -> 1개
	N = 4일 때 : 01101001 -> 3개
	N = 5일 때 : 1001011001101001 -> 5개
	
	여기서 N이 홀수일 때 S(n) = 2 * S(n - 1) - 1, N이 짝수일 때 S(n) = 2 * S(n - 1) + 1임을 알 수 있음
	*/

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