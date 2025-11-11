#include <iostream>

int field[19][19];

bool isInside(int x, int y) {
	return ((0 <= x && x < 19) && (0 <= y && y < 19));
}

bool RowCheck(int x, int y) {
	if (isInside(x, y - 1) && field[x][y] == field[x][y - 1]) return false;
	for (int i = 0; i < 5; ++i) {
		if (!isInside(x, y + i) || field[x][y] != field[x][y + i]) return false;
	}
	if (isInside(x, y + 5) && field[x][y] == field[x][y + 5]) return false;
	return true;
}

bool ColumnCheck(int x, int y) {
	if (isInside(x - 1, y) && field[x][y] == field[x - 1][y]) return false;
	for (int i = 0; i < 5; ++i) {
		if (!isInside(x + i, y) || field[x][y] != field[x + i][y]) return false;
	}
	if (isInside(x + 5, y) && field[x][y] == field[x + 5][y]) return false;
	return true;
}

bool DiagonalCheck(int x, int y) {
	if (isInside(x - 1, y - 1) && field[x][y] == field[x - 1][y - 1]) return false;
	for (int i = 0; i < 5; ++i) {
		if (!isInside(x + i, y + i) || field[x][y] != field[x + i][y + i]) return false;
	}
	if (isInside(x + 5, y + 5) && field[x][y] == field[x + 5][y + 5]) return false;
	return true;
}

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
			if (RowCheck(i, j) || ColumnCheck(i, j) || DiagonalCheck(i, j) || DiagonalCheck2(i, j)) {
				std::cout << field[i][j] << '\n';
				std::cout << i + 1 << ' ' << j + 1;
				return 0;
			}

		}
	}
	std::cout << 0;
}