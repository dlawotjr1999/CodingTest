#include <iostream>

void Star(int i, int j, int n) {
	if (n == 1) {
		std::cout << '*';
	}
	else if ((i - 1) / (n / 3) % 3 == 1 && (j - 1) / (n / 3) % 3 == 1)
		std::cout << ' ';
	else
		Star(i, j, n / 3);
}

int main() {
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Star(i, j, N);
		}
		std::cout << '\n';
	}

	return 0;
}
