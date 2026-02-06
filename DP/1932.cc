#include <bits/stdc++.h>

// 정수로 이루어진 삼각형이 존재할 때, 맨 위층부터 시작하여 아래에 있는 수 중 하나를 선택하여 아래로 내려올 수 있음
// 이 때, 이제까지 선택된 수의 합이 최대가 되는 경로에 있는 수의 합을 구하는 문제

int DP[501][501];

int main() {
	int n; std::cin >> n;

	// 정수 삼각형 구성
	std::vector<std::vector<int>> triangle(n + 1);
	for (int i = 1; i <= n; ++i) {
		triangle[i].resize(i + 1);

		for (int j = 1; j <= i; ++j) {
			std::cin >> triangle[i][j];
		}
	}

	// DP 첫부분은 삼각형의 꼭대기에 있는 값
	DP[1][1] = triangle[1][1];
	for (int i = 1; i <= n; ++i) {
		// 가장 좌측에 있는 숫자와 우측에 있는 숫자는 바로 윗부분의 숫자와 현재 위치의 숫자의 합
		DP[i][1] = DP[i - 1][1] + triangle[i][1];
		DP[i][i] = DP[i - 1][i - 1] + triangle[i][i];

		// 가장 좌측과 우측을 제외한 각 부분들은 '왼쪽 위와 현재 숫자의 합'과 '오른쪽 위와 현재 숫자의 합' 중 최댓값으로 채워놓음
		for (int j = 2; j < i; ++j) {
			DP[i][j] = std::max(DP[i - 1][j - 1], DP[i - 1][j]) + triangle[i][j];
		}
	}

	// 최하단에 있는 숫자들 중 가장 큰 값을 탐색
	// 그 값이 바로 합이 최대가 되는 경로에 있는 숫자들의 합
	int answer = 0;
	for (int i = 1; i <= n; ++i)
		answer = std::max(answer, DP[n][i]);

	std::cout << answer;
	return 0;
}