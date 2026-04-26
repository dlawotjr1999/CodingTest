#include <bits/stdc++.h>

const int INF = 1e8;

struct info {
	int cost;
	int u, v;
};

bool hasNegativeCycle(std::vector<info>& edges, int n) {
	std::vector<int> dist(n + 1, 0);
	dist[n] = 0;

	for (int i = 1; i < n; ++i) {
		for (auto& edge : edges) {
			auto [cost, u, v] = edge;

			if (dist[u] != INF && dist[u] + cost < dist[v])
				dist[v] = dist[u] + cost;
		}
	}

	for (auto& edge : edges) {
		auto [cost, u, v] = edge;

		if (dist[u] != INF && dist[u] + cost < dist[v])
			return true;
	}

	return false;
}

int main() {
	int T; std::cin >> T;

	while (T--) {
		int N, M, W;
		std::cin >> N >> M >> W;
		
		std::vector<info> edges;
		for (int i = 0; i < M; ++i) {
			int u, v, cost;
			std::cin >> u >> v >> cost;
			edges.push_back({ cost, u, v });
			edges.push_back({ cost, v, u });
		}

		for (int i = 0; i < W; ++i) {
			int u, v, cost;
			std::cin >> u >> v >> cost;
			edges.push_back({ -cost, u, v });
		}

		std::cout << (hasNegativeCycle(edges, N) ? "YES" : "NO") << '\n';
	}

	return 0;
}