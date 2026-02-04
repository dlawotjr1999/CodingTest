#include <bits/stdc++.h>

std::vector<int> graph[101];
std::vector<bool> visited(101);

std::vector<int> cnt(101, 0);

void DFS(int node) {
	visited[node] = true;
	cnt[node]++;

	for (int next : graph[node]) {
		if (!visited[next]) {
			DFS(next);
		}
	}
}

int main() {
	int N;	std::cin >> N;

	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		std::cin >> a >> b;

		graph[a].push_back(b);
	}

	for (int i = 1; i <= N; ++i) {
		std::fill(visited.begin(), visited.end(), false);
		DFS(i);
	}

	for (int i = 1; i <= N; ++i) {
		if (cnt[i] == N) {
			std::cout << i;
			return 0;
		}
	}

	std::cout << -1;
	return 0;
}