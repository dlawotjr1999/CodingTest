#include <bits/stdc++.h>

int main() {
	int K, C;
	std::cin >> K >> C;

	while (C--) {
		int M, N;
		std::cin >> M >> N;
	
		if (M == N) {
			std::cout << 1 << '\n';
			continue;
		}
		
		int remain = K - std::max(M, N);
		int diff = std::abs(M - N);

		if (M > N) {
			if ((diff - remain) <= 2) {
				std::cout << 1 << '\n';
				continue;
			}

			std::cout << 0 << '\n';
			continue;
		}

		if ((diff - remain) <= 1) {
			std::cout << 1 << '\n';
			continue;
		}

		std::cout << 0 << '\n';
	}

	return 0;
}