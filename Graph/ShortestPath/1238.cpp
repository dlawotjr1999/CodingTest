#include <iostream>
#include <vector>
#include <queue>

constexpr int MAX = 1001;
constexpr int INF = 1e9;
int N, M, X;

std::vector<std::pair<int, int>> field[MAX];
std::vector<std::pair<int, int>> rfield[MAX];

std::vector<int> results;

bool visited[MAX];

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
		field[a].emplace_back(b, c);
		rfield[b].emplace_back(a, c);
	}

	std::vector<int> dist_X_to_nodes = dijkstra(X, field);
	std::vector<int> dist_nodes_to_X = dijkstra(X, rfield);

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (dist_X_to_nodes[i] == INF || dist_nodes_to_X[i] == INF)
			continue;
		answer = std::max(answer, dist_X_to_nodes[i] + dist_nodes_to_X[i]);
	}

	std::cout << answer;
	return 0;
}