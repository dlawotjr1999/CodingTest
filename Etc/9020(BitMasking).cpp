#include <iostream>
#include <vector>

// 골드바흐 파티션을 구하는 문제
// 골드바흐 파티션 : 짝수를 두 소수의 합으로 나타내는 표현
// 골드바흐 파티션이 여러 개인 경우 두 소수의 차이가 가장 작은 것을 출력

std::vector<bool> vec(10001, true);

// 에라토스테네스의 체
void SieveOfEratosthenes() {
	vec[0] = vec[1] = false;

	for (int i = 2; i * i <= 10000; i++) {
		if (vec[i]) {
			for (int j = i * i; j <= 10000; j += i) {
				vec[j] = false;
			}
		}
	}
}

int main() {
	int T;
	std::cin >> T;

	SieveOfEratosthenes();

	while (T--) {
		int n;
		std::cin >> n;

		// 두 수로 분할하기 위해 가운데 수를 기준으로 삼음
		int a = n / 2;
		int b = n / 2;

		for (int i = 2; i < vec.size(); i++) {
			// a와 b 두 수가 모두 소수면 골드바흐 파티션이므로 출력 후 종료
			if (vec[a] && vec[b]) {
				std::cout << a << " " << b << '\n';
				break;
			}
			// 그렇지 않으면 a는 감소, b는 증가시키면서 소수인지를 탐색함
			// 출력되는 소수는 작은 것부터 출력되어야 하기 때문
			else {
				a--;
				b++;
			}
		}
	}

	return 0;
}