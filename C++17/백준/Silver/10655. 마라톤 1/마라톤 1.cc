#include <bits/stdc++.h>

int answer = INT_MAX;

int main() {
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> vec;
	std::vector<int> dist_vec;

	for (int i = 0; i < N; ++i) {
		int x, y;
		std::cin >> x >> y;
		vec.emplace_back(x, y);
	}

	int dist = 0;

	for (int i = 0; i < N - 1; ++i)
		dist += (abs(vec[i].first - vec[i + 1].first) + abs(vec[i].second - vec[i + 1].second));

	for (int i = 1; i < N - 1; ++i) {
		int removed1 = (abs(vec[i - 1].first - vec[i].first) + abs(vec[i - 1].second - vec[i].second));
		int removed2 = (abs(vec[i].first - vec[i + 1].first) + abs(vec[i].second - vec[i + 1].second));
		int direct = (abs(vec[i - 1].first - vec[i + 1].first) + abs(vec[i - 1].second - vec[i + 1].second));
		
		int temp = dist - (removed1 + removed2) + direct;
		dist_vec.push_back(temp);
	}

	answer = *std::min_element(dist_vec.begin(), dist_vec.end());
	std::cout << answer;
	return 0;
}
