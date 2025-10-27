#include <bits/stdc++.h>

// N*M 맵에서 0은 이동할 수 있는 곳, 1은 벽을 나타냄
// (1,1)에서 (N,M)으로 최단 경로로 이동하고자 하며, 상하좌우 인접한 칸으로만 이동이 가능함
// 또한 이동하는 도중 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면 벽을 한 개 까지 부수고 이동하는 것이 가능함
// 이 때 이동할 수 있는 최단 거리를 구하는 문제

const int MAX = 1001;
int N, M;

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

// visited 배열은 3차원으로 선언하여 벽을 부수고 지나간 경우와 그렇지 않은 경우를 구분할 수 있게 함
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

		// 목표 지점에 도착하면 거리 반환
		if (dy == N && dx == M)
			return dist;

		for (int i = 0; i < 4; ++i) {
			int ny = dy + dir_y[i];
			int nx = dx + dir_x[i];

			if (nx < 1 || nx > M || ny < 1 || ny > N)
				continue;

			// 벽을 부수고 지나가지 않는 경우
			// 그냥 이동 가능
			// 현재의 b 상태(벽을 이미 부쉈는지 여부)를 유지해서 이동
			if (field[ny][nx] == 0 && !visited[ny][nx][b]) {
				visited[ny][nx][b] = true;
				q.push({ b, ny, nx, dist + 1 });
			}
			// 벽을 부수고 지나가는 경우
			// 아직 벽을 부순 적이 없다면(b == false) 그 벽을 부수고 이동할 수 있음
			// 벽을 부수고 나면 b 상태는 true가 되며, 더 이상 벽을 부수지 못함
			// 벽을 부순 후의 visited로만 고려하여 이동함
			if (field[ny][nx] == 1 && !b && !visited[ny][nx][1]) {
				visited[ny][nx][1] = true;
				q.push({ true, ny, nx, dist + 1 });
			}
		}
	}

	// 도달하지 못한 경우에는 -1 반환
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