#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
#define INF 1e9

// n : 지역의 갯수, m : 수색 범위, r : 길의 갯수
int n, m, r;
int answer;

std::vector<std::pair<int, int>> field[MAX];
int items[MAX];

int Dijkstra(int start) {
	// 반복을 통해 답을 구하기 때문에 dist 배열은 Dijkstra 함수 내에서 선언
	int dist[MAX];
	std::fill_n(dist, n + 1, INF);

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	pq.emplace(0, start);
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)
			continue;
		for (int i = 0; i < field[cur].size(); i++) {
			int cost2 = cost + field[cur][i].second;

			if (cost2 < dist[field[cur][i].first]) {
				dist[field[cur][i].first] = cost2;
				pq.emplace(cost2, field[cur][i].first);
			}
		}
	}

	// 범위 내에서 습득할 수 있는 아이템의 갯수를 구함
	// 도달거리가 범위보다 멀면 아이템을 습득할 수 없음
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] > m)
			continue;
		sum += items[i];
	}

	return sum;
}

int main() {
	std::cin >> n >> m >> r;
	
	for (int t = 1; t <= n; t++) {
		std::cin >> items[t];
	}

	for (int i = 0; i < r; i++) {
		int a, b, l;
		std::cin >> a >> b >> l;

		// 무향 그래프이므로 양쪽 노드를 서로 연결해야 함
		field[a].emplace_back(b, l);
		field[b].emplace_back(a, l);
	}

	// 출발지에 따라 얻을 수 있는 아이템의 최대 갯수는 달라지므로 모든 노드의 경우를 따져봐야 함
	for (int i = 1; i <= n; i++) {
		answer = std::max(answer, Dijkstra(i));
	}
	std::cout << answer;

	return 0;
}