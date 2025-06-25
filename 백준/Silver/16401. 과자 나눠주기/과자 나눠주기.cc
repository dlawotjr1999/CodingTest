#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int M, N;
	std::cin >> M >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	int left = 1, right = *std::max_element(vec.begin(), vec.end());
	int answer = 0;
	
	while (left <= right) {
		int mid = (left + right) / 2; 
		int count = 0;
		for (int i = 0; i < N; i++) {
			count += vec[i] / mid; 
		}
		if (count >= M) {
			left = mid + 1;
			answer = mid;
		}
		else if (count < M) { 
			right = mid - 1;
		}
	}
	std::cout << answer << "\n";

	return 0;
}