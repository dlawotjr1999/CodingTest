#include <iostream>
#include <utility>

// N * N ũ�⿡ ������ ä���� ���� ��, ������ ���� ��Ģ�� ������
// 1. ������ ���� ������ �� ĭ�� ��
// 2. �� ���� �� ĭ�� ����ִ� ������ ���� ��ȯ
// 3. ���� ��� ���� ������ �̷���� �ִ� ���� �� ���� �κ�(�� �Ǵ� ��)�� �� ���� �� ������ ��� ����
// �� �� ���� �� �ִ� ������ �ִ� ������ ���ϴ� ���� 

int N;

char board[50][50];
int answer;

int check_cnt() {
	int max_value = 0;

	// �� �ึ�� ���ӵ� ���� �� ������ �ִ� ������ ���
	// �� ���� ���ʺ��� ���������� Ž���ϸ鼭 ���� ���� �̾����� cnt ����, �ٸ� ���� ������ cnt�� �ʱ�ȭ
	// ���� ������ Ž���ϸ鼭 �� �������� �ִ��� ����
	for (int i = 0; i < N; ++i) {
		int cnt = 1;

		for (int j = 1; j < N; ++j) {
			if (board[i][j - 1] == board[i][j])
				cnt++;
			else {
				max_value = std::max(max_value, cnt);
				cnt = 1;
			}
		}
		max_value = std::max(max_value, cnt);
	}

	// �� ������ ���ӵ� ���� �� ������ �ִ� ������ ���
	// ������ �Ʒ��� Ž���ϸ� ���� ������� ���� ������ Ȯ��
	// ��� �����ϰ�, �ٸ� ���� ������ cnt�� �ʱ�ȭ�ϰ� �ִ��� ����
	for (int j = 0; j < N; ++j) {
		int cnt = 1;

		for (int i = 1; i < N; ++i) {
			if (board[i - 1][j] == board[i][j])
				cnt++;
			else {
				max_value = std::max(max_value, cnt);
				cnt = 1;
			}
		}
		max_value = std::max(max_value, cnt);
	}

	// ��� ������ ���� �ִ� �� �� ū ���� ��ȯ
	return max_value;
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> board[i][j];
		}
	}

	// �ݺ����� ���� ������ ��ȯ�� ��� �����ϱ� ������ ���� �Ʒ�, �����̳� ������ ��ȯ �� �ϳ��� �����ϸ� ��
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			// ������ ĭ�� ��ȯ ���� �Ŀ� ���� �� �ִ� ������ ������ ���� �� ���󺹱�
			if (j + 1 < N && board[i][j] != board[i][j + 1]) {
				std::swap(board[i][j], board[i][j + 1]);
				answer = std::max(check_cnt(), answer);
				std::swap(board[i][j], board[i][j + 1]);
			}
			// ���� ĭ�� ��ȯ ���� �Ŀ� ���� �� �ִ� ������ ������ ���� �� ���󺹱�
			if (i + 1 < N && board[i][j] != board[i + 1][j]) {
				std::swap(board[i + 1][j], board[i][j]);
				answer = std::max(check_cnt(), answer);
				std::swap(board[i + 1][j], board[i][j]);
			}
		}
	}

	std::cout << answer;
	return 0;
}