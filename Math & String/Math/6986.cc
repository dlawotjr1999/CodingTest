#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

// 절사평균 : 극단값의 영향을 줄이기 위해 데이터의 상위·하위 일정 비율을 제거한 후 산술평균을 계산하는 방법
// 보정평균 : 데이터의 상위·하위 일정 일정 비율을 제거한 후 양쪽 가장 가까운 값으로 치환하여 산술평균을 계산하는 방법

int main() {
	int N, K;
	std::cin >> N >> K;

	std::vector<double> vec(N);

	double trimmed_mean{ 0 }; double adjusted_mean{ 0 };

	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	// 두 평균을 구하기 위해 정렬이 선행되어야 함
	std::sort(vec.begin(), vec.end());

	// 앞 뒤 각각 K개의 원소를 제외하고 값을 누적
	for (int i = K; i < N - K; ++i) {
		trimmed_mean += vec[i];
	}

	// 앞 뒤 각각 K개의 값을 (K + 1)번째와 (N - K)번째 값으로 치환
	for (int i = 0; i < N; ++i) {
		if (i < K)
			vec[i] = vec[K];
		else if (i > (N - K - 1))
			vec[i] = vec[N - K - 1];
		adjusted_mean += vec[i];
	}

	trimmed_mean /= static_cast<double>(N - (K * 2));
	adjusted_mean /= static_cast<double>(N);

	// 소수점 두 자릿수까지 반올림
	trimmed_mean = std::round(trimmed_mean * 100.0) / 100.0;
	adjusted_mean = std::round(adjusted_mean * 100.0) / 100.0;

	// 소수점 두 자릿수까지만 출력
	std::cout << std::fixed << std::setprecision(2) << trimmed_mean << '\n' << adjusted_mean;
}