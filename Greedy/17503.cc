#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 맥주 축제에 참가해 총 N일 동안 맥주 N병을 마시려 하며, 도수가 높은 맥주를 마시면 기절하는 맥주병이 있음
// 이를 해결하기 위해 간을 가능한 한 조금 강화하고자 함
// 맥주에 각각 '선호도'와 '도수 레벨'을 매겼으며, 마시는 맥주의 도수 레벨이 간 레벨보다 높으면 맥주병이 발병하게 됨
// 맥주병에 걸리지 않으면서도 자신이 좋아하는 맥주를 많이 마시기 위해, 마시는 맥주 N개의 선호도 합이 M이상이 되게하려 함
// 이 때, 주어진 선호도의 합 M을 채우면서 N개의 맥주를 모두 마실 수 있는 간 레벨의 최솟값을 구하는 문제

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

	// 도수 레벨을 기준으로 오름차순 정렬
	std::sort(vec.begin(), vec.end(), [](const auto& l, const auto& r) {
		return l.second < r.second;
	});

	// 선호도를 저장하는 최소 힙 선언
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	long long sum = 0;

	for (int i = 0; i < K; ++i) {
		pq.push(vec[i].first);
		sum += vec[i].first;

		// 축제 기간동안 마실 수 있는 맥주, 즉 K개 중 N개의 맥주로 선호도를 만족할 수 없는 경우
		// 즉 N의 기간을 넘어서 선호도의 합 M을 채워야 하는 경우
		// 가장 선호도가 낮은 맥주를 제외함
		if (pq.size() > N) {
			sum -= pq.top();
			pq.pop();
		}

		// N의 기간동안 M 이상의 선호도를 채울 수 있는 경우
		// 현재 탐색 중인 맥주의 도수 레벨이 바로 구하고자 하는 최소 도수 레벨
		// 도수 레벨이 이미 오름차순으로 정렬되어 있기 때문임
		if (pq.size() == N && sum >= M) {
			std::cout << vec[i].second;
			return 0;
		}
	}
	
	std::cout << -1;
	return 0;
}