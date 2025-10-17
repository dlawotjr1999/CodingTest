#include <bits/stdc++.h>

int answer;

int main() {
	int H, W;
	std::cin >> H >> W;
	std::vector<int> vec(W);

	for (int i = 0; i < W; ++i) {
		std::cin >> vec[i];
	}

	for (int i = 1; i < W - 1; ++i) {
		int left_height = -1, right_height = -1;

		for (int j = 0; j < i; ++j) {
			left_height = std::max(left_height, vec[j]);
		}

		for (int j = i + 1; j < W; ++j) {
			right_height = std::max(right_height, vec[j]);
		}

		if (vec[i] < left_height && vec[i] < right_height) {
			answer += std::min(left_height, right_height) - vec[i];
		}
	}

	std::cout << answer;
	return 0;
}