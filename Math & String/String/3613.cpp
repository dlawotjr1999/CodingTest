#include <iostream>
#include <algorithm>

// C++ ��Ÿ���� ������� JAVA ��Ÿ���� �������� ���� ġȯ�ϴ� ����
// ��� �Ϳ��� �ش����� �ʴ� ��� Error ���
// C++ ��Ÿ�� : Snake Case
// JAVA ��Ÿ�� : Camel Case

/*
	���� ���̽� :

	1. ù ���ڿ� _�� �����ϰų� ������ ���ڿ� _�� �����ϴ� ���
	2. ù ���ڿ� �빮�ڰ� ���� ���
	3. �Է� ���ڿ� ���� __�� �����ϴ� ���
	4. C++ ��Ÿ�������� �빮�ڰ� �����ϴ� ���
	5. Java ��Ÿ�������� _�� �����ϴ� ���
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
