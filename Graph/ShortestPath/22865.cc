#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 세 명의 친구 A, B, C가 살고 있는 집으로부터 가장 먼 곳에 집을 구하려고 함
// 가장 먼 곳은 선택할 집에서 거리가 가장 가까운 친구의 집까지의 거리를 기준으로 거리가 가장 먼 곳을 의미함
// 이 때, 친구들이 살고 있는 집으로부터 가장 먼 곳의 땅 번호를 구하는 문제

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

	// 특정 한 지점에서 A,B,C의 집까지의 거리 비교
	// 그 거리들 중에서 가장 거리가 먼 지점이 정답이 됨 
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