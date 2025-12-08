#include <iostream>
#include <vector>
#include <climits>

// 많은 종류의 산성 용액과 알칼리성 용액이 있을 때, 같은 양의 두 용액을 혼합한 특성값은 혼합에 사용된 각 용액의 특성값의 합으로 정의함
// 두 종류의 알칼리성 용액만으로나 혹은 두 종류의 산성 용액만으로 특성값이 0에 가장 가까운 혼합 용액을 만드는 경우도 존재할 수 있음
// 산성 용액과 알칼리성 용액의 특성값이 정렬된 순서로 주어졌을 때, 두 개의 서로 다른 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액을 구하는 문제

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<ll> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	// 특성값들의 인덱스를 활용하여 two-pointer 탐색 진행
	long long l = 0, r = N - 1;

	long long answer = LLONG_MAX;
	long long x = vec[l], y = vec[r];

	while (l < r) {
		// 특성값들이 정렬된 상대로 저장되어 있기 때문에 두 특성값의 합은 0에 가깝게 됨
		long long ph = vec[l] + vec[r];

		if (llabs(ph) < answer) {
			answer = llabs(ph);
			x = vec[l];
			y = vec[r];
		}

		// 특성값이 0보다 작은 경우 산성이 더 작은 용액 탐색
		if (ph < 0)
			l++;

		// 특성값이 0보다 큰 경우 알칼리성이 더 작은 용액 탐색
		else if (ph > 0)
			r--;
		// 특성값이 0인 경우 탐색 종료
		else
			break;
	}

	std::cout << x << ' ' << y;
	return 0;
}
