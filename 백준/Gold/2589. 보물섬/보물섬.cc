#include <iostream>
#include <queue>

int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, -1, 0, 1 };

char field[50][50];

int N, M;
int answer;

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
				answer = std::max(answer, BFS(i, j));
		}
	}

	std::cout << answer;
	return 0;
}