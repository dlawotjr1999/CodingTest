#include <bits/stdc++.h>

// 25명의 여학생들로 이루어진 반에서 '소문난 칠공주'를 결성하고자 하며, 그 규칙은 아래와 같음
// 1. 7명의 여학생들로 구성되어야 하며, 7명의 자리는 서로 가로나 세로로 반드시 인접해 있어야 한다.
// 2. 이다솜파의 학생들로만 구성될 필요는 없지만, 7명의 학생 중 이다솜파의 학생이 적어도 4명 이상은 반드시 포함되어 있어야 함
// 이다솜파(S)와 임도연파(Y)로 자리 배치도가 주어질 때, '소문난 칠공주'를 결성할 수 있는 경우의 수를 구하는 문제

// 일반적인 미로 찾기, 섬의 갯수 탐색 문제와는 달리 이 문제는 조합을 찾고, 그 조합이 연결되어 있는 방식으로 접근해야 함
// 전자는 이미 연결되어 있는 요소들에 대해 연결성을 탐색하는 것이며, 후자는 연결이 보장이 되어 있지 않기 때문에 조합 탐색 후 연결성을 검증해야 함

int answer;

char board[5][5];
bool selected[25];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

bool isConnected() {
	int cnt = 0;

	// 선택된 7명에 대해 연결 여부를 판단하기 위해 BFS 사용
	// 7명의 조합을 temp에 복사하여 연결 여부 판단
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

	// 가장 먼저 선택된 사람을 시작점으로 삼음
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

	// BFS로 7명이 모두 연결되어 있음을 확인하면 true 반환
	if (cnt == 7)
		return true;
	return false;
}

// 백트래킹을 통해 7명의 조합을 탐색한 후, 그 조합이 모두 연결되어 있는지를 확인함
void DFS(int idx, int cnt) {
	if (cnt == 7) {
		if (isConnected()) {
			int s_cnt = 0;

			// 선택된 7명에 대해 자리 배치도에서 S에 해당하면 S의 갯수를 증가시킴
			// S가 4명 이상이면 정답에 부합함
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

