#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
#define INF 1e9

int n, m, r;
int answer;

std::vector<std::pair<int, int>> field[MAX];
int items[MAX];

int Dijkstra(int start) {
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
		field[a].emplace_back(b, l);
		field[b].emplace_back(a, l);
	}

	for (int i = 1; i <= n; i++) {
		answer = std::max(answer, Dijkstra(i));
	}
	std::cout << answer;

	return 0;
}