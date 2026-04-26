#include <iostream>
#include <vector>

using namespace std;

int DFS(int start, vector<vector<int>>& graph, vector<bool>& visited) {
	visited[start] = true;
	int cnt = 1;

	for (int next : graph[start]) {
		if (!visited[next])
			cnt += DFS(next, graph, visited);
	}

	return cnt;
}

int main() {
	int T; cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N, M;
		cin >> N >> M;

		int answer = 0;

		vector<vector<int>> graph(N + 1);
		vector<vector<int>> rgraph(N + 1);
		vector<bool> visited(N + 1);

		for (int i = 0; i < M; ++i) {
			int s, e; cin >> s >> e;
			graph[s].push_back(e);
			rgraph[e].push_back(s);
		}

		for (int i = 1; i <= N; ++i) {
			fill(visited.begin(), visited.end(), false);
			int n =  DFS(i, graph, visited) - 1;

			fill(visited.begin(), visited.end(), false);
			int m = DFS(i, rgraph, visited) - 1;

			if (n + m == N - 1)
				answer++;
		}

		printf("#%d %d\n", tc, answer);
	}

	return 0;
}