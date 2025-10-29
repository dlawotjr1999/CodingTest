#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

// 신도시 건물 사이들을 잇는 양방향 도로를 만들려고 할 때, 모든 건물을 최소 비용으로 잇고자 함
// 이 때, 모든 도로로 이을 때보다 최소 비용으로 건물을 이을 때 절약되는 비용을 구하는 문제
// 모든 건물이 연결되어 있지 않는 경우에는 -1을 출력함

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

	// 모든 건물이 연결되어 있지 않는 경우에응 -1 반환
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

	// 1번 건물에서부터 계산 진행
	long long mst = Prim(1);
	if (mst == -1)
		std::cout << -1;
	else
		std::cout << total - Prim(1);

	return 0;
}