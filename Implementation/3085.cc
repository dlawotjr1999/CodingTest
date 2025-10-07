#include <iostream>
#include <utility>

// N * N 크기에 사탕이 채워져 있을 때, 다음과 같은 규칙을 수행함
// 1. 사탕의 색이 인접한 두 칸을 고름
// 2. 그 다음 고른 칸에 들어있는 사탕을 서로 교환
// 3. 이후 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹음
// 이 때 먹을 수 있는 사탕의 최대 갯수를 구하는 문제 

int N;

char board[50][50];
int answer;

int check_cnt() {
	int max_value = 0;

	// 각 행마다 연속된 동일 색 사탕의 최대 개수를 계산
	// 한 행을 왼쪽부터 오른쪽으로 탐색하면서 같은 색이 이어지면 cnt 증가, 다른 색을 만나면 cnt를 초기화
	// 행의 끝까지 탐색하면서 매 구간마다 최댓값을 갱신
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

	// 각 열마다 연속된 동일 색 사탕의 최대 개수를 계산
	// 위에서 아래로 탐색하며 같은 방식으로 연속 구간을 확인
	// 행과 동일하게, 다른 색을 만나면 cnt를 초기화하고 최댓값을 갱신
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

	// 행과 열에서 구한 최댓값 중 더 큰 값을 반환
	return max_value;
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> board[i][j];
		}
	}

	// 반복문을 통해 가능한 교환을 모두 진행하기 때문에 위나 아래, 왼쪽이나 오른쪽 교환 중 하나만 진행하면 됨
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			// 오른쪽 칸과 교환 진행 후에 먹을 수 있는 사탕의 갯수를 구한 뒤 원상복구
			if (j + 1 < N && board[i][j] != board[i][j + 1]) {
				std::swap(board[i][j], board[i][j + 1]);
				answer = std::max(check_cnt(), answer);
				std::swap(board[i][j], board[i][j + 1]);
			}
			// 왼쪽 칸과 교환 진행 후에 먹을 수 있는 사탕의 갯수를 구한 뒤 원상복구
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