#include <bits/stdc++.h>

int field[301][301];
int DP[301][301];

int N, M;
int answer;

int main() {
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		int x, y; std::cin >> x >> y;
		field[y][x] = 1;
	}

	for (int i = 0; i <= 300; ++i) {
		for (int j = 0; j <= 300; ++j) {
			if (i > 0) 
				DP[i][j] = std::max(DP[i][j], DP[i - 1][j]);
			if (j > 0) 
				DP[i][j] = std::max(DP[i][j], DP[i][j - 1]);

			if (field[i][j] > 0)
				DP[i][j] += std::max(0, M - i - j);

			answer = std::max(answer, DP[i][j]);
		}
	}

	std::cout << answer;
	return 0;
}