#include <iostream>
#include <vector>
#include <algorithm>

int answer;

int main() {
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> vec;
	for (int i = 0; i < N; ++i) {
		int l, h;
		std::cin >> l >> h;
		vec.emplace_back(l, h);
	}

	std::sort(vec.begin(), vec.end());

	int max_idx = 0, max_h = 0;
	for (int i = 0; i < N; ++i) {
		if (max_h < vec[i].second) {
			max_idx = i;
			max_h = vec[i].second;
		}
	}

	answer = max_h;
	int l = vec[0].first; int h = vec[0].second;
	for (int i = 1; i < max_idx + 1; ++i) {
		if (h <= vec[i].second) {
			answer += (vec[i].first - l) * h;
			l = vec[i].first;
			h = vec[i].second;
		}
	}

	l = vec[N - 1].first + 1;
	h = vec[N - 1].second;
	for (int i = N - 1; i > max_idx - 1; --i) {
		if (vec[i].second >= h) {
			answer += (l - vec[i].first - 1) * h;
			l = vec[i].first + 1;
			h = vec[i].second;
		}
	}

	std::cout << answer;
	return 0;
}