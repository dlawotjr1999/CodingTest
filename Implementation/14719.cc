#include <bits/stdc++.h>

// 아래 문제를 구현
// https://www.acmicpc.net/problem/14719

int answer;

// i번 칸을 확인한다고 할 때, i번 칸에 담길 수 있는 빗물의 양은 아래와 같음
// min((i번째 이전 벽들 중 가장 높은 벽의 높이), ((i번째 이후 벽들 중 가장 높은 벽의 높이)) - (i번째 벽의 높이)

int main() {
	int H, W;
	std::cin >> H >> W;
	std::vector<int> vec(W);

	for (int i = 0; i < W; ++i) {
		std::cin >> vec[i];
	}

	// 가장 끝부분들은 빗물이 담길 수 없으므로 (0, W-1) 구간에서 탐색 진행
	for (int i = 1; i < W - 1; ++i) {
		int left_height = -1, right_height = -1;

		// i번째 이전 벽들 중 가장 높은 벽의 높이 계산
		for (int j = 0; j < i; ++j) {
			left_height = std::max(left_height, vec[j]);
		}

		// i번째 이후 벽들 중 가장 높은 벽의 높이 계산
		for (int j = i + 1; j < W; ++j) {
			right_height = std::max(right_height, vec[j]);
		}

		// 담길 수 있는 빗물의 양들을 누적하여 계산
		if (vec[i] < left_height && vec[i] < right_height) {
			answer += std::min(left_height, right_height) - vec[i];
		}
	}

	std::cout << answer;
	return 0;
}