#include <iostream>

// 소인수분해 구현
int main() {
	int num;
	int i = 2;

	std::cin >> num;

	// 먼저 2로 나누어 떨어지는지 확인
	// 2로 나누어 떨어지지 않으면 i를 증가시키면서 소인수를 검토
	while (num != 1) {
		if (num % i == 0) {
			std::cout << i << "\n";
			num /= i;
		}
		else 
			i++;
	}
}