#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

const int MAX = 100001;

long long total;
int N, M;

std::vector<std::pair<int, int>> graph[MAX];

long long Prim(int start) {
	std::vector<bool> visited(N + 1, false);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

	long long total_cost = 0;
	int connected = 0;

	pq.emplace(0, start);

	while (!pq.empty()) {
		auto [cost, cur] = pq.top();
		pq.pop();

		if (visited[cur])
			continue;
		visited[cur] = true;
		total_cost += cost;
		connected++;

		if (connected == N)
			break;
		for (auto& [next_node, next_cost] : graph[cur]) {
			if (!visited[next_node])
				pq.emplace(next_cost, next_node);
		}
	}

	if (connected < N) {
		return -1;
	}

	return total_cost;
}

int main() {
	std::cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;
		total += c;

		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	long long mst = Prim(1);
	if (mst == -1)
		std::cout << -1;
	else
		std::cout << total - Prim(1);

	return 0;
}