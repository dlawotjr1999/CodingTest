	#include <iostream>

	int main() {
		int N, L;
		std::cin >> N >> L;

		for (int i = L; i <= 100; ++i) {
			int Lx = N - i * (i + 1) / 2;

			if (Lx % i == 0) {
				int x = Lx / i + 1;

				if (x >= 0) {
					for (int j = 0; j < i; ++j) {
						std::cout << j + x << " ";
					}
					return 0;
				}

			}
		}

		std::cout << -1;
	}