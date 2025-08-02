#include <iostream>
#include <vector>
#include <algorithm>

// N명의 병사가 무작위로 나열되어 있을 때, 전투력을 기준으로 병사를 내림차순으로 배치하려고 함
// 배치 과정에서는 특정 위치의 병사를 열외시키는 방법을 사용함
// 이 때 남아있는 병사의 수를 최대로 하기 위해 열외해야 하는 병사의 수를 구하는 문제

// 가장 긴 증가하는 부분 수열 문제를 활용하여 해결 가능
// 내림차순이기 때문에 원래 순서를 반대로 뒤집으면, 가장 긴 증가하는 부분 수열 문제로 치환 가능함
// 전체 병사의 수에서 LIS의 길이를 빼면 열외해야 하는 최소 병사의 수를 구할 수 있음

int main() {
	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}
	
	std::reverse(vec.begin(), vec.end());
	std::vector<int> DP(N, 1);

	// LIS 알고리즘 수행
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (vec[i] > vec[j])
				DP[i] = std::max(DP[i], DP[j] + 1);
		}
	}

	// LIS의 최대 길이를 구하고, N에서 lis를 빼면 열외해야 하는 병사의 수를 구할 수 있음
	int lis = *std::max_element(DP.begin(), DP.end());
	std::cout << N - lis;
	return 0;
}