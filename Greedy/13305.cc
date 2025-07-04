#include <iostream>
#include <vector>

// N개의 도시가 있을 때, 맨 왼쪽 지점에서 오른쪽 지점으로 이동하고자 함
// 각 도시의 주유소마다 L당 주유비가 주어지며며, 각 도시 사이의 거리 (N-1)이 주어짐
// 이 때 제일 왼쪽 도시에서 제일 오른쪽 도시로 이동하는 최소 비용을 구하는 문제

std::vector<long long> dists;
std::vector<long long> costs;

int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N - 1; ++i) {
		long long dist; std::cin >> dist;
		dists.emplace_back(dist);
	}

	for (int i = 0; i < N; ++i) {
		long long node; std::cin >> node;
		costs.emplace_back(node);
	}

	long long answer = 0;
	long long cur = costs[0];
	
	for (int i = 0; i < N - 1; ++i) {
		// (현재 지점의 주유비 * 다음 지점까지의 거리)로 다음 지점으로 이동 
		answer += cur * dists[i];

		// 다음 지점의 주유비가 더 낮을 경우 그 비용으로 cur 갱신 
		if (costs[i + 1] < cur) {
			cur = costs[i + 1];
		}
	}

	std::cout << answer;
	return 0;
}