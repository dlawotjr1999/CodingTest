#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int Dijkstra(int N, vector<string>& graph) {
	const int INF = 1e8;
	vector<vector<int>> dist(N, vector<int>(N, INF));

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	
	pq.emplace(0, 0, 0);
	dist[0][0] = 0;

	while (!pq.empty()) {
		auto [cur_cost, y, x] = pq.top();
		pq.pop();

		if (dist[y][x] < cur_cost) 
			continue;

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			int next_cost = cur_cost + (graph[ny][nx] - '0');

			if (next_cost < dist[ny][nx]) {
				dist[ny][nx] = next_cost;
				pq.emplace(next_cost, ny, nx);
			}
		}
	}

	return dist[N - 1][N - 1];
}

int main() {
	int T;	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int N;	cin >> N;
		
		vector<string> graph(N);
		for (int i = 0; i < N; ++i) {
			cin >> graph[i];
		}

		printf("#%d %d\n", t, Dijkstra(N, graph));
	}

	return 0;
}