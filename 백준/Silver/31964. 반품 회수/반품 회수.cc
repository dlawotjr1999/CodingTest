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

	std::vector<int> info(max_dist + 1, 0);
	for (int i = 0; i < N; ++i) {
		info[homes[i]] = times[i];
	}

	for (int i = max_dist; i >= 1; --i) {
		if (info[i] > answer) {
			answer = info[i];
		}
		answer++;
	}

	std::cout << answer;
	return 0;
}