#include <iostream>

// 한수 구하기
// 한수란? : 어떤 양의 정수 X의 각 자릿수가 등차수열을 이루는 수

int main() {
	int N;
	int cnt = 99;

	std::cin >> N;

	if (N < 100)
		std::cout << N;
	else {
		for (int i = 100; i <= N; i++) {
			int temp = i;
			int digits[3];

			for (int j = 0; j < sizeof(digits) / sizeof(int); j++) {
				int digit = temp % 10;
				digits[(sizeof(digits) / sizeof(int)) - j - 1] = digit;
				temp /= 10;
			}
			if ((digits[2] - digits[1]) == (digits[1] - digits[0]))
				cnt++;
		}
		if (N == 1000) cnt--;
		std::cout << cnt;
	}
}