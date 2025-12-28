#include <bits/stdc++.h>

// 출발지에서 마산으로 이동하고자 할 때, 반드시 P번 정점을 거쳐서 가야만 하는 최단 경로와 출발지에서 마산으로 가는 최단 경로가 존재함
// 이 때, 두 거리 중 더 짧은 거리를 구하는 문제
// 전자인 경우 "SAVE HIM"을, 후자인 경우 "GOOD BYE"를 출력함

const int INF = 1e8;
const int MAX = 5001;

int V, E, P;
std::vector<std::pair<int, int>> graph[MAX];

// Dijkstar 알고리즘 수행
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

		// 목적지에 다다른 경우 그 거리 반환
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

	// case1 : P를 무조건 거쳐서 최단 거리로 마산으로 이동하는 경우
	// case2 : 출발지에서 마산으로 최단 거리로 이동하는 경우
	// 두 경로 중 더 짧은 경로를 선택
	int dist1 = Dijkstra(1, P) + Dijkstra(P, V);
	int dist2 = Dijkstra(1, V);

	std::cout << (dist1 <= dist2 ? "SAVE HIM" : "GOOD BYE");
	return 0;
}