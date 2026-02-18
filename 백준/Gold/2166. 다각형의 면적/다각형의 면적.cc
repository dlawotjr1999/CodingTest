#include <bits/stdc++.h>

double answer;

int main() {
	int N; std::cin >> N;

	std::vector<std::pair<int, int>> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i].first >> vec[i].second;
	}

	long long sum1 = 0;
	long long sum2 = 0;
	for (int i = 0; i < N - 1; ++i) {
		sum1 += (1LL * vec[i].first * vec[i + 1].second);
		sum2 += (1LL * vec[i].second * vec[i + 1].first);
	}
	sum1 += (1LL * vec[N - 1].first * vec[0].second);
	sum2 += (1LL * vec[N - 1].second * vec[0].first);

	answer = std::llabs(sum1 - sum2) / 2.0;

	std::cout << std::fixed << std::setprecision(1) << answer;
	return 0;
}