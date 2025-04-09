#include <iostream>
#include <vector>
#include <cmath>

// N개의 포도주 잔이 일렬로 놓여 있고, 각 잔에는 마실 수 있는 포도주의 양이 주어진다
// 각 잔은 한 번 마시면 모두 마셔야 하며, 마시거나 마시지 않을 수 있다
// 단, 연속으로 세 잔을 마실 수는 없음
// 이 때 마실 수 있는 포도주의 양의 최댓값을 구해야 함

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
	dp[2] = wine[1] + wine[2];	// 와인잔이 두 개일 때는 두 잔을 모두 마시는 것이 최댓값

	for (int i = 3; i <= n; i++) {
		/*
			i번째 잔까지 마실 수 있는 최댓값은 다음 3가지 중 최대값:

			1. i번째 잔을 마시고, i-1번째 잔은 마시지 않은 경우 : dp[i - 2] + wine[i]
			   (i-2번째까지의 최대치 + i번째 잔만 마신 경우)
			2. i번째 잔과 i-1번째 잔을 모두 마시는 경우 : dp[i - 3] + wine[i - 1] + wine[i]
			   (i-3번째까지의 최대치 + i-1 + i번 잔을 연속으로 마신 경우)
			3. i번째 잔을 **마시지 않는 경우 : dp[i - 1]

			단, 연속으로 3잔 마시면 안 되므로 위 세 경우만 고려
		*/
		dp[i] = std::max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]);
		dp[i] = std::max(dp[i - 1], dp[i]);
	}

	std::cout << dp[n];

	return 0;
}