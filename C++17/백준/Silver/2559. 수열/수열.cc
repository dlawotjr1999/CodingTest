#include <iostream>
#include <vector>

int answer = -1;

int main() {
	int N, K;	std::cin >> N >> K;
	std::vector<int> vec(N);

	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	int cur_sum = 0;
	for (int i = 0; i < K; ++i) {
		cur_sum += vec[i];
	}
	answer = cur_sum;

	for (int i = K; i < N; ++i) {
		cur_sum += (vec[i] - vec[i - K]);
		answer = std::max(answer, cur_sum);
	}

	std::cout << answer;
	return 0;
}