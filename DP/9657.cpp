#include <iostream>
#include <vector>
#define MAX 1001

// 상근이와 창영이 두 명이 진행하는 돌 게임의 승자를 구하는 문제
// 게임은 턴제로 진행하며 돌은 1개, 3개, 4개를 가져갈 수 있고, 마지막 돌을 가져가면 승리한다

// 0 : 창영이가 이기는 경우
// 1 : 상근이가 이기는 경우
int dp[MAX];

int main() {
	int n;
	std::cin >> n;

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	dp[4] = 1;

	// i개의 돌이 남아있을 때의 승패 판정
	// 돌을 1개, 3개 , 4개 가져갈 수 있으므로 i-1, i-3, i-4번째에서 상태에서 창영이가 이긴다면(0) i번째에서는 상근이가 무조건 이기게 된다
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