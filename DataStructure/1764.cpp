#include <iostream>
#include <vector>
#include <cmath>
#define MAX 500

std::vector<int> vec;

int main() {
	int N, K;
	std::cin >> N >> K;
	std::cout << "N = " << N << ", K = " << K << '\n';

	std::vector<int> vec(N);

	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
		std::cout << "vec[" << i << "] = " << vec[i] << '\n';
	}

	int difference_sum = MAX;
	int min_index = -1;

	for (int i = 0; i <= vec.size() - K; i++) {
		int temp = 0;

		for (int j = i; j < (i + K - 1); j++) {
			temp += std::abs(vec[j] - vec[j + 1]);
		}
		if (temp < difference_sum) {
			difference_sum = temp;
			min_index = i;
		}
	}

	int sum = 0;

	for (int i = min_index; i < (min_index + K - 1); i++) {
		sum += vec[i];
	}
	double avg = static_cast<double>(sum) / K;

	double variance = 0;
	for (int i = min_index; i < min_index + K; i++) {
		variance += (vec[i] - avg) * (vec[i] - avg);
	}
	variance /= K;

	std::cout.precision(10);
	std::cout << std::sqrt(variance);

	return 0;
}