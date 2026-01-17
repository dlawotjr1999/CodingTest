#include <bits/stdc++.h>

int main() {
	std::string str; std::cin >> str;

	std::unordered_set<std::string> s;
	for (int len = 1; len <= str.length(); ++len) {
		for (int i = 0; i + len <= str.length(); ++i) {
			std::string tmp = str.substr(i, len);
			s.insert(tmp);
		}
	}

	std::cout << s.size();
	return 0;
}