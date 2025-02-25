#include <iostream>

unsigned long long result = 1;

int main() {

	int cnt = 0;
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0) {
			cnt++;
			if (i % 25 == 0) cnt++;
			if (i % 125 == 0) cnt++;

		}
	}
	std::cout << cnt << std::endl;
}