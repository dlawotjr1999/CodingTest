#include <iostream>
#include <algorithm>

// C++ 스타일의 변수명과 JAVA 스타일의 변수명을 서로 치환하는 문제
// 어느 것에도 해당하지 않는 경우 Error 출력
// C++ 스타일 : Snake Case
// JAVA 스타일 : Camel Case

/*
	예외 케이스 :

	1. 첫 글자에 _가 존재하거나 마지막 글자에 _가 존재하는 경우
	2. 첫 글자에 대문자가 오는 경우
	3. 입력 문자열 내에 __가 존재하는 경우
	4. C++ 스타일이지만 대문자가 존재하는 경우
	5. Java 스타일이지만 _가 존재하는 경우
*/

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
