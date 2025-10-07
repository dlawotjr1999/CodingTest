#include <bits/stdc++.h>

int answer;

char board[5][5];
bool selected[25];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

bool isConnected() {
	int cnt = 0;

	bool visited[5][5];
	bool temp[5][5];

	memset(visited, false, sizeof(visited));
	memset(temp, false, sizeof(temp));

	for (int i = 0; i < 25; ++i) {
		if (selected[i]) {
			int y = i / 5;
			int x = i % 5;
			temp[y][x] = true;
		}
	}

	std::queue<std::pair<int, int>> q;
	for (int i = 0; i < 25; ++i) {
		if (selected[i]) {
			int y = i / 5;
			int x = i % 5;
			q.emplace(y, x);
			visited[y][x] = true;
			break;
		}
	}

	while (!q.empty()) {
		auto [y, x] = q.front(); q.pop();
		cnt++;

		for (int i = 0; i < 4; ++i) {
			int ny = y + dir_y[i];
			int nx = x + dir_x[i];

			if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
				continue;
			if (!visited[ny][nx] && temp[ny][nx]) {
				visited[ny][nx] = true;
				q.emplace(ny, nx);
			}
		}
	}

	if (cnt == 7)
		return true;
	return false;
}

void DFS(int idx, int cnt) {
	if (cnt == 7) {
		if (isConnected()) {
			int s_cnt = 0;

			for (int i = 0; i < 25; ++i) {
				if (selected[i] && board[i / 5][i % 5] == 'S') {
					s_cnt++;
				}
			}

			if (s_cnt >= 4)
				answer++;
		}
		return;
	}

	for (int i = idx; i < 25; ++i) {
		if (selected[i])
			continue;
		selected[i] = true;
		DFS(i + 1, cnt + 1);
		selected[i] = false;
	}
}

int main() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			std::cin >> board[i][j];
		}
	}

	DFS(0, 0);

	std::cout << answer;
	return 0;
}