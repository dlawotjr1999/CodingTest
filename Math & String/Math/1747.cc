#include <iostream>
#include <string>

constexpr int MAX = 2000000;
bool arr[MAX + 1] = { true, };

int main() {
	int N;
	std::cin >> N;

	for (int i = 2; i <= MAX; ++i) {
		arr[i] = i;
	}

	for (int i = 2; i * i <= MAX; ++i) {
		if (arr[i] == false)
			continue;
		
		for (int j = i * i; j <= MAX; j += i) {
			arr[j] = false;
		}
	}

	for (int i = N; i <= MAX; ++i) {
		if (arr[i] == false)
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