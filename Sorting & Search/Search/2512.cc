#include <bits/stdc++.h>

// 정해진 총액 이하에서 가능한 한 최대의 총 예산을 아래와 같이 배정하려고 함
// 모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정하되, 그렇지 않은 경우에는 특정 상한액을 계산하여 그 이상인 예산 요청에는 모두 상한액을 배정함
// 이 때, 가능한 예산들 중 최댓값을 구하는 문제

int answer;

int main() {
	int N;	std::cin >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}
	// 가능한 하한가를 0, 상한가를 가장 큰 예산으로 가정
	int l = 0, r = *std::max_element(vec.cbegin(), vec.cend());

	int M;	std::cin >> M;

	// 이분 탐색 진행 
	while (l <= r) {
		int mid = (l + r) / 2;
		long long sum = 0;

		// 현재 비용이 상한액을 넘을 경우 상한액만큼만 증가
		for (int cost : vec) {
			if (cost > mid)
				sum += mid;
			else
				sum += cost;
		}

		// 현재 상한가(mid)로 누적된 비용이 총액 이하인 경우 하한가 증가
		if (sum <= M) {
			answer = mid;
			l = mid + 1;
		}

		// 반대의 경우 상한가 감소
		else {
			r = mid - 1;
		}
	}

	std::cout << answer;
	return 0;
}