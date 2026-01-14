#include <bits/stdc++.h>

// 0-2 친구는 두 사람이 친구이거나, A와 친구이고, B와 친구인 C가 존재하는 경우를 의미함
// 또한 A와 B가 친구면, B와 A도 친구이고, A와 A는 친구가 아님
// 이 때 가장 유명한 사람, 즉 2-친구의 수가 가장 많은 사람의 2-친구의 수를 구하는 문제

int N;
int answer;

std::vector<std::string> field;

int BFS(int s) {
	std::vector<bool> visited(N, false);
	std::queue<std::pair<int, int>> q;
	
	q.emplace(s, 0);
	visited[s] = true;

	int cnt = 0;

	while (!q.empty()) {
		auto [c, d] = q.front();
		q.pop();

		// d가 0이면 바로 친구인 경우, 1은 한 다리 건너서 아는 친구임을 의미함
		// 즉 d가 2이면 2-친구의 범주를 벗어나므로 무시함
		if (d == 2)
			continue;

		// 현재 사람과 연결되어 있는 친구들을 탐색
		for (int i = 0; i < N; ++i) {
			if (field[c][i] == 'N')
				continue;
			if (visited[i])
				continue;

			visited[i] = true;
			cnt++;
			q.emplace(i, d + 1);
		}
	}

	return cnt;
}

int main() {
	std::cin >> N;
	field.resize(N);

	for (int i = 0; i < N; ++i) {
		std::cin >> field[i];
	}

	// 각 인원에 대한 2-친구의 수를 구함
	for (int i = 0; i < N; ++i) {
		answer = std::max(answer, BFS(i));
	}

	std::cout << answer;
	return 0;
}