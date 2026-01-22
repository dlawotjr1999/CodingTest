#include <iostream>
#include <cstring>
#include <queue>

// 빙산의 각 높이 정보들이 저장되어 있으며, 바닷물에 인접한 부분이 많을수록 빙산은 더 빨리 줄어듦
// 빙산의 각 부분에 해당되는 칸에 있는 높이는 일 년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어들며, 0보다 더 줄어들지 않음
// 한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간을 구하는 문제

const int MAX = 301;

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

int N, M;
int answer;

int field[MAX][MAX];	

// 각 시뮬레이션마다 사용될 임시 필드
int temp[MAX][MAX];

bool visited[MAX][MAX];

// BFS를 통해 빙산 덩어리 탐색
void BFS(int y, int x) {
	std::queue<std::pair<int, int>> q;
	q.emplace(y, x);
	visited[y][x] = true;
	
	while (!q.empty()) {
		auto [cur_y, cur_x] = q.front();
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int ny = cur_y + dir_y[k];
			int nx = cur_x + dir_x[k];

			if (ny <= 0 || ny > N || nx <= 0 || nx > M)
				continue;

			if (field[ny][nx] != 0 && !visited[ny][nx]) {
				visited[ny][nx] = true;
				q.emplace(ny, nx);
			}
		}
	}
}

int main() {
	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			std::cin >> field[i][j];
		}
	}

	while (true) {
		int cnt = 0;

		// 빙산의 높이를 구함
		// 현재 칸을 기준으로 사방에 0이 있는 칸의 갯수만큼 높이가 줄어듦
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				if (field[i][j] != 0) {
					int cur = field[i][j];

					for (int k = 0; k < 4; ++k) {
						int dx = j + dir_x[k];
						int dy = i + dir_y[k];

						if (dy <= 0 || dy > N || dx <= 0 || dx > M) 
							continue;
						
						// 높이가 0보다 클 때만 감소
						if (field[dy][dx] == 0 && cur > 0)
							cur--;
					}

					// 감소된 높이를 temp에 저장
					temp[i][j] = cur;
				}
			}
		}

		// 다음 시뮬레이션을 위해 현재 변형된 빙산의 정보가 담긴 temp의 정보를 field에 저장
		memcpy(field, temp, sizeof(field));

		// 현재 시점에서의 빙산 덩어리들의 갯수를 구함
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				if (field[i][j] != 0 && !visited[i][j]) {
					BFS(i, j);
					cnt++;
				}
			}
		}
		answer++;

		// 빙산이 두 덩어리 이상으로 분리되는 최초의 시점을 구함
		if (cnt >= 2) {
			std::cout << answer;
			return 0;
		}

		// 빙산이 다 녹을 때까지 두 덩어리 이상으로 분리되지 않는 경우
		// 즉 빙산이 모두 녹아서 존재하지 않는 경우에는 0 출력
		if (cnt == 0) {
			std::cout << 0;
			return 0;
		}

		memset(temp, 0, sizeof(temp));
		memset(visited, false, sizeof(visited));
	}
}