#include <iostream>
#include <algorithm>

int main() {
	int T;
	std::cin >> T;

	while (T--) {
		int N, M;
		std::cin >> N >> M;

		int* A = new int[N];
		int* B = new int[M];

		for (int j = 0; j < N; j++)
			std::cin >> A[j];
		for (int j = 0; j < M; j++)
			std::cin >> B[j];

		std::sort(B, B + M);

		int count = 0;
		for (int j = 0; j < N; j++) {
			count += std::upper_bound(B, B + M, A[j] - 1) - B;
		}

		std::cout << count << '\n';

		delete[] A;
		delete[] B;
	}

	return 0;
}