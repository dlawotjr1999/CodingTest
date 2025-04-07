#include <iostream>
#include <vector>
#include <cmath>

int wine[10001];
int dp[10001];

int main() {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> wine[i];
	}

	dp[0] = wine[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = std::max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]);
		dp[i] = std::max(dp[i - 1], dp[i]);
	}

	std::cout << dp[n];

	return 0;
}