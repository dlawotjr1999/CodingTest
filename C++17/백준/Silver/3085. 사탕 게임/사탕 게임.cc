#include <iostream>
#include <utility>

int N;

char board[50][50];
int answer;

int check_cnt() {
	int max_value = 0;

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

	for (int j = 1; j < N; ++j) {
		int cnt = 1;

		for (int i = 0; i < N; ++i) {
			if (board[i - 1][j] == board[i][j])
				cnt++;
			else {
				max_value = std::max(max_value, cnt);
				cnt = 1;
			}
		}
		max_value = std::max(max_value, cnt);
	}

	return max_value;
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (j + 1 < N && board[i][j] != board[i][j + 1]) {
				std::swap(board[i][j], board[i][j + 1]);
				answer = std::max(check_cnt(), answer);
				std::swap(board[i][j], board[i][j + 1]);
			}
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