#include <bits/stdc++.h>

const int MAX = 51;

int N, M;
int field[MAX][MAX];
int selected[13];

std::vector<std::pair<int, int>> chickens, homes;

int answer = INT_MAX;

int CheckDist() {
	int dist = 0;

	for (auto& [hy, hx] : homes) {
		int min_dist = 1e6;

		for (int i = 0; i < chickens.size(); ++i) {
			if (selected[i]) 
				min_dist = std::min(min_dist, abs(hy - chickens[i].first) + abs(hx - chickens[i].second));
		}
		dist += min_dist;
	}
	return dist;
}

void DFS(int idx, int cnt) {
	if (cnt == M) {
		answer = std::min(CheckDist(), answer);
		return;
	}

	for (int i = idx; i < chickens.size(); ++i) {
		if (!selected[i]) {
			selected[i] = true;
			DFS(i + 1, cnt + 1);
			selected[i] = false;
		}
	}
}

int main() {
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> field[i][j];
			if (field[i][j] == 1) homes.emplace_back(i, j);
			if (field[i][j] == 2) chickens.emplace_back(i, j);
		}
	}

	DFS(0, 0);

	std::cout << answer;
	return 0;
}