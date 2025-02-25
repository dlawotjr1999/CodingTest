#include <iostream>

long long arr[100];

int main() {
	int T;
	std::cin >> T;

	arr[0] = arr[1] = arr[2] = 1;

	for (int i = 3; i < 100; i++) {
		arr[i] = arr[i - 3] + arr[i - 2];
	}

	while (T--) {
		int N;
		std::cin >> N;
		std::cout << arr[N - 1] << '\n';
	}

	return 0;
}