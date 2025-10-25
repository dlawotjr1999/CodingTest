#include <bits/stdc++.h>

const int MAX = 1001;
int N, M;

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

int field[MAX][MAX];
bool visited[MAX][MAX][2];

struct elm {
	bool isBreak;
	int y, x, dist;
};

int BFS() {
	std::queue<elm> q;
	q.push({ false, 1, 1, 1 });
	visited[1][1][0] = true;

	while (!q.empty()) {
		auto [b, dy, dx, dist] = q.front();
		q.pop();

		if (dy == N && dx == M)
			return dist;

		for (int i = 0; i < 4; ++i) {
			int ny = dy + dir_y[i];
			int nx = dx + dir_x[i];

			if (nx < 1 || nx > M || ny < 1 || ny > N)
				continue;

			if (field[ny][nx] == 0 && !visited[ny][nx][b]) {
				visited[ny][nx][b] = true;
				q.push({ b, ny, nx, dist + 1 });
			}
			if (field[ny][nx] == 1 && !b && !visited[ny][nx][1]) {
				visited[ny][nx][1] = true;
				q.push({ true, ny, nx, dist + 1 });
			}
		}
	}

	return -1;
}

int main() {
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		std::string str;
		std::cin >> str;

		for (int j = 0; j < M; ++j) {
			field[i + 1][j + 1] = str[j] - '0';
		}
	}

	std::cout << BFS();
	return 0;
}