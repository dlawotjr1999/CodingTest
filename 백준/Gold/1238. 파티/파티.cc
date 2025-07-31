#include <iostream>
#include <vector>
#include <queue>

// 어떤 마을에서 파티를 진행하려고 할 때, 다른 마을로부터 그 마을까지 왕복 거리의 최소 비용을 구하는 문제
// 마을 간 도로는 단방향이며, 파티를 마치고 돌아갈 때도 최소 비용으로 돌아가야 함

// 단방향 그래프에서 왕복 거리의 최소 비용들을 구해야 함
// 즉, 원래 그래프와 이를 뒤집은 역그래프를 활용하여 왕복 거리의 최소 비용을 구할 수 있음

constexpr int MAX = 1001;
constexpr int INF = 1e9;
int N, M, X;

std::vector<std::pair<int, int>> field[MAX];
std::vector<std::pair<int, int>> rfield[MAX];

std::vector<int> dijkstra(int node, const std::vector<std::pair<int, int>> field[]) {
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	std::vector<int> dist(MAX, INF);

	dist[node] = 0;
	pq.emplace(node, 0);

	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)
			continue;

		for (auto& node : field[cur]) {
			int next_node = node.first;
			int next_cost = node.second + cost;

			if (next_cost < dist[next_node]) {
				dist[next_node] = next_cost;
				pq.emplace(next_node, next_cost);
			}
		}
	}
	return dist;
}

int main() {
	std::cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		field[a].emplace_back(b, c);	// 원래 그래프
		rfield[b].emplace_back(a, c);	// 역그래프
	}

	std::vector<int> dist_X_to_nodes = dijkstra(X, field);
	std::vector<int> dist_nodex_to_X = dijkstra(X, rfield);

	// 왕복 거리의 합이 가장 큰 멤버의 비용을 구함
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (dist_X_to_nodes[i] == INF || dist_nodex_to_X[i] == INF)
			continue;
		answer = std::max(answer, dist_X_to_nodes[i] + dist_nodex_to_X[i]);
	}

	std::cout << answer;
	return 0;
}