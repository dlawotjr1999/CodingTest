#include <bits/stdc++.h>

int main() {
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> DP(N + 1, { 0,0 });
	DP[1] = { 0,-1 };

	for (int i = 2; i <= N; ++i) {
		DP[i].first = DP[i - 1].first + 1;
		DP[i].second = i - 1;

		if (i % 3 == 0) {
			int temp = DP[i / 3].first + 1;
			if (temp < DP[i].first) {
				DP[i].first = temp;
				DP[i].second = i / 3;
			}
		}
		if (i % 2 == 0) {
			int temp = DP[i / 2].first + 1;
			if (temp < DP[i].first) {
				DP[i].first = temp;
				DP[i].second = i / 2;
			}
		}
	}

	std::cout << DP[N].first << '\n';

	std::cout << N << ' ';
	while (DP[N].second != -1) {
		std::cout << DP[N].second << ' ';
		N = DP[N].second;
	}

	return 0;
}