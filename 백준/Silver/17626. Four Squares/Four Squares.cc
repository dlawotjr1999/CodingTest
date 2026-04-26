#include <bits/stdc++.h>

int main() {
	int n;	std::cin >> n;

	std::vector<int> DP(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		DP[i] = i;
	}

	for (int i = 4; i <= n; ++i) {
		for (int j = 1; j*j <= i; ++j) {
			DP[i] = std::min(DP[i], DP[i - j * j] + 1);
		}
	}

	std::cout << DP[n];
	return 0;
}