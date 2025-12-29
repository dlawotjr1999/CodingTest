#include <iostream>
#include <vector>

int DP[1001];

int main() {
	int N;	
	std::cin >> N;

	std::vector<int> vec(N + 1);
	for (int i = 1; i <= N; ++i) {
		std::cin >> vec[i];
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			DP[i] = std::max(DP[i], DP[i - j] + vec[j]);
		}
	}

	std::cout << DP[N];
	return 0;
}