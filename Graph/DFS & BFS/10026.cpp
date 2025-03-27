#include <iostream>
#include <cstring>
#define MAX 100

int N;
int cnt1;
int cnt2;

char field[MAX][MAX];
bool visited[MAX][MAX];

int x_dir[4] = { -1, 0, 1, 0 };
int y_dir[4] = { 0, -1, 0, 1 };

void DFS(int x, int y, char color) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int new_x = x + x_dir[i];
		int new_y = y + y_dir[i];

		if ((0 <= new_x && new_x < N) && (0 <= new_y && new_y < N)) {
			if (!visited[new_x][new_y] && field[new_x][new_y] == color) {
				DFS(new_x, new_y, color);
			}
		}
	}
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::string row;
		std::cin >> row;

		for (int j = 0; j < N; j++) {
			field[i][j] = row[j];
		}
	}

	// 정상인의 경우
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				DFS(i, j, field[i][j]);
				cnt1++;
			}
		}
	}

	memset(visited, false, sizeof(visited));

	// 적록색약인의 경우
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (field[i][j] == 'G')
				field[i][j] = 'R';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				DFS(i, j, field[i][j]);
				cnt2++;
			}
		}
	}

	std::cout << cnt1 << '\n' << cnt2 << std::endl;

	return 0;
}