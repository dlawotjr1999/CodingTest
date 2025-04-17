#include <iostream>
#define MAX 15

// N-Queen Probelm
// Âü°í : https://ko.wikipedia.org/wiki/%EC%97%AC%EB%8D%9F_%ED%80%B8_%EB%AC%B8%EC%A0%9C

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