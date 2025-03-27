#include <iostream>
#include <vector>

// 1번 컴퓨터가 바이러스에 걸렸을 때 연쇄적으로 감염될 수 있는 컴퓨터의 수를 구하는 문제
// 단순 DFS 구현 문제

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
	// 1번 컴퓨터가 감염되었을 경우를 구하는 것이므로 DFS(1);
	DFS(1);

	std::cout << cnt - 1;
}