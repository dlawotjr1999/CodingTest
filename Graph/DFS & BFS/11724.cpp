#include <iostream>

int N, M;
int graph[1001][1001];
bool visited[1001];

void DFS(int x) {
	visited[x] = true;

	for (int i = 1; i <= N; i++) {
		if (graph[x][i] == 1 && !visited[i]) {
			DFS(i);
		}
	}
}

int main() {
	std::cin >> N >> M;
	int cnt = 0;

	for (int i = 0; i < M; i++) {
		int u, v;
		std::cin >> u >> v;

		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			DFS(i);
			cnt++;
		}
	}

	std::cout << cnt << std::endl;
}
