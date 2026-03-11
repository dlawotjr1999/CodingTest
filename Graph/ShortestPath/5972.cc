#include <bits/stdc++.h>

// 택배를 배달하기 위해서는 가는 길에 만나는 모든 소들에게 여물을 줘야함
// 이때, 배달을 하기 위해 확보해야하는 최소 여물의 수를 구하는 문제

const int INF = 1e8;

int N, M;
std::vector<std::pair<int, int>> graph[50001];

// 1번 노드에서 시작하여 N번 노드까지 가는데 필요한 여물의 양을 구함
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

	// N번 노드까지 계산 후의 여물 양 return
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

	// 각 노드들과 그 사이의 여물 양이 주어지므로 Dijkstra 알고리즘 사용
	Dijkstra();
	return 0;
}