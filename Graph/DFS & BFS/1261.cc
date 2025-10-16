#include <iostream>
#include <vector>
#include <deque>
#include <climits>

// N * M 크기의 미로에서 출발 지점(1,1)으로부터 (N, M)번 방으로 이동하고자 함
// 현재 지점에서 사방에 있는 방으로만 이동이 가능하며, 주변에 벽이 있는 경우 부숴서 이동할 수 있음
// 이 때, (N, M)번 방으로 이동하기 위해 최소 몇 개의 벽을 부숴야하는지 구하는 문제

int M, N;

int field[101][101];
int dist[101][101];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

// 0-1 그래프이기 때문에 deque을 이용하여 BFS 진행
// 1(벽)을 만나면 deque의 뒤에, 0(빈 방)을 만나면 deque의 앞에 삽입
// 다른 솔루션 : 벽(1)을 가중치로 간주하여, 0일 때와 1일 때를 나누어서 dijkstra 알고리즘을 통해 최단 경로를 구함 
void BFS(int y, int x) {
	std::deque<std::pair<int, int>> dq;
	dq.emplace_back(y, x);
	dist[y][x] = 0;

	while (!dq.empty()) {
		auto [cur_y, cur_x] = dq.front();
		dq.pop_front();

		for (int d = 0; d < 4; d++) {
			int ny = cur_y + dir_y[d];
			int nx = cur_x + dir_x[d];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N) 
				continue;

			int cost = dist[cur_y][cur_x] + field[ny][nx];
			if (cost < dist[ny][nx]) {
				dist[ny][nx] = cost;
				if (field[ny][nx] == 1)
					dq.emplace_back(ny, nx);
				else
					dq.emplace_front(ny, nx);
			}
		}
	}
}

int main() {
	std::cin >> M >> N;

	for (int i = 0; i < N; ++i) {
		std::string input;
		std::cin >> input;

		for (int j = 0; j < M; ++j) {
			field[i][j] = input[j] - '0';
			dist[i][j] = INT_MAX;
		}
	}

	BFS(0, 0);
	std::cout << dist[N - 1][M - 1];
	return 0;
}