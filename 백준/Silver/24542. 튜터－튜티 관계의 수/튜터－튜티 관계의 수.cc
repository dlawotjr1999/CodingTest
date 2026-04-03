#include <bits/stdc++.h>

int N, M;
long long answer = 1;

std::vector<int> graph[200001];
std::vector<bool> visited(200001);

int DFS(int start) {
	visited[start] = true;
	int cnt = 1;

	for (int next : graph[start]) {
		if (!visited[next])
			cnt += DFS(next);
	}

	return cnt;
}

int main() {
	std::cin >> N >> M;

	for (int i = 1; i <= M; ++i) {
		int u, v;
		std::cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; ++i) {
		if (!visited[i]) {
			answer = (answer * DFS(i)) % 1000000007;
		}
	}

	std::cout << (answer % 1000000007);
	return 0;
}