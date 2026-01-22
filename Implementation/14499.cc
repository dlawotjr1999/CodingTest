#include <iostream>

// 아래 문제를 구현
// https://www.acmicpc.net/problem/14499


// 주사위 표현
// 0 : 윗면, 1 : 북쪽면, 2 : 동쪽면, 3 : 서쪽면, 4 : 남쪽면, 5 : 아랫면
// 문제에 제시된 그림 기준으로 1, 2, 3, 4, 5, 6
int dice[6];

int dir_x[4] = { 1,-1,0,0 };
int dir_y[4] = { 0,0,-1,1 };

int field[20][20];

// 주사위를 굴리는 함수
void Roll(int dir) {
    int temp;

    // 동쪽 이동
    // 동쪽면이 바닥으로, 윗면이 동쪽으로 이동
    // 연산은 윗면 -> 서쪽면 -> 아랫면 -> 동쪽면으로 진행
    if (dir == 1) {
        temp = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[2];
        dice[2] = temp;
    }

    // 서쪽 이동
    // 서쪽면이 바닥으로, 윗면이 서쪽으로 이동
    // 연산은 동쪽면 -> 아랫면 -> 서쪽면 -> 윗면으로 진행
    else if (dir == 2) {
        temp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[3];
        dice[3] = temp;
    }

    // 북쪽 이동
    // 북쪽면은 바닥으로, 윗면이 북쪽으로 이동
    // 연산은 남쪽면 -> 바닥면 -> 북쪽면 -> 윗면으로 진행
    else if (dir == 3) {
        temp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[1];
        dice[1] = temp;
    }

    // 남쪽 이동
    // 남쪽면은 바닥으로, 윗면이 남쪼으로 이동
    // 연산은 윗면 -> 북쪽면 -> 바닥면 -> 남쪽면으로 진행
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

        // 이동한 칸의 숫자가 0이면 바닥면에 쓰여있는 숫자가 복사됨
		if (field[ny][nx] == 0) {
			field[ny][nx] = dice[5];
		}

        // 0이 아닌 경우엔 칸에 있는 수가 주사위 바닥면에 복사된 후, 칸에 있는 숫자는 0이 됨
		else {
			dice[5] = field[ny][nx];
			field[ny][nx] = 0;
		}

        // 현재 위치로 갱신
		x = nx, y = ny;

		std::cout << dice[0] << '\n';
	}

	return 0;
}