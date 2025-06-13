#include <iostream>

// ũ�Ⱑ H �� W�� �迭 A�� �� ���� X�� Y�� ���� ��, ũ�Ⱑ (H + X) �� (W + Y)�� �迭 B�� �迭 A�� �迭 A�� �Ʒ��� Xĭ, ���������� Yĭ �̵���Ų �迭�� ���� ����
// �迭 B��(i, j)�� ����ִ� ���� �Ʒ� 3�� �� �ϳ��̴�.
// - (i, j)�� �� �迭 ��ο� ���Ե��� ������, B_(i, j) = 0�̴�.
// - (i, j)�� �� �迭 ��ο� ���ԵǸ�, B_(i, j) = A_(i, j) + A_(i - X, j - Y)�̴�.
// - (i, j)�� �� �迭 �� �ϳ��� ���ԵǸ�, B_(i, j) = A_i, j �Ǵ� A_(i - X, j - Y)�̴�.
// �� ��, �迭 B�� ���� X, Y�� �־����� ��, �迭 A�� ���ϴ� ����

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
			// i�� j�� ��� X, Y �̻��� ���, changed_ary���� (X, Y)��ŭ �̵��� ���� ���� ������� ���
		    // ��, changed_ary �迭�� Ư�� ������ �ش��ϴ� ������ ���� ���� ���� ���
			if (i >= X && j >= Y)
				ary[i][j] = changed_ary[i][j] - ary[i - X][j - Y];
			// X, Y���� ���� ��쿡�� changed_ary�� ���� �״�� ����
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