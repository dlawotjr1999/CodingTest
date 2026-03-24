#include <bits/stdc++.h>

int K;
int N;
int x, y;

int field[128][128];
int cnt;

bool hasNoHole(int x, int y, int size) {
	for (int i = y; i < y + size; ++i) {
		for (int j = x; j < x + size; ++j) {
			if (field[i][j] != 0)
				return false;
		}
	}

	return true;
}

void MBC(int x, int y, int size) {
	if (size == 1)
		return;
	
	size /= 2;
	cnt++;

	if (hasNoHole(x, y, size)) field[y + size - 1][x + size - 1] = cnt;
	if (hasNoHole(x + size, y, size)) field[y + size - 1][x + size] = cnt;
	if (hasNoHole(x, y + size, size)) field[y + size][x + size - 1] = cnt;
	if (hasNoHole(x + size, y + size, size)) field[y + size][x + size] = cnt;

	MBC(x, y, size);
	MBC(x + size, y, size);
	MBC(x, y + size, size);
	MBC(x + size, y + size, size);
}

int main() {
	std::cin >> K;
	std::cin >> x >> y;

	field[y - 1][x - 1] = -1;
	N = 1 << K;

	MBC(0, 0, N);

	for (int i = (N - 1); i >= 0; --i) {
		for (int j = 0; j < N; ++j) {
			std::cout << field[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}