#include <bits/stdc++.h>

long long answer;

int main() {
	int N, C, W;
	std::cin >> N >> C >> W;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}
	int n = *std::max_element(vec.cbegin(), vec.cend());

	for (int l = 1; l <= n; ++l) {
		long long cur = 0;

		for (int i = 0; i < N; ++i) {
			int len = vec[i];
			int cnt = vec[i] / l;

			if (cnt == 0)
				continue;

			int cut = 0;
			if (len % l == 0)
				cut = cnt - 1;
			else
				cut = cnt;

			long long profit = 1LL * cnt * l * W;
			long long loss = 1LL * cut * C;
			long long total = profit - loss;

			if (total > 0) cur += total;
		}
		answer = std::max(answer, cur);
	}

	std::cout << answer;
	return 0;
}