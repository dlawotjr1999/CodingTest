#include <iostream>
#include <vector>
#include <algorithm>

/* 단순한 이분탐색 문제 */ 

int main() {
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<int> vec(N);

	for (int i = 0; i < N; i++)
		std::cin >> vec[i];

	// 이분 탐색 이전에는 정렬이 선행되어야 함
	std::sort(vec.begin(), vec.end());

	int M;
	std::cin >> M;

	std::vector<bool> results(M);
	for (int j = 0; j < M; j++) {
		int idx;
		std::cin >> idx;
		results[j] = std::binary_search(vec.begin(), vec.end(), idx);
	}

	for (bool result : results) {
		std::cout << result << '\n';
	}
}