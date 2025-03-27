#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 1e9

// Dijkstra Algorithm 구현 기본 문제

int N, M;
std::vector<std::pair<int, int>> bus[MAX];
int start, dest;
int dist[MAX];

void Dijkstra() {
	std::priority_queue<std::pair<int, int>> pq;
	pq.emplace(0, start);
	dist[start] = 0;

	while (!pq.empty()) {

		// 최소 비용을 음수로 저장했기 때문에 다시 양수로 변환해야 함 
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)
			continue;

		for (int i = 0; i < bus[cur].size(); i++) {
			int cost2 = cost + bus[cur][i].second;

			if (cost2 < dist[bus[cur][i].first]) {
				dist[bus[cur][i].first] = cost2;

				// 비용들을 음수로 처리해서 우선순위 큐에 삽입
				// std::greater<std::pair<int, int>>를 이용하면 음수를 이용하지 않아도 됨
				// 이 때 절댓값이 가장 작은 값. 즉 최소 비용이 큐의 가장 상단에 위치하게 된다
				pq.emplace(-cost2, bus[cur][i].first);
			}
		}
	}
	std::cout << dist[dest] << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> N;
	std::cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		bus[a].emplace_back(b, c);
	}

	std::cin >> start >> dest;
	for (int i = 1; i < MAX; i++) {
		dist[i] = INF;
	}
	Dijkstra();
	return 0;
}