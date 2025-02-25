#include <iostream>
#include <vector>

int main() {
	std::vector<bool> vec(10001, true);

	for (int i = 1; i < vec.size(); i++) {
		int sum = 0;
		int num = i;

		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}
		if (sum + i < vec.size()) {
			vec[sum + i] = false;
		}
	}
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] == true)
			std::cout << i << std::endl;
	}
}