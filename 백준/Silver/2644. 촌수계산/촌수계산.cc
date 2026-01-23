#include <bits/stdc++.h>

int n, m, p1, p2;

std::vector<int> graph[101];
std::vector<bool> visited(101, false);

int BFS(int p1, int p2) {
	std::queue<std::pair<int, int>> q;
	q.emplace(p1, 0);
	visited[p1] = true;

	while (!q.empty()) {
		auto [cur, dist] = q.front();
		q.pop();

		if (cur == p2)
			return dist;

		for (auto p : graph[cur]) {
			if (!visited[p]) {
				q.emplace(p, dist + 1);
				visited[p] = true;
			}
		}
	}

	return -1;
}

int main() {
	std::cin >> n;
	std::cin >> p1 >> p2;
	std::cin >> m;

	for (int i = 0; i < m; ++i) {
		int x, y; 
		std::cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	std::cout << BFS(p1, p2);
	return 0;
}