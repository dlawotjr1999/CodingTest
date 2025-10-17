#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

// 아래 문제를 구현
// https://www.acmicpc.net/problem/2636

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

	// 판의 가장자리에는 치즈가 놓여있지 않으므로, 왼쪽 상단부터 BFS를 통해 공기와 접촉된 치즈 조각 탐색
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

				// 바깥 공기와 접촉된 치즈 조각을 저장
				if (cheese[dy][dx] == 1)
					melt.emplace_back(dx, dy);
				else
					q.emplace(dx, dy);
			}
		}
	}

	// 바깥 공기와 접촉된 치즈들을 한 번에 녹임
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

		// 치즈가 모두 녹아 없어질 때까지 반복
		if (cnt == 0) {
			std::cout << duration << "\n" << piece << "\n";
			break;
		}
		duration++; 
		piece = cnt;
	}

	return 0;
}