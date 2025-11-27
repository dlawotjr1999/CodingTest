#include <bits/stdc++.h>

// N*N 크기의 표에 있는 숫자들로 (x1, y1)부터 (x2, y2)까지의 합을 구하는 문제
// (x1, y1)은 (1, 1)부터 (x1, y1)까지 x1*y1 크기의 구간을 의미함

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;	
	std::cin >> N >> M;
	
	std::vector<std::vector<int>> field(N + 1, std::vector<int>(N + 1));
	std::vector<std::vector<int>> sum(N + 1, std::vector<int>(N + 1, 0));

	// 2차원 누적합 계산
	// sum[i][j] = (1,1) ~ (i,j)까지의 구간 합
	// sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + field[i][j]
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			std::cin >> field[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + field[i][j];
		}
	}

	// 직사각형 (x1, y1) ~ (x2, y2)의 구간합을 구함
    // sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] (포함-배제 원리)
	for (int i = 0; i < M; ++i) {
		int x1, x2, y1, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;

		int result = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
		std::cout << result << '\n';
	}

	return 0;
}