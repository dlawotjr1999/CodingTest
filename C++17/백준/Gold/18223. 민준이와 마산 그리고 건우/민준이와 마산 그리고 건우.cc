#include <bits/stdc++.h>

const int INF = 1e8;
const int MAX = 5001;

int V, E, P;
std::vector<std::pair<int, int>> graph[MAX];

int Dijkstra(int s, int e) {
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	
	static int dist[MAX];
	std::fill(dist, dist + MAX, INF);
	
	pq.emplace(0, s);
	dist[s] = 0;

	while (!pq.empty()) {
		auto [cur_c, cur_v] = pq.top();
		pq.pop();

		if (cur_c > dist[cur_v]) 
			continue;
		if (cur_v == e) 
			return cur_c;

		for (auto& [v, c] : graph[cur_v]) {
			if (cur_c + c < dist[v]) {
				dist[v] = cur_c + c;
				pq.emplace(dist[v], v);
			}
		}
	}

	return INF;
}

int main() {
	std::cin >> V >> E >> P;

	while (E--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	int dist1 = Dijkstra(1, P) + Dijkstra(P, V);
	int dist2 = Dijkstra(1, V);

	std::cout << (dist1 <= dist2 ? "SAVE HIM" : "GOOD BYE");
	return 0;
}