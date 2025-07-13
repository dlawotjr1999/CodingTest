#include <iostream>
#include <vector>

inline int sieve_of_eratosthenes(int n) {
	int cnt = 0;
	std::vector<bool> vec(n + 1, false);
	
	for (int i = 2; i * i <= n; ++i) {
		if (vec[i] == true)
			continue;

		for(int j = i * i; j <= n; j += i) {
			vec[j] = true;
		}
	}

	for (int i = 2; i <= n; ++i) {
		if (!vec[i]) cnt++;
	}

	return cnt;
}

int main() {
	while (true) {
		int n;
		std::cin >> n;

		if (n == 0)
			break;
		int a = sieve_of_eratosthenes(n);
		int b = sieve_of_eratosthenes(2 * n);

		std::cout << b - a << '\n';
	}
}