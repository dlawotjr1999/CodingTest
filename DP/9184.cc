#include <bits/stdc++.h>

// memoization 배열
int DP[21][21][21];

// 문제에 구현된 함수
// 연산 횟수를 비약적으로 줄이기 위해 memoization 활용(중복 계산 제거)
// 일반 재귀 방식을 사용하면 지수 시간이 소요되지만(약 O(4^n)), memoization을 활용하면 상수 시간이 소요됨(O(21^3))
int W(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	else if (a > 20 || b > 20 || c > 20)
		return W(20, 20, 20);

	// 배열에 이미 값이 존재하면 기존 값 return
	else if (DP[a][b][c] != 0)
		return DP[a][b][c];

	// 재귀 연산마다 계산된 값들을 배열에 기록
	else if (a < b && b < c)
		return DP[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);

	else
		return DP[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
}

int main() {
	while (true) {
		int a, b, c;
		std::cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
			break;

		printf("w(%d, %d, %d) = %d\n", a, b, c, W(a, b, c));
	}

	return 0;
}