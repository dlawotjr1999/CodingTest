#include <iostream>
#include <cmath>

// 주어진 규칙대로 계단을 올랐을 때 밟은 계단에 적힌 점수들의 합을 구해야 함
// 규칙들은 아래와 같다
// 1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다.즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
// 2. 연속된 세 개의 계단을 모두 밟아서는 안 된다.단, 시작점은 계단에 포함되지 않는다.
// 3. 마지막 도착 계단은 반드시 밟아야 한다.
// 이 때, 그 합의 최댓값을 구하는 문제

int stair[301];
int dp[301];

int main() {
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		std::cin >> stair[i];
	}

	dp[0] = 0;
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];

	/*
	계단을 오를 수 있는 경우의 수는 아래와 같다.
		1. OXO
		2. XOO
		3. OOX
	하지만 3번의 경우, 최종적으로 봤을 때 마지막 계단을 밟지 않게 될 수 있으므로 고려하지 않는다
	그러므로 점화식은 dp[n] = dp[n - 2] + stair[n] (1번), 혹은 dp[n] = dp[n- 3] + stair[n - 1] + stair[n] (3번)
	이 두 개의 경우 중 최댓값을 가지는 경우가 바로 구하고자 하는 값이다
	*/

	for (int i = 3; i <= N; i++) {
		dp[i] = std::max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}

	std::cout << dp[N];

	return 0;
}