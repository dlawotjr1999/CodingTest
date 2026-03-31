#include <bits/stdc++.h>

long long answer;

int main() {
	int S, C;
	long long total = 0;

	std::cin >> S >> C;

	int l = 1, r = -1;

	std::vector<int> vec(S);
	for (int i = 0; i < S; ++i) {
		std::cin >> vec[i];
		total += 1LL * vec[i];
		r = std::max(r, vec[i]);
	}

	long long cur = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		long long cnt = 0;

		for (int len : vec) {
			cnt += (1LL * (len / mid));
		}

		if (cnt >= C) {
			cur = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	answer = total - cur * C;
	std::cout << answer;
	return 0;
}