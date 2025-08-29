#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

constexpr int MAX = 500000;
constexpr int INF = 1e9;

int N;
int A, B, C;
int M;

long long result = -1;
int answer = -1;

std::vector<std::pair<int, int>> graph[MAX + 1];

std::vector<long long> Dijkstra(int N, int start) {
	std::vector<long long> dist(N + 1, INF);
	std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
	
	dist[start] = 0;
	pq.emplace(0, start);

	while (!pq.empty()) {
		auto [cost, node] = pq.top();
		pq.pop();

		if (cost > dist[node])
			continue;

		for (auto& [next_node, next_cost] : graph[node]) {
			long long new_cost = cost + (long long)next_cost;
			if (new_cost < dist[next_node]) {
				dist[next_node] = new_cost;
				pq.emplace(new_cost, next_node);
			}
		}
	}

	return dist;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N;
	std::cin >> A >> B >> C;
	std::cin >> M;

	for (int i = 0; i < M; ++i) {
		int a, b, cost;
		std::cin >> a >> b >> cost;

		graph[a].emplace_back(b, cost);
		graph[b].emplace_back(a, cost);
	}

	auto dist_A = Dijkstra(N, A);
	auto dist_B = Dijkstra(N, B);
	auto dist_C = Dijkstra(N, C);

	for (int i = 1; i <= N; ++i) {
		long long m = std::min({ dist_A[i], dist_B[i], dist_C[i] });
		if (m == INF) continue;
		if (m > result) {
			result = m;
			answer = i;
		}
	}

	std::cout << answer;
	return 0;
}