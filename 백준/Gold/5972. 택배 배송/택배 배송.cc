#include <bits/stdc++.h>

const int INF = 1e8;

int N, M;
std::vector<std::pair<int, int>> graph[50001];

void Dijkstra() {
	std::vector<int> dist(50001, INF);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	pq.emplace(0, 1);
	dist[1] = 0;

	while (!pq.empty()) {
		const auto [cur_cost, cur_node] = pq.top();
		pq.pop();

		if (dist[cur_node] < cur_cost)
			continue;

		for (const auto [next_node, next_cost] : graph[cur_node]) {
			int cost = next_cost + cur_cost;

			if (cost < dist[next_node]) {
				dist[next_node] = cost;
				pq.emplace(cost, next_node);
			}
		}
	}

	std::cout << dist[N];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N >> M;
	while (M--) {
		int v1, v2, cost;
		std::cin >> v1 >> v2 >> cost;

		graph[v1].emplace_back(v2, cost);
		graph[v2].emplace_back(v1, cost);
	}

	Dijkstra();
	return 0;
}