#include <bits/stdc++.h>

const int MAX = 200000;
const long long INF = 1e15;

int N, M, A, B;

std::vector<std::pair<int, int>> graph[MAX + 1];
std::vector<int> answers;

std::vector<long long> Dijkstra(int start) {
	std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
	std::vector<long long> dist(N + 1, INF);

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
				pq.emplace(cost, next_node);
			}
		}
	}
	
	return dist;
}

int main() {
	std::cin >> N >> M >> A >> B;

	while (M--) {
		int u, v, c;
		std::cin >> u >> v >> c;
		graph[u].emplace_back(v, c);
		graph[v].emplace_back(u, c);
	}

	std::vector<long long> distA = Dijkstra(A);
	std::vector<long long> distB = Dijkstra(B);

	long long shortest_dist = distA[B];

	for (int i = 1; i <= N; ++i) {
		if (distA[i] + distB[i] == shortest_dist) {
			answers.push_back(i);
		}
	}

	std::cout << answers.size() << '\n';
	for (int node : answers) {
		std::cout << node << ' ';
	}
	return 0;
}