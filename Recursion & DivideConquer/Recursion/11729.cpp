#include <iostream>
#include <cmath>

void Hanoi(int num, int from, int temp, int to) {
	if (num == 1) {
		std::cout << from << " " << to << "\n";
	}
	else {
		Hanoi((num - 1), from, to, temp);
		std::cout << from << " " << to << "\n";
		Hanoi((num - 1), temp, from, to);
	}
}

int main() {
	int N;
	std::cin >> N;

	std::cout << int(std::pow(2, N)) - 1 << '\n';
	Hanoi(N, 1, 2, 3);

	return 0;
}