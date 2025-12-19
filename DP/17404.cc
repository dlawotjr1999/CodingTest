#include <iostream>
#include <vector>
#include <algorithm>

// RGB 거리에 N개의 집이 있을 때 집들을 빨강, 파랑, 초록 중 한 가지의 색으로 색칠을 하되 아래 규칙을 따라야 함
// 1. 1번 집의 색은 2번, N번 집의 색과 같지 않아야 함
// 2. N번 집의 색은 N - 1번, 1번 집의 색과 같지 않아야 함
// 3. i(2 ≤ i ≤ N - 1)번 집의 색은 i - 1, i + 1번 집의 색과 같지 않아야 함
// 이 때, 모든 집을 칠하는 비용의 최솟값을 구하는 문제


const int INF = 1e8;

int main() {
	int N;
	std::cin >> N;

	std::vector<std::vector<int>> vec(N + 1, std::vector<int>(3));
	for (int i = 1; i <= N; ++i) 
		std::cin >> vec[i][0] >> vec[i][1] >> vec[i][2];

	int answer = INF;

	// 맨 처음에 있는 집의 색을 고정한 채로 DP 연산 진행
	// 비용을 INF로 초기화 하되, 첫 집을 특정 색으로 색칠하는 데 드는 비용만으로 갱신
	for (int s = 0; s < 3; ++s) {
		std::vector<std::vector<int>> DP(N + 1, std::vector<int>(3, INF));

		DP[1][s] = vec[1][s];

		// 이전 집과 다르게 색칠하는 경우들 중, 더 적은 비용으로 색칠할 수 있는 경우를 선택
		for (int i = 2; i <= N; ++i) {
			DP[i][0] = std::min(DP[i - 1][1], DP[i - 1][2]) + vec[i][0];
			DP[i][1] = std::min(DP[i - 1][0], DP[i - 1][2]) + vec[i][1];
			DP[i][2] = std::min(DP[i - 1][0], DP[i - 1][1]) + vec[i][2];
		}

		// DP를 만족하면서, 맨 앞의 집과 맨 뒤의 집 색이 다른 경우 정답
		for (int e = 0; e < 3; ++e) {
			if (s != e)
				answer = std::min(answer, DP[N][e]);
		}
	}

	std::cout << answer;
	return 0;
}