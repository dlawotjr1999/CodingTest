#include <iostream>

// M*N 크기의 보드를 잘라 8*8 크기의 체스판을 만들고자 함
// 체스판은 격자 간격으로 색이 다르게 칠해져야 하며, 이 규칙을 만족하지 않은 경우 그 칸을 다시 색칠해야 함
// 이 때, 다시 칠해야하는 칸의 최소 갯수를 구하는 문제

const int MAX = 51;
bool field[MAX][MAX];

int N, M;
int answer = 64;

int CountSquare(int x, int y) {
	int cnt1 = 0;	// 첫 칸이 검은색이라고 가정했을 때 다시 칠해야 하는 칸 수
	int cnt2 = 0;	// 첫 칸이 흰색이라고 가정했을 때 다시 칠해야 하는 칸 수

	// 체스판은 격자 간격으로 같은 색이 칠해짐
	// 즉, 각 x, y의 좌표의 합이 짝수인 경우에 같은 색이어야 함
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			bool cur = field[y + i][x + j];		// 현재 칸의 실제 색
			bool is_black = ((i + j) % 2 == 0);	// (i + j)가 짝수면 첫 칸과 같은 색이어야 하는 체스판 규칙

			// 첫 칸이 검정색이라 가정한 경우 cur과 is_black은 동일해야 함	
			// 즉 cur과 is_black이 다르다면 다시 칠해야 함
			if (cur != is_black)
				cnt1++;
			// 첫 칸이 흰색이라 가정한 경우 cur과 is_black은 달라야 함
			// 위의 경우와 반대
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
				field[i][j] = true;
			else
				field[i][j] = false;
		}
	}

	// 8*8 크기의 체스판을 만들기 위해 기존 판을 자르며, 그 경우를 모두 탐색
	// 이 중 가장 적은 횟수로 체스판을 다시 색칠하는 경우를 구함
	for (int i = 0; i <= N - 8; ++i) {
		for (int j = 0; j <= M - 8; ++j) {
			answer = std::min(answer, CountSquare(j, i));
		}
	}

	std::cout << answer;
	return 0;
}