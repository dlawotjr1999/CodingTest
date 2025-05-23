#include <iostream>
#include <algorithm>

// 정수 N이 주어졌을 때, N을 1로 만들기 위해 사용할 수 있는 연산은 다음 세 가지이다:
// 1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
// 2. X가 2로 나누어 떨어지면, 2로 나눈다.
// 3. 1을 뺀다.
// 위 연산을 이용해서 N을 1로 만들 때, 연산을 사용하는 최소 횟수를 구해야함

// "연산 횟수"를 구해야하므로 DP에는 연산 횟수의 데이터를 담아야 함
int DP[1000000];

int main() {
	int N;
	std::cin >> N;

	// DP[0] = DP[1] = 0;

	for (int i = 2; i <= N; i++) {
		// 기본적으로는 1을 빼는 연산을 먼저 고려한다.
		// 즉, i-1까지의 최소 연산 횟수에서 1을 더한 값
		DP[i] = DP[i - 1] + 1;

		// 만약 i가 2로 나누어 떨어지는 경우
		// i를 2로 나눈 수까지 가는 최소 연산 횟수 + 1 (i → i/2)
		if (i % 2 == 0)
			DP[i] = std::min(DP[i], DP[i / 2] + 1);

		// 만약 i가 3으로 나누어 떨어지는 경우
		// i를 3으로 나눈 수까지 가는 최소 연산 횟수 + 1 (i → i/3)
		if (i % 3 == 0)
			DP[i] = std::min(DP[i], DP[i / 3] + 1);
	}

	// 최종적으로 DP[N]에는 N을 1로 만들기 위한 최소 연산 횟수가 저장됨
	std::cout << DP[N];

	return 0;

	return 0;
}