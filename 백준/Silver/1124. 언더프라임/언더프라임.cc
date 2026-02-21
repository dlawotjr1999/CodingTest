#include <bits/stdc++.h>

bool isPrime[100001];
int answer;

void SieveOfEratosthenes() {
	for (int i = 2; i * i <= 100000; ++i) {
		for (int j = i * i; j <= 100000; j += i) {
			isPrime[j] = false;
		}
	}
}

int main() {
	int A, B;
	std::cin >> A >> B;
	
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	SieveOfEratosthenes();
	
	for (int i = A; i <= B; ++i) {		
		int cur = i;
		int cnt = 0;

		for (int p = 2; p <= cur; ++p) {
			if (!isPrime[p])
				continue;

			while (cur % p == 0) {
				cur /= p;
				cnt++;
			}
		}

		if (isPrime[cnt]) 
			answer++;
	}

	std::cout << answer;
	return 0;
}