#include <bits/stdc++.h>

long long answer;

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> costs(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> costs[i];
	}

	long long cur = 0;
	for (int i = 0; i < m; ++i) 
		cur += costs[i];
	answer = cur;

	for (int i = m; i < n; ++i) {
		cur += (costs[i] - costs[i - m]);
		answer = std::max(cur, answer);
	}

	std::cout << answer;
	return 0;
}