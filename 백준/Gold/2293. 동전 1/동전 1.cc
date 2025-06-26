#include <iostream>

int n, k;

int coin[101];
int DP[10001];

int main() {
	std::cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		std::cin >> coin[i];
	}

	DP[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = coin[i]; j <= k; ++j) {
			DP[j] = DP[j] + DP[j - coin[i]];
		}
	}
	std::cout << DP[k];

	return 0;
}