#include <iostream>

int A[30];
int B[30];

int main() {
	int D, K;
	std::cin >> D >> K;

	A[1] = 1;
	A[2] = 0;
	B[1] = 0;
	B[2] = 1;

	for (int i = 3; i <= D; i++) {
		A[i] = A[i - 1] + A[i - 2];
		B[i] = B[i - 1] + B[i - 2];
	}

	for (int i = 1; i <= K; i++) {
		int temp = K - (A[D] * i);
		if (temp % B[D] == 0) {
			if (1 <= i && i <= temp / B[D]) {
				std::cout << i << '\n' << temp / B[D] << std::endl;
				break;
			}
		}
	}

	return 0;
}