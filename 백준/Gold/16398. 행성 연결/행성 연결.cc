#include <bits/stdc++.h>

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