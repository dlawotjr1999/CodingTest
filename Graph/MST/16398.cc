#include <bits/stdc++.h>

// 여러 행성 간 플로우를 연결하여 제국의 최소 관리 비용을 구하는 문제
// Prim 알고리즘을 이용하여 MST 구현

typedef long long ll;
int N;

std::vector<std::pair<ll, ll>> graph[1001];
bool visited[1001] = { false, };

ll Prim() {
	std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll>>, std::greater<std::pair<ll, ll>>> pq;
	long long total_cost = 0;
	long long connected = 0;

	pq.emplace(0,1);

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
		for(auto& [next, next_cost] : graph[cur]) {
			if (!visited[next]) {
				pq.emplace(next_cost, next);
			}
		}
	}

	return total_cost;
}

int main() {
	std::cin >> N;

	// 인접 행렬을 인접 리스트로 표현
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			int cost; 
			std::cin >> cost;
			graph[i].emplace_back(j, cost);
		}	
	}

	std::cout << Prim();
	return 0;
}