#include <bits/stdc++.h>

long long answer;

int main() {
	int N; std::cin >> N;
	
	std::vector<int> homes(N);
	std::vector<int> times(N);

	for (int i = 0; i < N; ++i) { std::cin >> homes[i]; }
	for (int i = 0; i < N; ++i) { std::cin >> times[i]; }

	int max_dist = homes[N - 1];
	answer = homes[N - 1];

	std::vector<std::pair<int, int>> info(N);
	for (int i = 0; i < N; ++i) { info[i] = { homes[i], times[i] }; }

	answer = std::max(answer, (long long)info.back().second);
	for (int i = N - 2; i >= 0; --i) {
		answer += (info[i + 1].first - info[i].first);
		answer = std::max(answer, (long long)info[i].second);
	}
	answer += info[0].first;

	std::cout << answer;
	return 0;
}