#include <bits/stdc++.h>

long long answer;

int main() {
	int N;
	std::cin >> N;

	std::vector<long long> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	if (N == 1 || N == 2) {
		std::cout << 0;
		return 0;
	}

	while (true) {
		bool isChanged = false;

		for (int i = 1; i <= N - 2; ++i) {
			long long limit = (vec[i - 1] + vec[i + 1]) / 2;

			if (vec[i] > limit) {
				answer += (vec[i] - limit);
				vec[i] = limit;
				isChanged = true;
			}
		}

		if (!isChanged)
			break;
	}

	std::cout << answer;
	return 0;
}