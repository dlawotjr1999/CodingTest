#include <iostream>

// 캠핑장에서 집에 돌아가는 방법의 가짓수를 구하는 문제
// 캠핑장은 가장 왼쪽 아래에 있으며, 집은 오른쪽 위에 위치함
// 한 번 지나간 곳은 방문하지 않으며, T로 표시된 곳은 가지 못하는 곳

static constexpr int MAX = 6;

char field[MAX][MAX];
bool visited[MAX][MAX];

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

int R, C, K;
int answer;

void DFS(int y, int x, int dist) {
	// 가지치기 : 거리가 K를 넘으면 되돌아감
	if (dist > K)
		return;

	// K의 거리로 집에 도착하면 정답
	if ((y == 0 && x == C - 1) && dist == K) {
		answer++;
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int new_x = x + dir_x[i];
		int new_y = y + dir_y[i];

		if ((0 <= new_x && new_x < C) && (0 <= new_y && new_y < R)) {
			// 가지 못하는 곳은 건너뜀
			if (field[new_y][new_x] == 'T')
				continue;
			if (!visited[new_y][new_x]) {
				visited[new_y][new_x] = true;
				DFS(new_y, new_x, dist + 1);
				visited[new_y][new_x] = false;
			}
		}
	}
}

int main() {
	std::cin >> R >> C >> K;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			std::cin >> field[i][j];
		}
	}

	// 좌측 가장 하단에서 출발
	visited[R - 1][0] = true;
	DFS(R - 1, 0, 1);

	std::cout << answer;
	return 0;
}