#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}
	
	std::reverse(vec.begin(), vec.end());
	std::vector<int> DP(N, 1);

	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (vec[i] > vec[j])
				DP[i] = std::max(DP[i], DP[j] + 1);
		}
	}

	int lis = *std::max_element(DP.begin(), DP.end());
	std::cout << N - lis;
	return 0;
}