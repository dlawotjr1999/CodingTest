#include <bits/stdc++.h>

int N;
std::vector<std::pair<int, int>> taste;

int answer = 1e9;

void DFS(int cnt, int cur, int idx, int sweet, int bitter) {
	if (cnt == cur) {
		int diff = std::abs(sweet - bitter);
		answer = std::min(answer, diff);

		return;
	}

	for (int i = idx; i < N; ++i) {
		int next_sweet = sweet * taste[i].first;
		int next_bitter = bitter + taste[i].second;

		DFS(cnt, cur + 1, i + 1, next_sweet, next_bitter);
	}
}

int main() {
	std::cin >> N;

	taste.resize(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> taste[i].first >> taste[i].second;
	}

	for (int cnt = 1; cnt <= N; ++cnt) {
		DFS(cnt, 0, 0, 1, 0);
	}

	std::cout << answer;
	return 0;
}