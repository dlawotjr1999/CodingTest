#include <bits/stdc++.h>

int answer;

int main() {
	std::string str;
	std::cin >> str;

	for (int i = 0; i < str.length(); ++i) {
		bool isOk = true;
		int l = i, r = str.length() - 1;

		while (l < r) {
			if (str[l] != str[r]) {
				isOk = false;
				break;
			}
			l++;
			r--;
		}

		if (isOk) {
			std::cout << str.length() + i;
			return 0;
		}
	}
}