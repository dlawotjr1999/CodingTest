#include <iostream>
#include <vector>
#include <algorithm>

// LDS(Longest Decreasing Subsequence) 구현 문제

int main() {
	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	std::vector<int> lds(N, 1);

	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	// LDS Algorithm
	// LIS 알고리즘에서 원소의 크기 비교를 반대로 진행하면 구할 수 있음
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (vec[i] < vec[j]) {
				lds[i] = std::max(lds[i], lds[j] + 1);
			}
		}
	}

	std::cout << *std::max_element(lds.begin(), lds.end());
	return 0;
}