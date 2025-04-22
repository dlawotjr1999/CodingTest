#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

std::vector<int> vec;

int main() {
	int N, K;
	std::cin >> N >> K;

	vec.resize(N);
	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}

	double min_stddev = std::numeric_limits<double>::max();

	for (int i = K; i <= N; i++) { 
		for (int j = 0; j <= N - i; j++) {  
			double sum = 0;
			for (int k = j; k < j + i; k++) {
				sum += vec[k];
			}
			double avg = sum / i;

			double variance = 0;
			for (int k = j; k < j + i; k++) {
				variance += (vec[k] - avg) * (vec[k] - avg);
			}
			variance /= i;

			double stddev = std::sqrt(variance);

			if (stddev < min_stddev)
				min_stddev = stddev;
		}
	}

	std::cout.precision(11);
	std::cout << std::fixed << min_stddev;

	return 0;
}
