#include <bits/stdc++.h>

// 주인공은 동생과 숨바꼭질을 하고 있으며, 동생을 찾기 위해 걷거나 순간이동을 할 수 있음
// 만약 주인공의 위치가 X이면 1초 후에 X-1 혹은 X+1로 이동할 수 있으며, 순간이동을 하는 경우에는 2*X 지점으로 이동하게 됨 
// 주인공과 동생의 위치가 주어져있을 때, 동생을 찾을 수 있는 가장 빠른 시간과 이동 경로를 구하는 문제

const int MAX = 100001;
int N, K;

void BFS(int start) {
	bool visited[MAX];	// 방문 여부 확인
	int traces[MAX];	// 바로 이전에 있었던 좌표를 저장하는 배열
	int dist[MAX];		// 현재 좌표의 탐색 레벨을 저장하는 배열

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

		// 갈 수 있는 모든 경로를 탐색
		// BFS 연산 후 dist에 현재 탐색 레벨을, traces에 현재 지점을 저장함
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

	// 존재했던 지점들을 역추적하며 경로 저장
	// 마지막에는 출발지점 저장
	std::vector<int> path;
	for (int i = K; i != start; i = traces[i])
		path.push_back(i);
	path.push_back(start);

	// 역추적으로 지점들을 저장했기 때문에 역순으로 출력해야 순방향이 됨
	for (int i = path.size() - 1; i >= 0; --i)
		std::cout << path[i] << ' ';
}

int main() {
	std::cin >> N >> K;
	BFS(N);
}