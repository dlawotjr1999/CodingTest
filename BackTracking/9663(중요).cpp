#include <iostream>
#define MAX 15

// N-Queen Probelm
// 참고 : https://ko.wikipedia.org/wiki/%EC%97%AC%EB%8D%9F_%ED%80%B8_%EB%AC%B8%EC%A0%9C

int N;
int answer;
int field[MAX];

bool Promising(int row) {
	for (int i = 0; i < row; i++) {
		// 같은 열에 있거나 대각선에 위치하면 퀸을 놓을 수 없음
		if (field[row] == field[i] || row - i == std::abs(field[row] - field[i]))
			return false;
	}
	return true;
}

void DFS(int row) {
	// 판을 모두 탐색했으면, 즉 모든 행까지의 탐색을 완료했으면 정답
	if (row == N) {
		answer++;
		return;
	}

	// 현재 행에 퀸을 배치
	for (int col = 0; col < N; col++) {
		// row번째 행, col번째 열에 퀸 배치
		field[row] = col;

		// 만약 유망한 경우, 즉 퀸을 놓을 수 있는 경우의 위치에서 다음 행을 탐색
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