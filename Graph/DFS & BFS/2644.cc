#include <bits/stdc++.h>

// 여러 사람들에 대한 부모 자식들 간의 관계가 주어졌을 때, 주어진 두 사람의 촌수를 구하는 문제

int n, m, p1, p2;

std::vector<int> graph[101];
std::vector<bool> visited(101, false);

// 두 사람 사이 최단 간선 수(촌수)를 구하는 문제이므로 BFS로 탐색 진행
int BFS(int p1, int p2) {
	std::queue<std::pair<int, int>> q;
	q.emplace(p1, 0);
	visited[p1] = true;

	while (!q.empty()) {
		auto [cur, dist] = q.front();
		q.pop();

		// 현재 사람이 찾고자 하는 사람이면 그 거리(촌수) 반환
		if (cur == p2)
			return dist;

		// 관계가 이어져 있는 사람들 탐색
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

	// 촌수는 트리 구조이므로 무향 그래프로 구조화  
	for (int i = 0; i < m; ++i) {
		int x, y; 
		std::cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	std::cout << BFS(p1, p2);
	return 0;
}