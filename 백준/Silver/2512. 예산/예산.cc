#include <bits/stdc++.h>

int answer;

int main() {
	int N;	std::cin >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}
	int l = 0, r = *std::max_element(vec.cbegin(), vec.cend());

	int M;	std::cin >> M;

	while (l <= r) {
		int mid = (l + r) / 2;
		long long sum = 0;

		for (int cost : vec) {
			if (cost > mid)
				sum += mid;
			else
				sum += cost;
		}

		if (sum <= M) {
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