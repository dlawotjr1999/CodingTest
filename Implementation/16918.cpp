#include <iostream>
#include <vector>

// 아래 문제를 구현
// https://www.acmicpc.net/problem/16918

constexpr int MAX = 200;
char field[MAX][MAX];
int boom_tick[MAX][MAX];

int x_dir[4] = { -1, 0, 1, 0 };
int y_dir[4] = { 0, -1, 0, 1 };

int R, C, N;
int tick;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> R >> C >> N;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cin >> field[i][j];
			if (field[i][j] == 'O') {

				// 폭탄은 설치 후 3초 뒤에 터지므로, 설치된 시점에서 그 위치의 폭탄이 터지는 시간을 저장
				boom_tick[i][j] = 3; 
			}
		}
	}

	// 1초 후에는 변화가 없으므로 2초부터 계산
	for (tick = 2; tick <= N; tick++) {

		// 짝수 시간 에는 폭탄이 설치되지 않은 모든 위치에 폭탄을 설치
		// 설치 시점(tick)을 기준으로 3초 후에 다시 폭탄이 터지므로 (tick + 3)을 저장
		if (tick % 2 == 0) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (field[i][j] == '.') {
						field[i][j] = 'O';
						boom_tick[i][j] = tick + 3;
					}
				}
			}
		}

		// 홀수 시간에는 폭탄이 폭발
		// 인접한 네 방향은 모두 폭탄이 폭발하며, 인접한 폭탄들은 즉시 폭발함; 연쇄 폭발이 존재하지 않음
		else {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (boom_tick[i][j] == tick) {
						for (int k = 0; k < 4; k++) {
							int nx = i + x_dir[k];
							int ny = j + y_dir[k];

							// 인접한 네 방향의 폭탄이 폭발; 이후 폭발 시간을 다시 0으로 초기화
							// 동시에 터질 폭탄은 건드리지 않기 위해 boom_tick을 검사해야 함
							if ((0 <= nx && nx < R) && (0 <= ny && ny < C) && boom_tick[nx][ny] != tick) {
								field[nx][ny] = '.';
								boom_tick[nx][ny] = 0;
							}
						}

						// 원래 위치의 폭탄 폭발 처리
						field[i][j] = '.';
						boom_tick[i][j] = 0;
					}
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cout << field[i][j];
		}
		std::cout << '\n';
	}

	return 0;
}
