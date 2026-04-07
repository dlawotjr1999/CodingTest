#include <bits/stdc++.h>

int N, S, M;
int answer = -1;

std::vector<int> vec;

int main() {
	std::cin >> N >> S >> M;

	vec.resize(N + 1, 0);
	for (int i = 1; i <= N; ++i) {
		std::cin >> vec[i];
	}

	std::vector<std::vector<bool>> DP(N + 1, std::vector<bool>(M + 1, false));
	DP[0][S] = true;

	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= M; ++j) {
			if (!DP[i - 1][j])
				continue;

			if (j - vec[i] >= 0)
				DP[i][j - vec[i]] = true;
			if (j + vec[i] <= M)
				DP[i][j + vec[i]] = true;
		}
	}

	for (int j = M; j >= 0; --j) {
		if (DP[N][j]) {
			std::cout << j;
			return 0;
		}
	}

	std::cout << -1;
	return 0;
}