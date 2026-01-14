#include <iostream>
#include <vector>

// n×m 크기의 체스 판에 상대팀의 퀸, 나이트, 폰의 위치가 주어져 있음
// 퀸은 가로, 세로, 대각선으로 갈 수 있는 만큼 최대한 많이 이동을 할 수 있는데 만약 그 중간에 장애물이 있다면 이동을 할 수 없음
// 나이트는 중간에 장애물이 있더라도 이동을 할 수 있음
// 폰은 상대팀의 말을 잡을 수 없는, 장애물의 역할만을 수행함
// 이 때, 안전한 칸(그 곳에 자신의 말이 있어도 잡힐 가능성이 없는 칸)의 갯수를 구하는 문제

// 퀸이 이동할 수 있는 경로
int queen_x[8] = { 1,-1,0,0, 1,1,-1,-1 };
int queen_y[8] = { 0,0,1,-1, 1,-1,1,-1 };

// 나이트가 이동할 수 있는 경로
int knight_x[8] = { -2,-1,1,2,2,1,-1,-2 };
int knight_y[8] = { -1,-2,-2,-1,1,2,2,1 };

int board[1001][1001];
int answer;

int main() {
	int n, m;
	std::cin >> n >> m;

	int q;	std::cin >> q;
	while (q--) {
		int r, c;	std::cin >> r >> c;
		board[r][c] = 'Q';
	}

	int k;	std::cin >> k;
	while (k--) {
		int r, c;	std::cin >> r >> c;
		board[r][c] = 'K';
	}

	int p;	std::cin >> p;
	while (p--) {
		int r, c;	std::cin >> r >> c;
		board[r][c] = 'P';
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {

			// 현재 칸에 퀸이 놓여있는 경우
			if (board[i][j] == 'Q') {
				for (int k = 0; k < 8; ++k) {
					int nx = j + queen_x[k];
					int ny = i + queen_y[k];

					// 도달할 수 있는 칸을 모두 탐색
					// 만약 가능한 경로에 말들이 있다면 더 이상 이동 불가
					while (1 <= nx && nx <= m && 1 <= ny && ny <= n) {
						if (board[ny][nx] == 'Q' || board[ny][nx] == 'K' || board[ny][nx] == 'P')
							break;
					
						// 현재 도달한 칸 표시 후, 이동 가능한 다음 칸 갱신
						board[ny][nx]++;
						nx += queen_x[k];
						ny += queen_y[k];
					}
				}
			}

			// 현재 칸에 나이트가 놓여있는 경우
			else if (board[i][j] == 'K') {
				for (int k = 0; k < 8; ++k) {
					int nx = j + knight_x[k];
					int ny = i + knight_y[k];

					if (nx <= 0 || nx > m || ny <= 0 || ny > n)
						continue;

					// 이동 가능한 칸에 말들이 놓여져 있는 경우에는, 어차피 말을 놓을 수 없으므로 무시함
					if (board[ny][nx] == 'Q' || board[ny][nx] == 'K' || board[ny][nx] == 'P')
						continue;

					// 현재 도달한 칸 표시
					board[ny][nx]++;
				}
			}
		}
	}

	// 체스판의 값이 0인 칸, 즉 표시되지 않은 칸들이 안전한 칸
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (board[i][j] == 0)
				answer++;
		}
	}

	std::cout << answer;
	return 0;
}