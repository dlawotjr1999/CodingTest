#include <bits/stdc++.h>

int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };

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

		if (d == 2)
			continue;

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

	for (int i = 0; i < N; ++i) {
		answer = std::max(answer, BFS(i));
	}

	std::cout << answer;
	return 0;
}