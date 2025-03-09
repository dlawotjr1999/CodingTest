#include <iostream>
#include <cmath>

void Cantor(int n) {
	if (n == 0) {
		std::cout << '-';
		return;
	}
	Cantor(n - 1);
	for (int i = 0; i < std::pow(3, (n - 1)); i++) {
		std::cout << " ";
	}
	Cantor(n - 1);
}

int main() {
	int N;

	while (std::cin >> N) {
		Cantor(N);
		std::cout << "\n";
	}

	return 0;
}