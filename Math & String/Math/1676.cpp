#include <iostream>

// 수학 계산 문제
// N!에서 맨 뒤 0의 갯수는 10의 배수의 갯수에 따라 결정됨
// 하지만 2의 배수가 5의 배수보다 갯수가 더 많으므로 5의 배수의 갯수를 세는 것으로 치환할 수 있음

unsigned long long result = 1;

int main() {

	int cnt = 0;
	int n;
	std::cin >> n;

	// 0 <= N <= 500이므로 25, 125의 배수도 고려해야 함
	// 25의 배수인 경우 5가 한 번 더 곱해지므로 cnt++
	// 125의 배수인 경우도 마찬가지
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0) {
			cnt++;
			if (i % 25 == 0) cnt++;
			if (i % 125 == 0) cnt++;

		}
	}
	std::cout << cnt << std::endl;
}