#include <iostream>
#include <vector>

// �Ʒ� ������ ����
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

				// ��ź�� ��ġ �� 3�� �ڿ� �����Ƿ�, ��ġ�� �������� �� ��ġ�� ��ź�� ������ �ð��� ����
				boom_tick[i][j] = 3; 
			}
		}
	}

	// 1�� �Ŀ��� ��ȭ�� �����Ƿ� 2�ʺ��� ���
	for (tick = 2; tick <= N; tick++) {

		// ¦�� �ð� ���� ��ź�� ��ġ���� ���� ��� ��ġ�� ��ź�� ��ġ
		// ��ġ ����(tick)�� �������� 3�� �Ŀ� �ٽ� ��ź�� �����Ƿ� (tick + 3)�� ����
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

		// Ȧ�� �ð����� ��ź�� ����
		// ������ �� ������ ��� ��ź�� �����ϸ�, ������ ��ź���� ��� ������; ���� ������ �������� ����
		else {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (boom_tick[i][j] == tick) {
						for (int k = 0; k < 4; k++) {
							int nx = i + x_dir[k];
							int ny = j + y_dir[k];

							// ������ �� ������ ��ź�� ����; ���� ���� �ð��� �ٽ� 0���� �ʱ�ȭ
							// ���ÿ� ���� ��ź�� �ǵ帮�� �ʱ� ���� boom_tick�� �˻��ؾ� ��
							if ((0 <= nx && nx < R) && (0 <= ny && ny < C) && boom_tick[nx][ny] != tick) {
								field[nx][ny] = '.';
								boom_tick[nx][ny] = 0;
							}
						}

						// ���� ��ġ�� ��ź ���� ó��
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
