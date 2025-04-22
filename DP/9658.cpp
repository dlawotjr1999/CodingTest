#include <iostream>
#include <vector>
#define MAX 1001

// 상근이와 창영이 두 명이 진행하는 돌 게임의 승자를 구하는 문제
// 게임은 턴제로 진행하며 돌은 1개, 3개, 4개를 가져갈 수 있고, 마지막 돌을 가져가면 패배한다
// 9657번과 풀이는 동일. 단 마지막 돌을 가져가야 패배이기 때문에 기저 조건을 다르게 설정

int dp[MAX];

int main() {
	int n;
	std::cin >> n;

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	dp[4] = 1;

	for (int i = 5; i <= n; i++) {
		if (dp[i - 4] == 0 || dp[i - 3] == 0 || dp[i - 1] == 0)
			dp[i] = 1;
		else
			dp[i] = 0;
	}

	if (dp[n])
		std::cout << "SK";
	else
		std::cout << "CY";

	return 0;
}