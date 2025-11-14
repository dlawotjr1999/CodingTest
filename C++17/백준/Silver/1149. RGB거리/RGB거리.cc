#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 1001;
int DP[3][1001];

int answer;

struct color {
	int r, g, b;
};

int main() {
	int N;	std::cin >> N;
	std::vector<color> vec(N + 1);

	for (int i = 1; i <= N; ++i) {
		std::cin >> vec[i].r >> vec[i].g >> vec[i].b;
	}

	DP[0][1] = vec[1].r; DP[1][1] = vec[1].g; DP[2][1] = vec[1].b;
	for (int i = 2; i <= N; ++i) {
		DP[0][i] = std::min(DP[1][i - 1], DP[2][i - 1]) + vec[i].r;
		DP[1][i] = std::min(DP[0][i - 1], DP[2][i - 1]) + vec[i].g;
		DP[2][i] = std::min(DP[0][i - 1], DP[1][i - 1]) + vec[i].b;
	}

	answer = std::min({ DP[0][N], DP[1][N], DP[2][N] });
	std::cout << answer;
	return 0;
}