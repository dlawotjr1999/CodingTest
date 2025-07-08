#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	std::vector<int> lds(N, 1);

	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

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