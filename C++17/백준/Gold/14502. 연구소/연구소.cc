#include <bits/stdc++.h>

int N, M;
int answer = 0;

int field[9][9];
int test[9][9];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

int BFS() {
	std::memcpy(test, field, sizeof(field));
	std::queue<std::pair<int, int>> q;
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (test[i][j] == 2)
				q.emplace(i, j);
		}
	}

	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;
			if (test[ny][nx] == 0) {
				q.emplace(ny, nx);
				test[ny][nx] = 2;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (test[i][j] == 0)
				cnt++;
		}
	}

	return cnt;
}

void DFS(int cnt) {
	if (cnt == 3) {
		answer = std::max(answer, BFS());
		return;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (field[i][j] == 0) {
				field[i][j] = 1;
				DFS(cnt + 1);
				field[i][j] = 0;
			}
		}
	}
}

int main() {
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> field[i][j];
		}
	}
	
	DFS(0);

	std::cout << answer;
	return 0;
}