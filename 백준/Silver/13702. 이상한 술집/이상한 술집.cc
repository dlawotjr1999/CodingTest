#include <bits/stdc++.h>

long long answer;

int main() {
	int N, K;
	std::cin >> N >> K;

	long long l = 1;

	std::vector<long long> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}
	int r = *max_element(vec.begin(), vec.end());

	while (l <= r) {
		long long mid = (l + r) / 2;
		long long cnt = 0;

		for(int i = 0; i < vec.size(); ++i) {
			cnt += vec[i] / mid;
		}
		
		if (cnt >= K) {
			answer = mid;
			l = mid + 1;
		}
		else if(cnt < K) {
			r = mid - 1;
		}
	}

	std::cout << answer;
	return 0;
}