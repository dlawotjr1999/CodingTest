#include <iostream>
#include <vector>
#include <queue>

// 해킹한 컴퓨터 번호와 각 의존성이 존재할 때, 바이러스에 감염된 컴퓨터의 수와 그에 걸리는 시간을 구하는 문제
// 만약 b가 a를 의존하면, a에 의해 b가 감염될 수 있지만 b가 a를 의존하지 않는다면 a가 감염되더라도 b는 감염되지 않음

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

		// 의존 관계가 존재하므로 유향 그래프로 선언
		for (int i = 0; i < d; ++i) {
			int a, b, s;
			std::cin >> a >> b >> s;
			computers[b].emplace_back(a, s);
		}

		Dijkstra(s);

		// Dijkstra 알고리즘이 모두 끝난 후에 dist 배열에는 시작지점에서 각 지점까지의 최단 경로가 존재함
		// 배열에 INF가 존재하면, 그 컴퓨터는 감염되지 않았음을 의미함
		// 또한 INF를 제외한 배열 내 가장 큰 값은, 마지막으로 감염이 이루어진 시간을 의미함
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