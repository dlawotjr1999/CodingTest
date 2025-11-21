#include <iostream>
#include <vector>

int main() {
	int N, M;
	std::cin >> N >> M;

	std::vector<std::pair<int, int>> info(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> info[i].first;
	}

	int sum = 0;
	for (int i = 0; i < N; ++i) {
		std::cin >> info[i].second;
		sum += info[i].second;
	}

	std::vector<int> DP(sum + 1, 0);
	for (int i = 0; i < N; ++i) {
		int mem = info[i].first;
		int cost = info[i].second;

		for (int j = sum; j >= cost; --j) {
			DP[j] = std::max(DP[j], DP[j - cost] + mem);
		}
	}

	int answer = 1e9;
	for (int i = 0; i <= sum; ++i) {
		if (DP[i] >= M) {
			answer = std::min(answer, i);
		}
	}

	std::cout << answer;
	return 0;
}