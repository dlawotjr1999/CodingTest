#include <iostream>

// 크기가 H × W인 배열 A와 두 정수 X와 Y가 있을 때, 크기가 (H + X) × (W + Y)인 배열 B는 배열 A와 배열 A를 아래로 X칸, 오른쪽으로 Y칸 이동시킨 배열을 겹쳐 만듦
// 배열 B의(i, j)에 들어있는 값은 아래 3개 중 하나이다.
// - (i, j)가 두 배열 모두에 포함되지 않으면, B_(i, j) = 0이다.
// - (i, j)가 두 배열 모두에 포함되면, B_(i, j) = A_(i, j) + A_(i - X, j - Y)이다.
// - (i, j)가 두 배열 중 하나에 포함되면, B_(i, j) = A_i, j 또는 A_(i - X, j - Y)이다.
// 이 때, 배열 B와 정수 X, Y가 주어졌을 때, 배열 A를 구하는 문제

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
			// i와 j가 모두 X, Y 이상일 경우, changed_ary에서 (X, Y)만큼 이동한 값을 빼는 방식으로 계산
		    // 즉, changed_ary 배열의 특정 구간에 해당하는 값에서 원래 값을 빼는 방식
			if (i >= X && j >= Y)
				ary[i][j] = changed_ary[i][j] - ary[i - X][j - Y];
			// X, Y보다 작은 경우에는 changed_ary의 값을 그대로 저장
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