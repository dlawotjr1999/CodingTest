#include <bits/stdc++.h>

int answer;

int main() {
	int N;	std::cin >> N;

	std::vector<int> hp(N + 1);
	for (int i = 1; i <= N; ++i) {
		std::cin >> hp[i];
	}

	std::vector<int> joy(N + 1);
	for (int i = 1; i <= N; ++i) {
		std::cin >> joy[i];
	}

	std::vector<int> DP(100);
	for (int i = 1; i <= N; ++i) {
		int cur_hp = hp[i];
		int cur_joy = joy[i];

		for (int j = 99; j >= cur_hp; --j) {
			DP[j] = std::max(DP[j], DP[j - cur_hp] + cur_joy);
		}
	}

	for (int i = 1; i <= 99; ++i) 
		answer = std::max(answer, DP[i]);

	std::cout << answer;
	return 0;
}