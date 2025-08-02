#include <iostream>
#include <queue>

// 어떤 섬 내에 보물이 서로 간 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있음
// 이동은 상하좌우로만 이동이 가능하며, 한 칸 이동하는 데 한 시간이 소요됨
// 이 때, 보물이 묻혀있는 두 곳 간의 최단 거리로 이동하는 시간을 구하는 문제

int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, -1, 0, 1 };

char field[50][50];

int N, M;
int answer;

// 최단 거리를 구해야하므로 BFS 이용
int BFS(int x, int y) {
	std::queue<std::pair<int, int>> q;
	int dist[50][50] = { 0, };
	int max_dist = 0;

	q.emplace(x, y);
	dist[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = x + dir_x[i];
			int new_y = y + dir_y[i];

			if ((0 <= new_x && new_x < N) && (0 <= new_y && new_y < M) && 
				!dist[new_x][new_y] && field[new_x][new_y] == 'L') {
				dist[new_x][new_y] = dist[x][y] + 1;

				// 육지로 이루어진 칸에서의 BFS를 통해 가장 멀리 떨어진 곳을 찾아냄
				max_dist = std::max(max_dist, dist[new_x][new_y] - 1);
				q.emplace(new_x, new_y);
			}
		}
	}

	return max_dist;
}

int main() {
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::string temp;
		std::cin >> temp;

		for (int j = 0; j < M; j++) {
			field[i][j] = temp[j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 'L')

				// 각 칸으로부터의 BFS로 max_dist를 구하고, 그 max_dist 중 가장 큰 값이 보물이 묻힌 위치가 됨
				answer = std::max(answer, BFS(i, j));
		}
	}

	std::cout << answer;
	return 0;
}