#include <bits/stdc++.h>

const int MAX = 100001;
int N, K;

void BFS(int start) {
	bool visited[MAX];
	int traces[MAX];
	int dist[MAX];

	memset(visited, false, sizeof(visited));
	memset(traces, -1, sizeof(traces));
	memset(dist, -1, sizeof(traces));

	std::queue<int> q;

	q.push(start);
	visited[start] = true;
	traces[start] = start;
	dist[start] = 0;

	while (!q.empty() && q.front() != K) {
		int cur = q.front();
		q.pop();

		for (auto& next : { cur - 1, cur + 1, cur * 2 }) {
			if (0 <= next && next < MAX && !visited[next]) {
				visited[next] = true;
				q.push(next);
				dist[next] = dist[cur] + 1;
				traces[next] = cur;
			}
		}
	}

	std::cout << dist[K] << '\n';

	std::vector<int> path;
	for (int i = K; i != start; i = traces[i])
		path.push_back(i);
	path.push_back(start);

	for (int i = path.size() - 1; i >= 0; --i)
		std::cout << path[i] << ' ';
}

int main() {
	std::cin >> N >> K;
	BFS(N);
}