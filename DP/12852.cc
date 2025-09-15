#include <bits/stdc++.h>

// 정수 N이 주어졌을 때, N을 1로 만들기 위해 사용할 수 있는 연산으로 다음 세 가지가 존재함
// 1. X가 3으로 나누어 떨어지면, 3으로 나눔
// 2. X가 2로 나누어 떨어지면, 2로 나눔
// 3. 1을 뺌
// 위 연산을 이용해서 N을 1로 만들 때, 연산을 사용하는 최소 횟수를 구해야함
// 추가로, 1로 만드는 방법에 포함된 수를 순서대로 함께 출력해야 함

int main() {
	int N;
	std::cin >> N;

	// 연산 횟수는 first에 저장하며 연산 이전의 수, 즉 거쳐온 수를 second에 저장
	std::vector<std::pair<int, int>> DP(N + 1, { 0,0 });
	// 1이 목표 값이므로 first(연산 횟수)는 0, 이전 단계가 없음을 -1로 표현하여 second에 저장
	DP[1] = { 0,-1 };

	// 1을 뺀 경우, 2로 나누는 경우, 3으로 나누는 경우를 모두 고려하여 연산 진행
	// 연산 횟수가 더 적은 경우의 수를 DP의 first에 저장
	// 연산을 수행하기 이전의 값을 DP의 second에 저장(순방향)
	for (int i = 2; i <= N; ++i) {
		DP[i].first = DP[i - 1].first + 1;
		DP[i].second = i - 1;

		if (i % 3 == 0) {
			int temp = DP[i / 3].first + 1;
			if (temp < DP[i].first) {
				DP[i].first = temp;
				DP[i].second = i / 3;
			}
		}
		if (i % 2 == 0) {
			int temp = DP[i / 2].first + 1;
			if (temp < DP[i].first) {
				DP[i].first = temp;
				DP[i].second = i / 2;
			}
		}
	}

	std::cout << DP[N].first << '\n';

	std::cout << N << ' ';
	while (DP[N].second != -1) {
		std::cout << DP[N].second << ' ';
		N = DP[N].second;
	}

	return 0;
}