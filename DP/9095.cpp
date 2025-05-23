#include <iostream>

// 1, 2, 3 세 숫자의 합으로 정수 N을 만드는 경우의 수를 구하는 문제
// 단, 같은 수를 여러 번 사용할 수 있으며, 서로 다른 순서를 다른 경우로 간주함

int N[11];

int main() {
	int T;
	int n;

	N[1] = 1;
	N[2] = 2;
	N[3] = 4;

	std::cin >> T;

	/*
		어떤 정수 N을 1, 2, 3의 합으로 나타내는 방법의 수는
		- 마지막에 1을 더한 경우: N-1을 만드는 경우의 수
		- 마지막에 2를 더한 경우: N-2를 만드는 경우의 수
		- 마지막에 3을 더한 경우: N-3을 만드는 경우의 수
		위와 같이 세 가지이다

		즉, 점화식은 N[i] = N[i - 1] + N[i - 2] + N[i - 3]
	*/

	for (int i = 4; i < 11; i++) {
		N[i] = N[i - 1] + N[i - 2] + N[i - 3];
	}

	for (int i = 0; i < T; i++) {
		std::cin >> n;
		std::cout << N[n] << std::endl;
	}
}