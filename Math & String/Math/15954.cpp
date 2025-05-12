#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

// 특정한 곳에 인형들을 배치하고자 하는데, 인형들을 배치하는 규칙은 아래와 같음
// 1. 먼저 비슷한 인형이 가깝게 위치하도록 서로 다른 N개의 인형을 종류당 한 개씩 일렬로 배치
// 2. 그 후, 선호하는 사람의 수의 표준편차가 최소가 되는, K개 이상의 연속된 위치에 있는 인형들을 선택하여 그들을 같은 곳에 배치
// 이 때, 위의 방법으로 인형들을 선택했을 때, 선택된 인형들의 선호하는 사람의 수의 표준편차를 구해야 함
// 즉, 만약 K가 3인 경우 3, 4, 5, ... N개로 배치된 인형들의 모든 표준편차를 구해야 함

std::vector<int> vec;

int main() {
	int N, K;
	std::cin >> N >> K;

	vec.resize(N);
	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}

	// 표준편차의 최솟값을 갱신하기 위해 최초 표준편차에 max_value(double)를 저장
	double min_stddev = std::numeric_limits<double>::max();

	//	문제 정의에 의해 최소가 되는 표준편차는 아래의 경우를 모두 고려해야 함(e.g. K = 3일 경우; 0-based)
	// 3 : (0, 1, 2), (1, 2, 3), (2, 3, 4), ... (N-3, N-2, N-1)
	// 4 : (0, 1, 2, 3), (1, 2, 3, 4), (2, 3, 4, 5), ... (N-4, N-3, N-2, N-1)
	// 5 : (0, 1, 2, 3, 4), (1, 2, 3, 4, 5), (2, 3, 4, 5, 6), ... (N-5, N-4, N-3, N-2, N-1)
	// ...
	// N : (0, 1, 2, ... N-1)

	// i : K 이상 N 이하의 갯수를 담당하는 index 
	for (int i = K; i <= N; i++) {
		// j : i개로 이루어진 그룹의 시작점을 구하는 index
		for (int j = 0; j <= N - i; j++) {  
			double sum = 0;
			
			// k : 시작 index(j)로부터 i개로 이루어진 그룹의 원소들을 구하는 index
			for (int k = j; k < j + i; k++) {
				sum += vec[k];
			}
			double avg = sum / i;

			double variance = 0;
			for (int k = j; k < j + i; k++) {
				// 분산은 (현재 값 - 평균)의 제곱
				variance += (vec[k] - avg) * (vec[k] - avg);
			}
			variance /= i;

			double stddev = std::sqrt(variance);

			if (stddev < min_stddev)
				min_stddev = stddev;
		}
	}

	// 소수점 11자리까지 출력
	std::cout.precision(11);
	std::cout << std::fixed << min_stddev;

	return 0;
}
