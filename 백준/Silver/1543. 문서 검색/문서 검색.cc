#include <bits/stdc++.h>

int cnt;

int main() {
	std::string str;
	std::getline(std::cin, str);

	std::string input;
	std::getline(std::cin, input);

	int i = 0;
	while (i + input.length() <= str.length()) {
		std::string temp(str.begin() + i, str.begin() + i + input.length());

		if (temp == input) {
			cnt++;
			i += input.length();
		}
		else 
			i++;
	}

	std::cout << cnt;
	return 0;
}