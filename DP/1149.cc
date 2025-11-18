#include <iostream>
#include <vector>
#include <algorithm>

// RGB 거리에 N개의 집이 있을 때 집들을 빨강, 파랑, 초록 중 한 가지의 색으로 색칠을 하되 아래 규칙을 따라야 함
// - 1번 집의 색은 2번 집의 색과 같지 않아야 함
// - N번 집의 색은 N - 1번 집의 색과 같지 않아야 함
// - i(2 ≤ i ≤ N - 1)번 집의 색은 i - 1번, i + 1번 집의 색과 같지 않아야 함
// 이 때, 모든 집을 칠하는 비용의 최솟값을 구하는 문제

const int MAX = 1001;

// 3가지의 색으로 N개의 집을 규칙에 맞게 칠하는 경우의 수 저장 
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
	
	// 가장 먼저 칠해지는 집은 어느 색이라도 상관없음
	DP[0][1] = vec[1].r; DP[1][1] = vec[1].g; DP[2][1] = vec[1].b;

	// 현재 집을 빨간색으로 칠하는 경우 : 이전 집을 초록색이나 파란색으로 칠하는 경우 중 비용이 더 적은 경우를 선택한 후 색칠
	// 현재 집을 초록색으로 칠하는 경우 : 이전 집을 빨간색이나 파란색으로 칠하는 경우 중 비용이 더 적은 경우를 선택한 후 색칠
	// 현재 집을 파란색으로 칠하는 경우 : 이전 집을 빨간색이나 초록색으로 칠하는 경우 중 비용이 더 적은 경우를 선택한 후 색칠
	for (int i = 2; i <= N; ++i) {
		DP[0][i] = std::min(DP[1][i - 1], DP[2][i - 1]) + vec[i].r;
		DP[1][i] = std::min(DP[0][i - 1], DP[2][i - 1]) + vec[i].g;
		DP[2][i] = std::min(DP[0][i - 1], DP[1][i - 1]) + vec[i].b;
	}

	answer = std::min({ DP[0][N], DP[1][N], DP[2][N] });
	std::cout << answer;
	return 0;
}