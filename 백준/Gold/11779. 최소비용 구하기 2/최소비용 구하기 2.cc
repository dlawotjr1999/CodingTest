#include <bits/stdc++.h>

const int MAX = 1000;
const long long INF = 1e12;

int n, m;
int s, e;

long long Dijkstra(int start, std::vector<std::pair<int, int>> graph[], std::vector<int>& parent) {
	std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
	std::vector<long long> dist(n + 1, INF);

	pq.emplace(0, start);
	dist[start] = 0;

	while (!pq.empty()) {
		auto [cur_cost, cur_node] = pq.top();
		pq.pop();

		if (cur_cost > dist[cur_node])
			continue;

		for (auto [next_node, next_cost] : graph[cur_node]) {
			long long cost = 1LL * cur_cost + next_cost;

			if (cost < dist[next_node]) {
				dist[next_node] = cost;
				parent[next_node] = cur_node;
				pq.emplace(cost, next_node);
			}
		}
	}
	
	return dist[e];
}

int main() {
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> graph[MAX + 1];
	std::vector<int> parent(n + 1, -1);

	while (m--) {
		int u, v, c;
		std::cin >> u >> v >> c;
		graph[u].emplace_back(v, c);
	}
	std::cin >> s >> e;

	int shortest_dist = Dijkstra(s, graph, parent);

	std::vector<int> path;
	for (int cur = e; cur != -1; cur = parent[cur]) {
		path.push_back(cur);
	}
	std::reverse(path.begin(), path.end());

	std::cout << shortest_dist << '\n';
	std::cout << path.size() << '\n';
	for (int node : path)
		std::cout << node << ' ';

	return 0;
}