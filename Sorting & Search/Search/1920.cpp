#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<int> vec(N);

	for (int i = 0; i < N; i++)
		std::cin >> vec[i];

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