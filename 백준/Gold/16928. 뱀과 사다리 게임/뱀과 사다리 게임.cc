#include <bits/stdc++.h>

std::vector<int> field[101];
std::vector<bool> visited(101);

int BFS() {
	std::queue<std::pair<int, int>> q;
	q.emplace(1, 0);
	visited[1] = true;

	int answer = 0;
	while (!q.empty()) {
		auto [pos, cnt] = q.front();
		q.pop();

		if (pos == 100) {
			answer = cnt;
			break;
		}

		for (int i = 1; i <= 6; ++i) {
			int next = pos + i;

			if (next > 100)
				break;

			if (field[next].size() == 0) {
				if (!visited[next]) {
					q.emplace(next, cnt + 1);
					visited[next] = true;
				}
			}
			else {
				if (!visited[field[next][0]]) {
					q.emplace(field[next][0], cnt + 1);
					visited[field[next][0]] = true;
				}
			}
		}
	}

	return answer;
}

int main() {
	int N, M;
	std::cin >> N >> M;

	while (N--) {
		int x, y;
		std::cin >> x >> y;
		field[x].push_back(y);
	}

	while (M--) {
		int u, v;
		std::cin >> u >> v;
		field[u].push_back(v);
	}

	std::cout << BFS();
	return 0;
}