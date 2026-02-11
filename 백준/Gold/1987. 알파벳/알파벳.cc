#include <bits/stdc++.h>

int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };

int R, C;
int answer;

char field[21][21];
bool visited[26];

void DFS(int y, int x, int len) {
	answer = std::max(answer, len);

	for (int i = 0; i < 4; ++i) {
		int nx = x + dir_x[i];
		int ny = y + dir_y[i];

		if (nx < 1 || nx > C || ny < 1 || ny > R)
			continue;

		char next = field[ny][nx];

		if (!visited[next - 'A']) {
			visited[next - 'A'] = true;
			DFS(ny, nx, len + 1);
			visited[next - 'A'] = false;
		}
	}
}

int main() {
	std::cin >> R >> C;

	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			std::cin >> field[i][j];
		}
	}

	visited[field[1][1] - 'A'] = true;
	DFS(1, 1, 1);
	
	std::cout << answer;
	return 0;
}