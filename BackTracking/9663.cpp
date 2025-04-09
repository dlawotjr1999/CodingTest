#include <iostream>
#define MAX 15

int N;
int answer;
int field[MAX];

bool Promising(int row) {
	for (int i = 0; i < row; i++) {
		if (field[row] == field[i] || row - i == std::abs(field[row] - field[i]))
			return false;
	}
	return true;
}

void DFS(int row) {
	if (row == N) {
		answer++;
		return;
	}

	for (int col = 0; col < N; col++) {
		field[row] = col;

		if (Promising(row))
			DFS(row + 1);
	}
}

int main() {
	std::cin >> N;

	DFS(0);

	std::cout << answer;
	return 0;
}