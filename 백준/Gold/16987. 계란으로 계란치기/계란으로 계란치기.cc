#include <bits/stdc++.h>

int N, answer;
std::vector<std::pair<int, int>> eggs;

void DFS(int idx) {
	if (idx == N) {
		int cnt = 0;

		for(auto& egg : eggs) {
			if (egg.first <= 0)
				cnt++;
		}
		answer = std::max(answer, cnt);
		return;
	}

	if (eggs[idx].first <= 0) {
		DFS(idx + 1);
		return;
	}

	bool is_all_broken = true;
	for (int i = 0; i < N; ++i) {
		if (i == idx || eggs[i].first <= 0)
			continue;
		is_all_broken = false;

		eggs[idx].first -= eggs[i].second;
		eggs[i].first -= eggs[idx].second;

		DFS(idx + 1);

		eggs[idx].first += eggs[i].second;
		eggs[i].first += eggs[idx].second;
	}

	if (is_all_broken)
		DFS(idx + 1);
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		int durability, weight;
		std::cin >> durability >> weight;
		eggs.emplace_back(durability, weight);
	}

	DFS(0);

	answer = std::max(0, answer);
	std::cout << answer;

	return 0;
}