#include <iostream>
#include <vector>
#include <queue>

int N, M, V;

int matrix[1001][1001];
std::queue<int> queue;
std::vector<bool> visited(1001, false);

void DFS(int v) {
	visited[v] = true;
	std::cout << v << " ";

	for (int i = 1; i <= N; i++) {
		if (matrix[v][i] == 1 && !visited[i])
			DFS(i);
	}
}

void BFS(int v) {
	queue.push(v);
	visited[v] = true;
	std::cout << v << " ";

	while (!queue.empty()) {
		v = queue.front();
		queue.pop();

		for (int i = 1; i <= N; i++) {
			if (matrix[v][i] == 1 && !visited[i]) {
				queue.push(i);
				visited[i] = true;
				std::cout << i << " ";
			}
		}
	}
}

int main() {

	std::cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int u, v;
		std::cin >> u >> v;

		matrix[u][v] = 1;
		matrix[v][u] = 1;
	}

	std::fill(visited.begin(), visited.end(), false);
	DFS(V);

	std::cout << '\n';

	std::fill(visited.begin(), visited.end(), false);
	BFS(V);

	return 0;
}