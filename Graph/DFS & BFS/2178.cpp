#include <iostream>
#include <queue>
#define MAX 101

// 미로를 탈출하는 데 필요한 최소 비용을 구하는 문제
// 흔히 나오는, 방향과 DFS, BFS를 이용한 경로 탐색 문제
// 지나온 길의 좌표에 1을 더하면서 최단 경로를 구함

int N, M;
int maze[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];

int x_dir[4] = { -1,1,0,0 };
int y_dir[4] = { 0,0,-1,1 };

std::queue<std::pair<int, int>> queue;

void BFS(int x, int y) {
	visited[x][y] = true;
	queue.emplace(x, y);
	dist[x][y]++;

	while (!queue.empty()) {
		int x_ = queue.front().first;
		int y_ = queue.front().second;

		queue.pop();

		for (int i = 0; i < 4; i++) {
			int x_new = x_ + x_dir[i];
			int y_new = y_ + y_dir[i];

			// 1(길)로 이루어진 곳만 갈 수 있음 => 1보다 큰 값을 가진 좌표는 이미 지나온 길이기 때문
			if ((0 <= x_new && x_new < N) && (0 <= y_new && y_new < M)
				&& !visited[x_new][y_new] && maze[x_new][y_new] == 1) {
				visited[x_new][y_new] = true;
				queue.emplace(x_new, y_new);
				// 지나온 좌표에 1을 더함으로써 지나왔음을 표시하며, 동시에 최소비용을 구할 수 있도록 함
				dist[x_new][y_new] = dist[x_][y_] + 1;
			}
		}
	}
}

int main() {
	std::cin >> N >> M;

	// 입력 주의
	// 공백없이 입력되는 경우 입력을 string으로 처리함
	for (int i = 0; i < N; i++) {
		std::string row;
		std::cin >> row;

		for (int j = 0; j < M; j++) {
			maze[i][j] = row[j] - '0';
		}
	}

	BFS(0, 0);

	std::cout << dist[N - 1][M - 1];
}