#include <bits/stdc++.h>

// 치킨 거리는 집과 가장 가까운 치킨집까지의 거리이며, 그 거리는 manhattan distance로 표현됨
// 각 치킨 거리의 합은 '도시의 치킨 거리'이며, 수익이 가장 많이 나는 M개의 치킨집을 제외하고 모두 폐업시키고자 함
// 이 때, 가장 작은 값의 '도시의 치킨 거리'를 구하는 문제

const int MAX = 51;

int N, M;
int field[MAX][MAX];
int selected[13];

std::vector<std::pair<int, int>> chickens, homes;

int answer = INT_MAX;

int CheckDist() {
	int dist = 0;

	// 모든 집에 대해서 각 치킨 거리를 구하여 누적
	// 이 누적값이 도시의 치킨 거리
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
	// 치킨집을 M개 고르면 도시의 치킨 거리를 구함
	if (cnt == M) {
		answer = std::min(CheckDist(), answer);
		return;
	}

	// 조합을 활용하여 폐업하지 않을 치킨집 선정
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

	// 입력된 값(좌표)들을 따로 저장하는 로직을 추가하면 시간 초과가 발생하므로 입력 시부터 좌표를 저장하여 시간 단축 
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