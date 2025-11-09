#include <iostream>

const int MAX = 51;
bool field[MAX][MAX];

int N, M;
int answer = 64;

int CountSquare(int x, int y) {
	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			bool cur = field[y + i][x + j];
			bool is_equal = ((i + j) % 2 == 0);

			if (cur != is_equal)
				cnt1++;
			else
				cnt2++;
		}
	}

	return std::min(cnt1, cnt2);
}

int main() {
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char c;	std::cin >> c;
			
			if (c == 'B')
				field[i][j] = 1;
			else
				field[i][j] = 0;
		}
	}

	for (int i = 0; i <= N - 8; ++i) {
		for (int j = 0; j <= M - 8; ++j) {
			answer = std::min(answer, CountSquare(j, i));
		}
	}

	std::cout << answer;
	return 0;
}