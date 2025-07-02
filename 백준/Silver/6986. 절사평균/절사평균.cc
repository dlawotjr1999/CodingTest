#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main() {
	int N, K;
	std::cin >> N >> K;

	std::vector<double> vec(N);

	double trimmed_mean{ 0 }; double adjusted_mean{ 0 };

	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end());

	for (int i = K; i < N - K; ++i) {
		trimmed_mean += vec[i];
	}

	for (int i = 0; i < N; ++i) {
		if (i < K)
			vec[i] = vec[K];
		else if (i > (N - K - 1))
			vec[i] = vec[N - K - 1];
		adjusted_mean += vec[i];
	}

	trimmed_mean /= static_cast<double>(N - (K * 2));
	adjusted_mean /= static_cast<double>(N);

	trimmed_mean = std::round(trimmed_mean * 100.0) / 100.0;
	adjusted_mean = std::round(adjusted_mean * 100.0) / 100.0;

	std::cout << std::fixed << std::setprecision(2) << trimmed_mean << '\n' << adjusted_mean;
}