#include <bits/stdc++.h>

int main() {
	int T; std::cin >> T;

	while (T--) {
		std::string str;
		std::cin >> str;
		
		int idx = str.length() - 2;
		while (idx >= 0 && str[idx] >= str[idx + 1]) 
			idx--;

		if (idx < 0) {
			std::cout << str << '\n';
			continue;
		}

		int j = str.length() - 1;
		while (str[j] <= str[idx])
			j--;

		std::swap(str[idx], str[j]);

		std::sort(str.begin() + idx + 1, str.end());
		std::cout << str << '\n';
	}

	return 0;
}