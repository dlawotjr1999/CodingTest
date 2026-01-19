#include <bits/stdc++.h>

// N*N 크기의 종이 각 칸에는 - 1, 0, 1 중 하나가 저장되어 있음
// 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용하며, 그렇지 않은 경우 같은 크기의 종이 9개로 자르는 과정을 반복함
// 이 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 각각 구하는 문제

int ans1, ans2, ans3;
std::vector<std::vector<int>> field;

void CheckPaper(int x, int y, int n) {
	// 현재 종이의 가장 왼쪽 상단 부분을 기준으로 삼음
	int base = field[y][x];
	bool isOk = true;

	// 현재 종이의 각 칸을 탐색
	for (int i = y; i < y + n; ++i) {
		for (int j = x; j < x + n; ++j) {
			if (base != field[i][j]) {
				isOk = false;
				break;
			}
		}

		if (!isOk)
			break;
	}

	// 현재 종이의 모든 부분이 동일하다면 계산 진행 후 종료
	if (isOk) {
		if (base == -1)
			ans1++;
		else if (base == 0)
			ans2++;
		else if (base == 1)
			ans3++;
		return;
	}
	// 모든 부분이 동일하지 않다면 9등분으로 나누어 다시 진행
	else {
		int size = n / 3;

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				CheckPaper(x + j*size, y + i*size, n/3);
			}
		}
	}
}

int main() {
	int N; std::cin >> N;
	field.resize(N, std::vector<int>(N));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> field[i][j];
		}
	}

	// 최초 시작 부분과 종이의 크기를 인자로 하여 탐색 진행
	CheckPaper(0, 0, N);

	std::cout << ans1 << '\n' << ans2 << '\n' << ans3;
	return 0;
}