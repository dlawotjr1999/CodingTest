#include <iostream>
#define MAX 50

// 0�� 1�θ� �̷���� ��� A�� ��� B�� ���� ��, ��� A�� ��� B�� �ٲٴµ� �ʿ��� ������ Ƚ���� �ּڰ��� ���ϴ� ����
// ����� ��ȯ�ϴ� ������ � 3��3ũ���� �κ� ��Ŀ� �ִ� ��� ���Ҹ� ������ ��

int A[MAX][MAX];
int B[MAX][MAX];

int cnt;

// 3 x 3 ũ�⸸ŭ ����� ������
void Reverse(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (A[i][j] == 1)
				A[i][j] = 0;
			else
				A[i][j] = 1;
		}
	}
}

int main() {
	bool flag = true;

	int N, M;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::string row;
		std::cin >> row;

		for (int j = 0; j < M; j++) {
			A[i][j] = row[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		std::string row;
		std::cin >> row;

		for (int j = 0; j < M; j++) {
			B[i][j] = row[j] - '0';
		}
	}

	// �� ���ҿ��� 3 x 3 ����� ������ ���̱� ������ ��ü ����� �ε����� ����Ͽ� (N - 2)�� (M - 2)��ŭ Ȯ���Ͽ� ������ ������
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (A[i][j] != B[i][j]) {
				Reverse(i, j);
				cnt++;
			}
		}
	}

	// ���� �� �ϳ��� �ٸ� ���Ұ� ������ A�� B�� ��ȯ�� �� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				flag = false;
				break;
			}
		}
	}

	if (flag)
		std::cout << cnt;
	else
		std::cout << -1;
	
	return 0;
}