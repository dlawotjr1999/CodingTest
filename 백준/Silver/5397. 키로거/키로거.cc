#include <bits/stdc++.h>

int main() {
	int T; std::cin >> T;

	while (T--) {
		std::string input; std::cin >> input;
		
		std::list<char> str;
		auto itr = str.begin();

		for (char c : input) {
			if (c == '<') {
				if (itr != str.begin()) --itr;
			}
			else if (c == '>') {
				if (itr != str.end()) ++itr;
			}
			else if (c == '-') {
				if (itr != str.begin()) {
					auto temp = itr;
					--temp;
					itr = str.erase(temp);
				}
			}
			else {
				str.insert(itr, c);
			}
		}

		for (auto c : str) std::cout << c;
		std::cout << '\n';
	}

	return 0;
}