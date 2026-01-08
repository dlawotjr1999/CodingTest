#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
	int N, M, K;
	std::cin >> N >> M >> K;

	int cur_prefer = 0;

	std::vector<std::pair<int, int>> vec;
	for (int i = 0; i < K; ++i) {
		int v, c;
		std::cin >> v >> c;
		vec.emplace_back(v, c);
	}

	std::sort(vec.begin(), vec.end(), [](const auto& l, const auto& r) {
		return l.second < r.second;
	});

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	long long sum = 0;

	for (int i = 0; i < K; ++i) {
		pq.push(vec[i].first);
		sum += vec[i].first;

		if (pq.size() > N) {
			sum -= pq.top();
			pq.pop();
		}

		if (pq.size() == N && sum >= M) {
			std::cout << vec[i].second;
			return 0;
		}
	}
	
	std::cout << -1;
	return 0;
}