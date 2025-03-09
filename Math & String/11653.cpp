#include <iostream>

int main() {
	int num;
	int i = 2;

	std::cin >> num;

	while (num != 1) {
		if (num % i == 0) {
			std::cout << i << "\n";
			num /= i;
			i = 2;
		}
		else i++;
	}
}