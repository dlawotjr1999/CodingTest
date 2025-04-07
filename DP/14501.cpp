#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;

	std::vector<int> T(N + 1, 0);
	std::vector<int> P(N + 1, 0);
	std::vector<int> DP(N + 2, 0);

	for (int i = 1; i <= N; i++) {
		std::cin >> T[i] >> P[i];
	}

	for (int i = N; i > 0; i--) {
		if (i + T[i] > N + 1) {
			DP[i] = DP[i + 1];
		}
		else {
			DP[i] = std::max(DP[i + 1], DP[i + T[i]] + P[i]);
		}
	}

	std::cout << *std::max_element(DP.begin(), DP.end());
	
	return 0;
}