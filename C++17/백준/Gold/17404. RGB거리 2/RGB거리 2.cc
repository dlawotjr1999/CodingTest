#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1e8;

int main() {
	int N;
	std::cin >> N;

	std::vector<std::vector<int>> vec(N + 1, std::vector<int>(3));
	for (int i = 1; i <= N; ++i) 
		std::cin >> vec[i][0] >> vec[i][1] >> vec[i][2];

	int answer = INF;

	for (int s = 0; s < 3; ++s) {
		std::vector<std::vector<int>> DP(N + 1, std::vector<int>(3, INF));

		DP[1][s] = vec[1][s];

		for (int i = 2; i <= N; ++i) {
			DP[i][0] = std::min(DP[i - 1][1], DP[i - 1][2]) + vec[i][0];
			DP[i][1] = std::min(DP[i - 1][0], DP[i - 1][2]) + vec[i][1];
			DP[i][2] = std::min(DP[i - 1][0], DP[i - 1][1]) + vec[i][2];
		}

		for (int e = 0; e < 3; ++e) {
			if (s != e)
				answer = std::min(answer, DP[N][e]);
		}
	}

	std::cout << answer;
	return 0;
}