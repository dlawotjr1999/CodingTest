#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int N, M;

int x_dir[4] = { -1,0,1,0 };
int y_dir[4] = { 0,1,0,-1 };

int field[500][500];
bool visited[500][500];
std::vector<int> areas;

void BFS(int x, int y) {
	int area = 1;
	
	std::queue<std::pair<int, int>> queue;
	visited[x][y] = true;
	queue.emplace(x, y);

	while (!queue.empty()) {
		x = queue.front().first;
		y = queue.front().second;
		queue.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = x + x_dir[i];
			int new_y = y + y_dir[i];

			if ((0 <= new_x && new_x < N) && (0 <= new_y && new_y < M)) {
				if (field[new_x][new_y] && !visited[new_x][new_y]) {
					visited[new_x][new_y] = true;
					queue.emplace(new_x, new_y);
					area++;
				}
			}
		}
	}
	areas.push_back(area);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int cnt = 0;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> field[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] && !visited[i][j]) {
				BFS(i, j);
				cnt++;
			}
		}
	}

	// areas가 비어있을 때를 고려해야 함
	int max = areas.empty() ? 0 : *std::max_element(areas.begin(), areas.end());
	std::cout << cnt << '\n';
	std::cout << max << '\n';

}