#include <iostream>
#include <cstring>
#include <queue>

const int MAX = 301;

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

int N, M;
int answer;

int field[MAX][MAX];
int temp[MAX][MAX];

bool visited[MAX][MAX];

void BFS(int y, int x) {
	std::queue<std::pair<int, int>> q;
	q.emplace(y, x);
	visited[y][x] = true;
	
	while (!q.empty()) {
		auto [cur_y, cur_x] = q.front();
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int ny = cur_y + dir_y[k];
			int nx = cur_x + dir_x[k];

			if (ny <= 0 || ny > N || nx <= 0 || nx > M)
				continue;

			if (field[ny][nx] != 0 && !visited[ny][nx]) {
				visited[ny][nx] = true;
				q.emplace(ny, nx);
			}
		}
	}
}

int main() {
	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			std::cin >> field[i][j];
		}
	}

	while (true) {
		int cnt = 0;

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				if (field[i][j] != 0) {
					int cur = field[i][j];

					for (int k = 0; k < 4; ++k) {
						int dx = j + dir_x[k];
						int dy = i + dir_y[k];

						if (dy <= 0 || dy > N || dx <= 0 || dx > M) 
							continue;

						if (field[dy][dx] == 0 && cur > 0)
							cur--;
					}
					temp[i][j] = cur;
				}
			}
		}
		memcpy(field, temp, sizeof(field));

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				if (field[i][j] != 0 && !visited[i][j]) {
					BFS(i, j);
					cnt++;
				}
			}
		}
		answer++;

		if (cnt >= 2) {
			std::cout << answer;
			return 0;
		}

		if (cnt == 0) {
			std::cout << 0;
			return 0;
		}

		memset(temp, 0, sizeof(temp));
		memset(visited, false, sizeof(visited));
	}
}