#include <iostream>
#include <cmath>

// Z���·� 2���� �迭�� Ž���� �� (r,c)�� �� ��°�� �湮�ϴ��� ���ϴ� ����
// ���� : https://www.acmicpc.net/problem/1074

int N, r, c;
int answer;

void Z_Search(int size, int col, int row) {
	// Ÿ�� ��ǥ�� ��� ��� �� ����
	if (row == r && col == c) {
		std::cout << answer << '\n';
		return;
	}

	// �迭 Ž��
	if ((col <= c && c < col + size) && (row <= r && r < row + size)) {
		Z_Search(size / 2, col, row);				// 1��и� Ž��
		Z_Search(size / 2, col + size / 2, row);	// 2��и� Ž��
		Z_Search(size / 2, col, row + size / 2);	// 3��и� Ž��
		Z_Search(size / 2, col + size / 2, row + size / 2);	// 4��и� Ž��
	}

	// (r,c)�� ���� ��и鿡 ���� ��� Ž���� �ʿ䰡 �����Ƿ� size*size��ŭ ������
	// �� ��ŭ�� Ž���� �̹� ����Ǿ��ٰ� ����� �� �ֱ� ���� 
	else {
		answer += size * size;
	}
}

int main() {
	std::cin >> N >> r >> c;

	// (1 << N) �������� (2^N * 2^N) ũ���� �ʵ� ����
	Z_Search((1 << N), 0, 0);

	return 0;
}