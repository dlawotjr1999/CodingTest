#include <bits/stdc++.h>

// 한 나라 안에 있는 여러 도시들을 정복하여 연결하고자 할 때, 모든 도시들을 연결하는 최소 비용을 구하는 문제
// 각 도시를 연결할 때마다 추가 비용 t가 발생하며, 현재 점거한 도시는 1번 도시 뿐임

int N, M, t;

std::vector<std::pair<int, int>> graph[10001];
bool visited[10001];

int Prim(int start) {
	std::priority_queue <std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	int connected = 0;
	int total_cost = 0;

	pq.emplace(0, start);

	while (!pq.empty()) {
		auto [cost, cur] = pq.top();
		pq.pop();

		if (visited[cur])
			continue;
		visited[cur] = true;

		// 시작점이 아닌 경우에만 연결 과정에서 추가 비용 t를 더함
		if (cur != start) {
			total_cost += cost + (connected * t);
			connected++;
		}
		if (connected == N - 1)
			break;

		for (auto& [next, next_cost] : graph[cur]) {
			if (!visited[next]) {
				pq.emplace(next_cost, next);
			}
		}
	}

	return total_cost;
}

int main() {
	std::cin >> N >> M >> t;

	for (int i = 0; i < M; ++i) {
		int a, b, cost;
		std::cin >> a >> b >> cost;

		graph[a].emplace_back(b, cost);
		graph[b].emplace_back(a, cost);
	}

	// 현재 점거중인 도시인 1번 도시를 시작점으로 Prim 알고리즘 실행
	std::cout << Prim(1);
	return 0;
}