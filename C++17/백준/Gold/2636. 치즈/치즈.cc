#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

const int MAX = 101;
int N, M;
int duration, piece;

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

int cheese[MAX][MAX];
bool visited[MAX][MAX];

int BFS() {
	std::queue<std::pair<int, int>> q;
	std::vector<std::pair<int, int>> melt;
	memset(visited, false, sizeof(visited));

	q.emplace(0, 0);
	visited[0][0] = true;

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int dx = x + dir_x[i];
			int dy = y + dir_y[i];

			if (dx < 0 || dx >= M || dy < 0 || dy >= N)
				continue;
			if (!visited[dy][dx]) {
				visited[dy][dx] = true;

				if (cheese[dy][dx] == 1)
					melt.emplace_back(dx, dy);
				else
					q.emplace(dx, dy);
			}
		}
	}

	for (auto [x, y] : melt) 
		cheese[y][x] = 0;
	
	return (int)melt.size();
}


int main() {
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> cheese[i][j];
		}
	}

	while (true) {
		int cnt = BFS();
		if (cnt == 0) {
			std::cout << duration << "\n" << piece << "\n";
			break;
		}
		duration++; 
		piece = cnt;
	}

	return 0;
}