#include <iostream>
#include <vector>

int matrix[101][101];
std::vector<bool> visited(101, false);

int vertex, edge;
int cnt;

void DFS(int v) {
	visited[v] = true;
	cnt++;

	for (int i = 1; i <= vertex; i++) {
		if (matrix[v][i] == 1 && !visited[i]) {
			DFS(i);
		}
	}
}

int main() {
	std::cin >> vertex;
	std::cin >> edge;

	for (int i = 0; i < edge; i++) {
		int u, v;

		std::cin >> u >> v;
		matrix[u][v] = 1;
		matrix[v][u] = 1;
	}
	DFS(1);

	std::cout << cnt - 1;
}