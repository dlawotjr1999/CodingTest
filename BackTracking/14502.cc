#include <bits/stdc++.h>

// 연구소에서 바이러스의 확산을 막기 위해 벽을 세우려고 하며, 3개의 벽을 새로 세움으로써 확산을 막으려고 함
// 바이러스는 상하좌우 인접한 칸으로 퍼져나갈 수 있으며, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 영역을 의미함
// 이 때, 얻을 수 있는 안전 영역(바이러스가 퍼지지 않은 영역)의 크기를 구하는 문제

int N, M;
int answer = 0;

int field[9][9];
int test[9][9];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

int BFS() {
	// 시뮬레이션을 진행할 test에 데이터 복사
	std::memcpy(test, field, sizeof(field));
	std::queue<std::pair<int, int>> q;
	
	// 현재 바이러스가 있는 지점으로부터 BFS 일괄 진행
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

	// 안전 영역의 크기 계산
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (test[i][j] == 0)
				cnt++;
		}
	}

	return cnt;
}

// Backtracking을 통해 벽을 세울 위치를 선정
void DFS(int cnt) {
	// 3개의 벽을 세우면 바이러스 전염 시뮬레이션
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