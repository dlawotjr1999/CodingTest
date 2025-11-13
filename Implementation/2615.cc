#include <iostream>

// 특정 상태의 오목판이 주어졌을 때, 어떤 색의 돌이 이겼는지 구하는 문제
// 단 6목은 이긴 것이 아니며, 검은색과 흰색이 동시에 이기거나 검은색 또는 흰색이 두 군데 이상에서 동시에 이기는 경우는 존재하지 않음

int field[19][19];

bool isInside(int x, int y) {
	return ((0 <= x && x < 19) && (0 <= y && y < 19));
}

// 행 체크
bool RowCheck(int x, int y) {
	// 현재 돌이 가장 왼쪽에 있는 돌인지 판별
	// 즉 현재 돌의 왼쪽에 돌이 있는지를 판별함
	if (isInside(x, y - 1) && field[x][y] == field[x][y - 1]) return false;

	// 돌이 연속으로 5개가 놓여있는지를 판별
	for (int i = 0; i < 5; ++i) {
		if (!isInside(x, y + i) || field[x][y] != field[x][y + i]) return false;
	}

	// 가장 왼쪽에 있는 돌부터 판별을 시작한 경우, 여섯 번째에 위치한 돌과 같은 색인지 판별
	if (isInside(x, y + 5) && field[x][y] == field[x][y + 5]) return false;

	// 위 세 가지의 조건을 모두 통과한 경우만 오목으로 인정됨
	return true;
}

// 열 체크
bool ColumnCheck(int x, int y) {
	if (isInside(x - 1, y) && field[x][y] == field[x - 1][y]) return false;
	for (int i = 0; i < 5; ++i) {
		if (!isInside(x + i, y) || field[x][y] != field[x + i][y]) return false;
	}
	if (isInside(x + 5, y) && field[x][y] == field[x + 5][y]) return false;
	return true;
}

// 대각선(왼쪽 위에서 오른쪽 아래 방향) 체크
bool DiagonalCheck(int x, int y) {
	if (isInside(x - 1, y - 1) && field[x][y] == field[x - 1][y - 1]) return false;
	for (int i = 0; i < 5; ++i) {
		if (!isInside(x + i, y + i) || field[x][y] != field[x + i][y + i]) return false;
	}
	if (isInside(x + 5, y + 5) && field[x][y] == field[x + 5][y + 5]) return false;
	return true;
}

// 대각선(왼쪽 아래에서 오른쪽 위 방향) 체크
bool DiagonalCheck2(int x, int y) {
	if (isInside(x + 1, y - 1) && field[x][y] == field[x + 1][y - 1]) return false;
	for (int i = 0; i < 5; ++i) {
		if (!isInside(x - i, y + i) || field[x][y] != field[x - i][y + i]) return false;
	}
	if (isInside(x - 5, y + 5) && field[x][y] == field[x - 5][y + 5]) return false;
	return true;
}

int main() {
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			std::cin >> field[i][j];
		}
	}

	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			if (field[i][j] == 0)
				continue;

			// 이긴 돌의 색을 출력하며, 그 아래에는 연속된 다섯 개의 바둑알 중에서 가장 왼쪽에 있는 바둑알의 (x,y)좌표를 출력함
			if (RowCheck(i, j) || ColumnCheck(i, j) || DiagonalCheck(i, j) || DiagonalCheck2(i, j)) {
				std::cout << field[i][j] << '\n';
				std::cout << i + 1 << ' ' << j + 1;
				return 0;
			}

		}
	}
	std::cout << 0;
}