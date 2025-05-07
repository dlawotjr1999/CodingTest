#include <iostream>

constexpr int MAX = 300;
int H, W, X, Y;

int ary[MAX][MAX];
int changed_ary[MAX][MAX];

int main() {
	std::cin >> H >> W >> X >> Y;

	for (int i = 0; i < H + X; i++) {
		for (int j = 0; j < W + Y; j++) {
			std::cin >> changed_ary[i][j];
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (i >= X && j >= Y)
				ary[i][j] = changed_ary[i][j] - ary[i - X][j - Y];
			else
				ary[i][j] = changed_ary[i][j];
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			std::cout << ary[i][j] << " ";
		}
		std::cout << '\n';
	}
	return 0;
}