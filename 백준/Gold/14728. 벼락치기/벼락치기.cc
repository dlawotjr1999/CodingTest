#include <iostream>
#include <vector>

int main() {
	int N, T;
	std::cin >> N >> T;

	std::vector<std::pair<int, int>> vec(N + 1);
	for (int i = 1; i <= N; ++i) {
		std::cin >> vec[i].first >> vec[i].second;
	}

	std::vector<int> DP(T + 1, 0);
	for(int i = 1; i <= N; ++i) {
		int K = vec[i].first;
		int S = vec[i].second;

		for (int j = T; j >= K; --j) {
			DP[j] = std::max(DP[j], DP[j - K] + S);
		}
	}

	std::cout << DP[T];
	return 0;
}