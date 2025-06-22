#include <iostream>
#include <vector>
#include <queue>

constexpr int MAX = 100001;
constexpr int INF = 1e9;

int T;
std::vector<std::pair<int, int>> computers[MAX];
int times[MAX];

void Dijkstra(int start) {
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	times[start] = 0;
	pq.emplace(0, start);

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (times[cur] < cost)
			continue;

		for (int i = 0; i < computers[cur].size(); ++i) {
			int cost2 = cost + computers[cur][i].second;

			if (cost2 < times[computers[cur][i].first]) {
				times[computers[cur][i].first] = cost2;
				pq.emplace(cost2, computers[cur][i].first);
			}
		}

	}
}

int main() {
	std::cin >> T;

	while (T--) {
		int n, d, s;
		std::cin >> n >> d >> s;
		for (int i = 1; i <= n; ++i) {
			computers[i].clear();
			times[i] = INF;
		}

		for (int i = 0; i < d; ++i) {
			int a, b, s;
			std::cin >> a >> b >> s;
			computers[b].emplace_back(a, s);
		}

		Dijkstra(s);

		int cnt = 0, lastTime = 0;
		for (int i = 1; i <= n; ++i) {
			if (times[i] < INF) {
				++cnt;
				lastTime = std::max(lastTime, times[i]);
			}
		}

		std::cout << cnt << ' ' << lastTime << '\n';
	}

	return 0;
}