#include <iostream>

// Âü°í : https://en.wikipedia.org/wiki/Regular_paperfolding_sequence

bool Fold(std::string& str, int start, int end) {
	if (start >= end)
		return true;

	int left = start;
	int right = end;

	while (left < right) {
		if (str[left] == str[right])
			return false;
		left++;
		right--;
	}
	return Fold(str, start, right - 1);
}

int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::string input;
		std::cin >> input;

		if (input.length() % 2 == 0) {
			std::cout << "NO";
			continue;
		}

		if (input.length() == 1) {
			std::cout << "YES" << '\n';
			continue;
		}

		else if (Fold(input, 0, input.length() - 1))
			std::cout << "YES" << '\n';
		else
			std::cout << "NO" << '\n';
	}

	return 0;
}