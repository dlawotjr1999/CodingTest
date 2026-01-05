#include <iostream>
#include <algorithm>

int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };

int N, M;
int answer;

int board[6][6];
bool visited[6][6];

void DFS(int sum, int y, int x) {
	if (y > N) {
		answer = std::max(answer, sum);
		return;
	}

	int ny = y;
	int nx = x + 1;
	if (nx > M) { nx = 1; ny++; }

	DFS(sum, ny, nx);

	if (!visited[y][x]) {
		for (int i = 0; i < 4; ++i) {
			int dy_1 = y + dir_y[i];
			int dx_1 = x + dir_x[i];

			int dy_2 = y + dir_y[(i + 1) % 4];
			int dx_2 = x + dir_x[(i + 1) % 4];

			if (dy_1 < 1 || dy_1 > N || dy_2 < 1 || dy_2 > N || dx_1 < 1 || dx_1 > M || dx_2 < 1 || dx_2 > M)
				continue;
			if (visited[dy_1][dx_1] || visited[dy_2][dx_2])
				continue;

			visited[dy_1][dx_1] = true; 
			visited[y][x] = true; 
			visited[dy_2][dx_2] = true;
            
			int cur_sum = 2 * board[y][x] + board[dy_1][dx_1] + board[dy_2][dx_2];
			DFS(sum + cur_sum, ny, nx);
            
			visited[dy_1][dx_1] = false;
			visited[y][x] = false; 
			visited[dy_2][dx_2] = false;
		}
	}
}

int main() {
	std::cin >> N >> M;

	for(int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			std::cin >> board[i][j];
		}
	}

	DFS(0, 1, 1);
	std::cout << answer;
}