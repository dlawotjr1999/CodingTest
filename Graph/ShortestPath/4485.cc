#include <bits/stdc++.h>

// 현재 (0,0)의 위치에서 가장 오른쪽 아래 칸인 (N-1, N-1)까지 이동하고자 하며, 상하좌우로만 이동할 수 있음
// 각 칸에는 도둑루피가 존재하며, 이 칸을 지나면 해당 도둑루피만큼의 소지금을 잃게 됨
// 잃는 금액을 최소로 하여 가장 오른쪽 아래 칸까지 이동하고자 할 때, 잃을 수밖에 없는 최소 금액을 구하는 문제

int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };

const int MAX = 125;
const int INF = 100000;

// 좌표와 그 칸의 도둑루피에 해당하는 구조체 선언
// 격자 그래프의 최단 거리 알고리즘이기 때문에 따로 선언
struct info {
	int cost, x, y;

	// 최소 힙을 사용하기 위해 오버로딩 수행
	// 기본적으로 STL의 우선순위 큐는 최대 힙 기반이기 때문
	// cost가 작은 노드가 top에 오도록 비교 기준을 반대로 정의
	bool operator<(const info& other) const {
		return cost > other.cost;
	}
};

int N;
int field[MAX][MAX];

// Dijkstra 알고리즘으로 잃는 최소 소지금 계산
int Dijkstra() {
	// 각 좌표에 해당하는 거리(도둑루피) 저장
	std::vector<std::vector<int>> dist(N, std::vector<int>(N, INF));

	// info 구조체를 사용하며, 도둑루피(cost)를 기준으로 하는 최소 힙사용
	std::priority_queue<info> pq;
	pq.push({field[0][0], 0, 0});
	dist[0][0] = field[0][0];

	while (!pq.empty()) {
		auto [cost, x, y] = pq.top();
		pq.pop();

		if (cost > dist[y][x])
			continue;

		// 상하좌우로 이동하면서 소모되는 금액 갱신
		for (int i = 0; i < 4; ++i) {
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;

			int next_cost = cost + field[ny][nx];

			if (next_cost < dist[ny][nx]) {
				dist[ny][nx] = next_cost;
				pq.push({ next_cost, nx, ny });
			}
		}
	}

	// (N-1, N-1) 좌표까지 소모된 금액 반환
	return dist[N - 1][N - 1];
}

int main() {
	int seq = 1;

	while (true) {
		std::cin >> N;

		// N이 0이면 종료
		if (N == 0)
			break;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				std::cin >> field[i][j];
			}
		}
		printf("Problem %d: %d\n", seq, Dijkstra());
		
		memset(field, 0, sizeof(field));
		seq++;
	}

	return 0;
}