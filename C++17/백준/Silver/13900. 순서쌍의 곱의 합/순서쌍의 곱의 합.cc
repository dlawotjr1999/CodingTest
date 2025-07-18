#include <iostream>
#include <vector>

long long answer = 0;

int main() {
	int N;
	std::cin >> N;

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