#include <bits/stdc++.h>

// R*C 크기의 보드의 각 칸에 알파벳이 하나씩 써있으며, 현재 말은 좌측 상단에 놓여있음
// 말은 상하좌우로 인접한 네 칸 중 한 칸으로 이동할 수 있으며, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 함
// 이 때, 말이 최대한 몇 칸을 지날 수 있는지 구하는 문제

int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };

int R, C;
int answer;

char field[21][21];

// 알파벳 방문 여부
bool visited[26];

// 모든 경로를 끝까지 탐색하며 최대 칸 수를 갱신
// 재귀 호출이 끝나면 함수는 암묵적으로 상위 호출로 복귀
// visited를 호출 전/후로 원복하는 것만으로 백트래킹이 완료되어 별도 return이 불필요
// 즉, 조기 종료가 필요 없는 탐색이기 때문에 return 불필요
void DFS(int y, int x, int len) {
	answer = std::max(answer, len);

	for (int i = 0; i < 4; ++i) {
		int nx = x + dir_x[i];
		int ny = y + dir_y[i];

		if (nx < 1 || nx > C || ny < 1 || ny > R)
			continue;

		char next = field[ny][nx];

		// 알파벳의 방문 여부가 곧 특정 칸의 방문 여부이기 때문에 칸에 대한 방문 여부가 필요없음
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

	// 현재 위치(좌측 상단)의 칸도 카운트하여 시작
	visited[field[1][1] - 'A'] = true;
	DFS(1, 1, 1);
	
	std::cout << answer;
	return 0;
}