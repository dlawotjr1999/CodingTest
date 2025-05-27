#include <iostream>
#include <vector>
#include <algorithm>

int N, L;
std::vector<std::pair<int, int>> puddles;

int main() {
	std::cin >> N >> L;
	puddles.resize(N);

	for (int i = 0; i < N; i++) {
		std::cin >> puddles[i].first >> puddles[i].second;
	}

	std::sort(puddles.begin(), puddles.end());

	int current = 0;
	int count = 0;

	for (auto [start, end] : puddles) {
		if (current < start)
			current = start;

		while (current < end) {
			current += L;
			count++;
		}
	}

	std::cout << count;

	return 0;
}