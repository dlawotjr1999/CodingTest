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

	std::sort(vec.begin(), vec.end());

	std::cout << vec[(vec.size() - 1) / 2];
	return 0;
}