#include <bits/stdc++.h>

int N, M, t;

std::vector<std::pair<int, int>> graph[10001];
bool visited[10001];

int Prim(int start) {
	std::priority_queue <std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	int connected = 0;
	int total_cost = 0;

	pq.emplace(0, start);

	while (!pq.empty()) {
		auto [cost, cur] = pq.top();
		pq.pop();

		if (visited[cur])
			continue;
		visited[cur] = true;

		if (cur != start) {
			total_cost += cost + (connected * t);
			connected++;
		}
		if (connected == N - 1)
			break;

		for (auto& [next, next_cost] : graph[cur]) {
			if (!visited[next]) {
				pq.emplace(next_cost, next);
			}
		}
	}

	return total_cost;
}

int main() {
	std::cin >> N >> M >> t;

	for (int i = 0; i < M; ++i) {
		int a, b, cost;
		std::cin >> a >> b >> cost;

		graph[a].emplace_back(b, cost);
		graph[b].emplace_back(a, cost);
	}

	std::cout << Prim(1);
	return 0;
}