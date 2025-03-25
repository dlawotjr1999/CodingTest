#include <iostream>
#include <queue>
#include <limits>
#define MAX 10001

// MST를 구하는 기본 문제
// Prim Algorithm 사용

const int INF = std::numeric_limits<int>::max();

int V, E;
std::vector<std::pair<int, int>> graph[MAX];
std::vector<bool> visited(MAX, false);

int Prim(int start) {
	// 최소 힙을 사용하여 가장 작은 가중치를 가진 간선을 찾음
	std::priority_queue <std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	int totalCost = 0;
	int connected = 0;

	pq.emplace(0, start);

	while (!pq.empty()) {
		int cost = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (visited[current])
			continue;
		visited[current] = true;
		totalCost += cost;
		connected++;

		if (connected == V)
			break;
		for (auto& edge : graph[current]) {
			int next = edge.first;
			int nextCost = edge.second;
			if (!visited[next])
				// 가장 작은 가중치가 힙의 top에 위치하게 됨
				pq.emplace(nextCost, next);
		}
	}
	return totalCost;
}

int main() {
	std::cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int A, B, C;
		std::cin >> A >> B >> C;

		graph[A].emplace_back(B, C);
		graph[B].emplace_back(A, C);
	}

	std::cout << Prim(1) << std::endl;

	return 0;
}