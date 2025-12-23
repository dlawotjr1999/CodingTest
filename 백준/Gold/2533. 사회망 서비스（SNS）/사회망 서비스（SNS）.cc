#include <bits/stdc++.h>

const int MAX = 1000001;

int N;

std::vector<int> graph[MAX];
bool visited[MAX];
int DP[MAX][2];

void DFS(int cur) {
	visited[cur] = true;
	DP[cur][0] = 0;
	DP[cur][1] = 1;

	for (int node : graph[cur]) {
		if (!visited[node]) {
			DFS(node);
			DP[cur][0] += DP[node][1];
			DP[cur][1] += std::min(DP[node][0], DP[node][1]);
		}
	}
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS(1);
	std::cout << std::min(DP[1][0], DP[1][1]);

	return 0;
}