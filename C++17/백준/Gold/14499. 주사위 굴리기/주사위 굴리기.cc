#include <iostream>

int dice[6];

int dir_x[4] = { 1,-1,0,0 };
int dir_y[4] = { 0,0,-1,1 };

int field[20][20];

void Roll(int dir) {
    int temp;

    if (dir == 1) {
        temp = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[2];
        dice[2] = temp;
    }
    else if (dir == 2) {
        temp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[3];
        dice[3] = temp;
    }
    else if (dir == 3) {
        temp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[1];
        dice[1] = temp;
    }
    else if (dir == 4) {
        temp = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[4];
        dice[4] = temp;
    }
}

int main() {
	int N, M, y, x, K;
	std::cin >> N >> M >> y >> x >> K;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> field[i][j];
		}
	}

	for (int i = 0; i < K; ++i) {
		int dir;
		std::cin >> dir;

		int nx = x + dir_x[dir - 1];
		int ny = y + dir_y[dir - 1];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;
        
        Roll(dir);

		if (field[ny][nx] == 0) {
			field[ny][nx] = dice[5];
		}
		else {
			dice[5] = field[ny][nx];
			field[ny][nx] = 0;
		}
		x = nx, y = ny;

		std::cout << dice[0] << '\n';
	}

	return 0;
}