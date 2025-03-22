#include <iostream>
#include <vector>

std::vector<bool> vec(10001, true);

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

		int a = n / 2;
		int b = n / 2;

		for (int i = 2; i < vec.size(); i++) {
			if (vec[a] && vec[b]) {
				std::cout << a << " " << b << '\n';
				break;
			}
			else {
				a--;
				b++;
			}
		}
	}

	return 0;
}