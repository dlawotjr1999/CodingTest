#include <iostream>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::string str;
	std::cin >> str;
	
	int N = 1;
	int idx = 0;

	while (true) {
		std::string temp = std::to_string(N);

		for (int i = 0; i < temp.length(); ++i) {
			if (str[idx] == temp[i])
				idx++;
			if (idx >= str.length()) {
				std::cout << N;
				return 0;
			}
		}
		N++;
	}
	return 0;
}