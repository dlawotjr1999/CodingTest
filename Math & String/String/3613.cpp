#include <iostream>
#include <algorithm>

int main() {
	std::string input, result;
	std::cin >> input;

	bool isError = false;
	bool isCpp = false;
	bool isJava = false;

	if (input.empty() || input.front() == '_' || std::isupper(input.front())) {
		isError = true;
	}
	else if (input.find("__") != std::string::npos) {
		isError = true;
	}
	else if (input.back() == '_') {
		isError = true;
	}

	else if (input.find('_') != std::string::npos) {
		isCpp = true;

		if (std::any_of(input.begin(), input.end(), ::isupper)) {
			isError = true;
		}
		for (size_t i = 0; i + 1 < input.size(); ++i) {
			if (input[i] == '_' && std::isupper(input[i + 1])) {
				isError = true;
				break;
			}
		}
	}

	else if (std::any_of(input.begin(), input.end(), ::isupper)) {
		isJava = true;

		if (input.find('_') != std::string::npos) {
			isError = true;
		}
	}

	else {
		isJava = true;
	}

	if (isError) {
		std::cout << "Error!" << std::endl;
		return 0;
	}

	if (isCpp) {
		bool toUpper = false;
		for (char c : input) {
			if (c == '_') {
				toUpper = true;
			}
			else {
				if (toUpper) {
					result += std::toupper(c);
					toUpper = false;
				}
				else {
					result += c;
				}
			}
		}
	}

	else if (isJava) {
		for (char c : input) {
			if (std::isupper(c)) {
				result += '_';
				result += std::tolower(c);
			}
			else {
				result += c;
			}
		}
	}

	std::cout << result << std::endl;
	return 0;
}
