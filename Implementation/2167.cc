#include <bits/stdc++.h>

// 2차원 배열이 주어졌을 때(i, j) 위치부터(x, y) 위치까지에 저장되어 있는 수들의 합을 구하는 문제

constexpr int MAX = 301;

int N, M;
int arr[MAX][MAX];

int main() {
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> arr[i][j];
		}
	}

	int K;
	std::cin >> K;

	for (int idx = 0; idx < K; ++idx) {
		int i, j, x, y;
		std::cin >> i >> j >> x >> y;
	
		int sum = 0;

		for (int a = 0; a <= x - i; ++a) {
			for (int b = 0; b <= y - j; ++b) {
				// 0-based로 만들기 위해 인덱스에 -1을 해야 함
				sum += arr[i - 1 + a][j - 1 + b];
			}
		}
		std::cout << sum << '\n';
	}

	return 0;
}