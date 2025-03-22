#include <iostream>
#include <queue>
#include <cstring>

int h, w;

int field[51][51];
int visited[51][51];

int x_dir[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int y_dir[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };

void BFS(int h, int w) {
	std::queue<std::pair<int, int>> queue;
	queue.emplace(h, w);
	visited[h][w] = true;

	while (!queue.empty()) {
		int cur_h = queue.front().first;
		int cur_w = queue.front().second;
		queue.pop();

		for (int i = 0; i < 8; i++) {
			int x = cur_h + x_dir[i];
			int y = cur_w + y_dir[i];

			if ((1 <= x && 1 <= y) && (x <= h && y <= w)) {
				if (field[x][y] && !visited[x][y]) {
					visited[x][y] = true;
					queue.emplace(x, y);
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int cnt = 0;

	while (true) {
		std::cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				std::cin >> field[i][j];
			}
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (field[i][j] && !visited[i][j]) {
					BFS(i, j);
					cnt++;
				}
			}
		}

		std::cout << cnt << std::endl;

		memset(field, false, sizeof(field));
		memset(visited, false, sizeof(visited));
		cnt = 0;
	}

	return 0;
}