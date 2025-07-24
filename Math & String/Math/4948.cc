#include <iostream>
#include <vector>

// 베르틀랑 공준을 구하는 문제
// 즉 n이 주어졌을 때, n보다 크고 2n보다 작거나 같은 소수의 갯수를 구하는 문제

// 에라토스테네스의 체
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

		// 2n까지의 소수의 갯수에서 n까지의 소수의 갯수를 빼면 구하고자 하는 값이 나옴
		std::cout << b - a << '\n';
	}
}