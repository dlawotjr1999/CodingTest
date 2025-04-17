#include <iostream>
#include <string>
#include <algorithm>

int main() {
	std::string input;
	std::getline(std::cin, input);

	std::string result = "";
	std::string temp = "";
	bool isTag = false;

	for (char c : input) {
		if (c == '<') {
			std::reverse(temp.begin(), temp.end());
			result += temp;
			temp.clear();

			isTag = true;
			result += c;
		}
		else if (c == '>') {
			isTag = false;
			result += c;
		}
		else if (isTag) {

			result += c;
		}
		else {
			if (c == ' ') {
				std::reverse(temp.begin(), temp.end());
				result += temp + ' ';
				temp.clear();
			}
			else {
				temp += c;
			}
		}
	}

	std::reverse(temp.begin(), temp.end());
	result += temp;

	std::cout << result;
	return 0;
}
