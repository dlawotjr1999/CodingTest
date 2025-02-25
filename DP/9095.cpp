#include <iostream>

int N[11];

int main() {
	int T;
	int n;

	N[1] = 1;
	N[2] = 2;
	N[3] = 4;

	std::cin >> T;

	for (int i = 4; i < 11; i++) {
		N[i] = N[i - 1] + N[i - 2] + N[i - 3];
	}

	for (int i = 0; i < T; i++) {
		std::cin >> n;
		std::cout << N[n] << std::endl;
	}
}