#include <iostream>
#include <queue>
#define MAX 101

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

			if ((0 <= x_new && x_new < N) && (0 <= y_new && y_new < M)
				&& !visited[x_new][y_new] && maze[x_new][y_new] == 1) {
				visited[x_new][y_new] = true;
				queue.emplace(x_new, y_new);
				dist[x_new][y_new] = dist[x_][y_] + 1;
			}
		}
	}
}

int main() {
	std::cin >> N >> M;

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