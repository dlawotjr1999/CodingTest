#include <bits/stdc++.h>

#define BLACK 2
#define WHITE 3

const int MAX = 20000;

bool isBipartite(int size, std::vector<int> graph[], std::vector<int>& visited) {
	for (int i = 1; i <= size; ++i) {
		for (int next : graph[i]) {
			if (visited[i] == visited[next])
				return false;
		}
	}

	return true;
}

void DFS(int s, std::vector<int> graph[], std::vector<int>& visited) {
	if (!visited[s])
		visited[s] = BLACK;

	for (int next : graph[s]) {
		if (!visited[next]) {
			if (visited[s] == BLACK)
				visited[next] = WHITE;
			else if (visited[s] == WHITE)
				visited[next] = BLACK;

			DFS(next, graph, visited);
		}
	}
}

int main() {
	int K;	std::cin >> K;

	while (K--) {
		std::vector<int> graph[MAX + 1];
		std::vector<int> visited(MAX + 1);

		int V, E;
		std::cin >> V >> E;

		for (int i = 0; i < E; ++i) {
			int u, v;
			std::cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <= V; ++i) {
			if (!visited[i])
				DFS(i, graph, visited);
		}

		std::cout << (isBipartite(V, graph, visited) ? "YES" : "NO") << '\n';
	}

	return 0;
}