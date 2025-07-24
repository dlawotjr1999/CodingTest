#include <iostream>
#include <vector>

// N개의 정수 중 서로 다른 위치의 두 수를 뽑는 모든 경우의 두 수의 곱의 합을 구하는 문제
// 예를 들어 N = 3이고 주어진 정수가 2, 3, 4일 때 두 수를 뽑는 모든 경우는 (2, 3), (2, 4), (3, 4)이며, 이때 각각의 곱은 6, 8, 12이기 때문에 총합은 26

long long answer = 0;

int main() {
	int N;
	std::cin >> N;

	// N개의 숫자 중 2개를 골라 그 곱을 합으로 만들 때의 공식은 아래와 같이 구성됨
	// a(b + c + d + ...) + b(c + d + e + ...) + c(d + e + f + ...) + ...
	// 즉, 0부터 i - 1번째 배열까지 i번째 배열의 값* ((i + 1)번째부터 (N - 1)번째를 모두 더한 값)을 구해 모두 더해주면 e됨
	// 특히 우항은 누적합을 통해 구할 수 있음(sum[N] - sum[i + 1])
	std::vector<int> vec(N);
	std::vector<long long> sum(N + 1);
	sum[0] = vec[0];

	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
		sum[i + 1] = sum[i] + vec[i];
	}

	for (int i = 0; i < N - 1; ++i) {
		answer += vec[i] * (sum[N] - sum[i + 1]);
	}

	std::cout << answer;
	return 0;
}