#include <iostream>
#include <vector>

using namespace std;

// 0 - 1 배낭문제
// 해설 : https://nanyoungkim.tistory.com/182

int main() {
	int N, K;
	std::vector<std::pair<int, int>> p;

	std::cin >> N >> K;
	std::vector<vector<int>> dp(N + 1, std::vector<int>(K + 1));

	p.emplace_back(0, 0);
	for (int i = 1; i < N + 1; i++) {
		int w, v;
		std::cin >> w >> v;

		p.emplace_back(w, v);
	}

	for (int i = 1; i < dp.size(); i++) {
		for (int j = 1; j < dp[i].size(); j++) {
			if (p[i].first > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - p[i].first] + p[i].second);
		}
	}

	std::cout << dp[N][K] << std::endl;

	return 0;
}