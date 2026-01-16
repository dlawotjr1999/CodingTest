#include <bits/stdc++.h>	

long long answer;

int main() {
	int K, N;
	std::cin >> K >> N;

	std::vector<long long> vec(K);
	for (int i = 0; i < K; ++i) {
		std::cin >> vec[i];
	}

	long long l = 1, r = *std::max_element(vec.cbegin(), vec.cend());

	while (l <= r) {
		long long mid = (l + r) / 2;
		long long cnt = 0;

		for (long long len : vec) 
			cnt += len / mid;

		if (cnt >= N) {
			answer = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	std::cout << answer;
	return 0;
}