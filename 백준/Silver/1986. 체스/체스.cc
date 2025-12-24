#include <iostream>
#include <vector>

int queen_x[8] = { 1,-1,0,0, 1,1,-1,-1 };
int queen_y[8] = { 0,0,1,-1, 1,-1,1,-1 };

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

	std::vector<int> coord;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (board[i][j] == 'Q') {
				for (int k = 0; k < 8; ++k) {
					int nx = j + queen_x[k];
					int ny = i + queen_y[k];

					while (1 <= nx && nx <= m && 1 <= ny && ny <= n) {
						if (board[ny][nx] == 'Q' || board[ny][nx] == 'K' || board[ny][nx] == 'P')
							break;
					
						board[ny][nx]++;
						nx += queen_x[k];
						ny += queen_y[k];
					}
				}
			}

			else if (board[i][j] == 'K') {
				for (int k = 0; k < 8; ++k) {
					int nx = j + knight_x[k];
					int ny = i + knight_y[k];

					if (nx <= 0 || nx > m || ny <= 0 || ny > n)
						continue;
					if (board[ny][nx] == 'Q' || board[ny][nx] == 'K' || board[ny][nx] == 'P')
						continue;

					board[ny][nx]++;
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (board[i][j] == 0)
				answer++;
		}
	}

	std::cout << answer;
	return 0;
}