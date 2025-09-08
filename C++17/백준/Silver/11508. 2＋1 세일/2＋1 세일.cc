#include <iostream>
#include <vector>
#include <algorithm>

int answer;

int main() {
	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end(), std::greater<int>());
	for (int i = 0; i < N; ++i) {
		if ((i + 1) % 3 == 0)
			continue;
		answer += vec[i];
	}

	std::cout << answer;
	return 0;
}