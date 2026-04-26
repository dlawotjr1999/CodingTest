#include <bits/stdc++.h>

std::vector<std::vector<int>> field;
std::vector<std::vector<int>> sums;

int answer = -1e8;

int main() {
	int N;	std::cin >> N;
	field.resize(N + 1, std::vector<int>(N + 1, 0));
	sums.resize(N + 1, std::vector<int>(N + 1, 0));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			std::cin >> field[i][j];
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + field[i][j];
		}
	}

	for (int s = 1; s <= N; ++s) {
		for (int i = 1; i + s - 1 <= N; ++i) {
			for (int j = 1; j + s - 1 <= N; ++j) {
				int x2 = i + s - 1;
				int y2 = j + s - 1;

				int sum = sums[x2][y2] - sums[i - 1][y2] - sums[x2][j - 1] + sums[i - 1][j - 1];
				answer = std::max(answer, sum);
			}
		}
	}


	std::cout << answer;
	return 0;
}