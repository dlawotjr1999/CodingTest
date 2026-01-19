#include <bits/stdc++.h>

int main() {
	int N; std::cin >> N;
	std::map<std::string, int> m;

	for (int i = 0; i < N; ++i) {
		std::string input;
		std::cin >> input;

		std::string extension = "";
		for (size_t j = input.length() - 1; j >= 0 && input[j] != '.'; --j) {
			extension += input[j];
		}

		std::reverse(extension.begin(), extension.end());
		m[extension]++;
	}

	for (auto& [str, cnt] : m) 
		std::cout << str << ' ' << cnt << '\n';
	
	return 0;
}