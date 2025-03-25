#include <iostream>
#include <cmath>

int N, r, c;
int answer;

void Z_Search(int size, int col, int row) {
	if (row == r && col == c) {
		std::cout << answer << '\n';
		return;
	}

	if ((col <= c && c < col + size) && (row <= r && r < row + size)) {
		Z_Search(size / 2, col, row);
		Z_Search(size / 2, col + size / 2, row);
		Z_Search(size / 2, col, row + size / 2);
		Z_Search(size / 2, col + size / 2, row + size / 2);
	}
	else {
		answer += size * size;
	}
}

int main() {
	std::cin >> N >> r >> c;
	Z_Search((1 << N), 0, 0);

	return 0;
}