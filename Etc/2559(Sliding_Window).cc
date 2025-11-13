#include <iostream>
#include <vector>

// 측정한 온도들이 어떤 정수의 수열로 주어졌을 때, 연속적인 며칠 동안의 온도의 합이 가장 큰 값을 구하는 문제

int answer = -1;

int main() {
	int N, K;	std::cin >> N >> K;
	std::vector<int> vec(N);

	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	// 최초 window 계산
	int cur_sum = 0;
	for (int i = 0; i < K; ++i) {
		cur_sum += vec[i];
	}
	answer = cur_sum;

	// window를 갱신해나가며 연속적인 기간동안의 온도의 합을 갱신함
	for (int i = K; i < N; ++i) {
		cur_sum += (vec[i] - vec[i - K]);
		answer = std::max(answer, cur_sum);
	}

	std::cout << answer;
	return 0;
}