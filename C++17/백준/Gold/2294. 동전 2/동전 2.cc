#include <iostream>
#include <vector>

const int INF = 1e8;

int DP[10001];

int main() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> vec(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> vec[i];
	}
	std::fill(DP, DP + 1 + k, INF);
	DP[0] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = vec[i]; j <= k; ++j) {
			DP[j] = std::min(DP[j], DP[j - vec[i]] + 1);
		}
	}

	std::cout << (DP[k] != INF ? DP[k] : -1);
	return 0;
}