#include <iostream>
#include <queue>
#include <vector>

const int MAX = 20000;
const int INF = 999999;

int V, E;
std::vector<std::pair<int, int>> graph[MAX];
int dist[MAX];

void Dijkstra(int start) {
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	pq.emplace(0, start);
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)
			continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int cost2 = cost + graph[cur][i].second;

			if (cost2 < dist[graph[cur][i].first]) {
				dist[graph[cur][i].first] = cost2;
				pq.emplace(cost2, graph[cur][i].first);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> V >> E;

	int start;
	std::cin >> start;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;

		graph[u].emplace_back(v, w);
	}
	for (int i = 0; i < MAX; i++) {
		dist[i] = INF;
	}

	Dijkstra(start);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			std::cout << "INF" << '\n';
		else
			std::cout << dist[i] << '\n';
	}

	return 0;
}