#include <iostream>
#include <algorithm>

// N*M 크기의 직사각형 나무판을 통해 부메랑을 만들고자 함
// 부메랑은 항상 3칸을 차지하며 'ㄱ'자 모양을 회전시킨 모양들로만 만들 수 있음
// 부메랑의 각 칸에는 강도가 존재하며, 특히 부메랑의 중심이 되는 칸은 강도의 영향을 2배로 받음
// 나무 재료의 형태와 각 칸의 강도가 주어졌을 때, 만들 수 있는 부메랑들의 강도 합의 최댓값을 구하는 문제

int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };

int N, M;
int answer;

int board[6][6];
bool visited[6][6];

void DFS(int sum, int y, int x) {
	// 모든 칸을 탐색했을 경우, 즉 N행을 넘어간 경우에 최댓값 갱신
	if (y > N) {
		answer = std::max(answer, sum);
		return;
	}

	// 다음 칸을 탐색하며, 현재 행을 모두 탐색했을 경우 아래 행의 가장 왼쪽부터 탐색
	int ny = y;
	int nx = x + 1;
	if (nx > M) { nx = 1; ny++; }

	// 부메랑을 만들지 않고 그냥 넘어가는 경우
	DFS(sum, ny, nx);

	// 부메랑을 만들고자 하는 경우
	if (!visited[y][x]) {
		for (int i = 0; i < 4; ++i) {
			// 부메랑 날개의 방향들 계산
			// 가능한 조합은 (위, 오른쪽), (오른쪽, 아래), (아래, 왼쪽), (왼쪽, 위)
			// 즉 12시 방향부터 시계 방향으로 선언된 dir 배열을 통해 가능한 날개 조합의 좌표인 d1, d2 계산
			int dy_1 = y + dir_y[i];
			int dx_1 = x + dir_x[i];

			int dy_2 = y + dir_y[(i + 1) % 4];
			int dx_2 = x + dir_x[(i + 1) % 4];

			// 범위를 벗어나거나, 부매랑의 날개가 존재하는 칸을 이미 방문한 경우에는 무시
			if (dy_1 < 1 || dy_1 > N || dy_2 < 1 || dy_2 > N || dx_1 < 1 || dx_1 > M || dx_2 < 1 || dx_2 > M)
				continue;
			if (visited[dy_1][dx_1] || visited[dy_2][dx_2])
				continue;

			visited[dy_1][dx_1] = true; 
			visited[y][x] = true; 
			visited[dy_2][dx_2] = true;
            
			// 부메랑의 강도 계산 후 다음 칸 탐색
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