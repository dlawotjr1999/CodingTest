#include <iostream>
#include <vector>

int main() {
	std::string input;
	std::string result = "";
	int cnt = 0;

	std::cin >> input;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] != '.') {
			cnt++;
		}
		else {
			if (cnt % 2 != 0) {
				std::cout << -1;
				return 0;
			}
			else {
				while (cnt >= 4) {
					result += "AAAA";
					cnt -= 4;
				}
				while (cnt == 2) {
					result += "BB";
					cnt -= 2;
				}
				result += '.';
			}
		}
	}

	if (cnt % 2 != 0) {
		std::cout << -1;
		return 0;
	}
	else {
		while (cnt >= 4) {
			result += "AAAA";
			cnt -= 4;
		}
		while (cnt == 2) {
			result += "BB";
			cnt -= 2;
		}
	}

	std::cout << result;

	return 0;
}