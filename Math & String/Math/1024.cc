#include <iostream>

// N과 L이 주어질 때, 합이 N이면서, 길이가 적어도 L인 가장 짧은 연속된 음이 아닌 정수 리스트를 구하는 문제

int main() {
	int N, L;
	std::cin >> N >> L;

	// L 길이를 가지는(x, x + L]에 대해 수식을 세우면 N = (x + 1) + ... + (x + L)
	// 여기서, Lx = N - (L * (L + 1) / 2)이므로 우항이 L로 나누어 떨어지면 x를 구할 수 있음
	for (int i = L; i <= 100; ++i) {
		int Lx = N - i * (i + 1) / 2;

		if (Lx % i == 0) {
			// x가 아닌 (x + 1)부터의 숫자를 구함
			int x = Lx / i + 1;

			if (x >= 0) {
				// (x + 1)부터 L개의 숫자 출력
				for (int j = 0; j < i; ++j) {
					std::cout << j + x << " ";
				}
				return 0;
			}

		}
	}

	// 존재하는 않는 경우에는 -1 출력
	std::cout << -1;
}