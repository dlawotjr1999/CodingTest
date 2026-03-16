#include <bits/stdc++.h>

int main() {
	int T; std::cin >> T;

	while (T--) {
		std::string str; std::cin >> str;
		
		bool isBiggest = false;
		std::string answer = str;
		std::sort(answer.begin(), answer.end(), std::greater<char>());

		for (int i = 0; i < str.length(); ++i) {
			for (int j = i + 1; j < str.length(); ++j) {
				if (str[i] < str[j]) {
					std::string temp = str;

					std::swap(temp[i], temp[j]);
					std::sort(temp.begin() + i + 1, temp.end());
					if (str < temp)
						answer = std::min(temp, answer);
				}
			}
		}

		if (str == answer)
			isBiggest = true;

		std::cout << (!isBiggest ? answer : "BIGGEST") << '\n';
	}

	return 0;
}