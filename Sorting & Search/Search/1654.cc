#include <bits/stdc++.h>	

// K개의 랜선들을 N개의 같은 길이의 랜선으로 만들고자 함
// 즉 K개의 랜선들을 각각 여러 개로 잘라서 N개의 랜선을 만드는 것이며, 자른 후 남은 길이의 랜선은 버려야 함
// 이 때, 만들 수 있는 최대 랜선 길이를 구하는 문제

long long answer;

int main() {
	int K, N;
	std::cin >> K >> N;

	std::vector<long long> vec(K);
	for (int i = 0; i < K; ++i) {
		std::cin >> vec[i];
	}

	// 자를 수 있는 최소 길이인 1, 보유한 랜선의 최대 길이를 초기값으로 설정하여 이분탐색 진행 
	long long l = 1, r = *std::max_element(vec.cbegin(), vec.cend());

	while (l <= r) {
		long long mid = (l + r) / 2;
		long long cnt = 0;

		// 자르고 남은 길이의 랜선은 버려야 함
		for (long long len : vec) 
			cnt += len / mid;

		// N개보다 많이 만들어졌을 경우, 갯수를 줄이기 위해 자르고자 하는 길이를 늘려야 함
		if (cnt >= N) {
			answer = mid;
			l = mid + 1;
		}
		// N개보다 적게 만들어졌을 경우, 갯수를 늘리기 위해 자르고자 하는 길이를 줄여야 함
		else {
			r = mid - 1;
		}
	}

	std::cout << answer;
	return 0;
}