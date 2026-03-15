#include <bits/stdc++.h>

bool isDone;

int field[9][9];
std::vector<std::pair<int, int>> coords;	// (y, x)

bool isPossible(int y, int x, int num) {
	// row check
	for (int i = 0; i < 9; ++i) {
		if (field[y][i] == num)
			return false;
	}

	// column check
	for (int j = 0; j < 9; ++j) {
		if (field[j][x] == num)
			return false;
	}

	// 3*3 grid check
	int sx = (x / 3) * 3; int sy = (y / 3) * 3;
	for (int i = sy; i < sy + 3; ++i) {
		for (int j = sx; j < sx + 3; ++j) {
			if (field[i][j] == num)
				return false;
		}
	}

	return true;
}

void DFS(int cur) {
	if (isDone)
		return;

	if (cur == coords.size()) {
		isDone = true;

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				std::cout << field[i][j] << ' ';
			}
			std::cout << '\n';
		}
		return;
	}

	auto [y, x] = coords[cur];
	for (int num = 1; num <= 9; ++num) {
		if (isPossible(y, x, num)) {
			field[y][x] = num;
			DFS(cur + 1);
			field[y][x] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			std::cin >> field[i][j];
			if (field[i][j] == 0) coords.emplace_back(i, j);
		}
	}

	DFS(0);
	return 0;
}