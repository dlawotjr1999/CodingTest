#include <iostream>
#include <string>

constexpr int MAX = 2000000;
int arr[MAX + 1];

int main() {
	int N;
	std::cin >> N;

	for (int i = 2; i <= MAX; ++i) {
		arr[i] = i;
	}

	for (int i = 2; i * i <= MAX; ++i) {
		if (arr[i] == 0)
			continue;	
		for (int j = i * i; j <= MAX; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = N; i <= MAX; ++i) {
		if (arr[i] == 0)
			continue;

		std::string num = std::to_string(i);
		std::string reverse_num(num.crbegin(), num.crend());

		if (num == reverse_num) {
			std::cout << num;
			break;
		}
	}

	return 0;
}