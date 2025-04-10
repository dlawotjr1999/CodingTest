#include <iostream>
#include <cmath>

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

	for (int i = 3; i <= N; i++) {
		dp[i] = std::max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}

	std::cout << dp[N];

	return 0;
}