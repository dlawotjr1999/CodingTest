#include <iostream>
#include <algorithm>

int DP[1000000];

int main() {
	int N;
	std::cin >> N;

	for (int i = 2; i <= N; i++) {
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0)
			DP[i] = std::min(DP[i], DP[i / 2] + 1);
		if (i % 3 == 0)
			DP[i] = std::min(DP[i], DP[i / 3] + 1);
	}

	std::cout << DP[N];

	return 0;
}