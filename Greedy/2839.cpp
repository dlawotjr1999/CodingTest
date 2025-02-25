#include <iostream>

int main() {
	int N;
	int pocketA, pocketB;

	std::cin >> N;

	pocketA = N / 5;
	while (true) {
		if (pocketA < 0) {
			std::cout << -1;
			return 0;
		}
		if ((N - pocketA * 5) % 3 == 0) {
			pocketB = (N - pocketA * 5) / 3;
			break;
		}
		pocketA--;
	}
	std::cout << pocketA + pocketB << std::endl;
}