#include <bits/stdc++.h>

int answer;

int main() {
	int N; std::cin >> N;

	std::string base;
	std::cin >> base;

	std::vector<int> base_cnt(26, 0);
	for (char c : base) {
		base_cnt[c - 'A']++;
	}

	for (int i = 1; i < N; ++i) {
		std::string comp;
		std::cin >> comp;

		int diff = 0;

		std::vector<int> comp_cnt(26, 0);
		for (char c : comp) {
			comp_cnt[c - 'A']++;
		}

		for (int i = 0; i < 26; ++i) {
			diff += std::abs(comp_cnt[i] - base_cnt[i]);
		}

		if (base.length() != comp.length() && diff <= 1)
			answer++;
		else if (base.length() == comp.length() && diff <= 2)
			answer++;
	}

	std::cout << answer;
	return 0;
}