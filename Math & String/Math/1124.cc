#include <bits/stdc++.h>

// 언더프라임이란, 어떤 수 X를 소인수분해 해서 구한 소수의 목록의 길이가 소수인 수를 의미함
// 두 정수 A와 B가 주어졌을 때, A보다 크거나 같고, B보다 작거나 같은 정수 중에서 언더프라임인 것의 갯수를 구하는 문제

bool isPrime[100001];
int answer;

// 에라토스테네스의 체로 소수 판별
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

		// 현재 수 i를 소인수분해
		for (int p = 2; p <= cur; ++p) {
			// p가 소수가 아닌 경우에는 진행하지 않음
			if (!isPrime[p])
				continue;

			// 소인수분해 시 같은 수가 여러 번 나올 수 있음
			// 이러한 이유로 현재 소인수로 여러 번 분해하여 그 횟수를 구함
			while (cur % p == 0) {
				cur /= p;
				cnt++;
			}
		}

		// 소인수분해 결과의 길이가 소수인 경우 정답
		if (isPrime[cnt]) 
			answer++;
	}

	std::cout << answer;
	return 0;
}