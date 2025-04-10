#include <iostream>
#include <algorithm>

std::string S;
std::string T;

int main() {
	std::cin >> S;
	std::cin >> T;

	while (T.length() != S.length()) {
		if (T.back() == 'A')
			T.pop_back();
		else {
			T.pop_back();
			std::reverse(T.begin(), T.end());
		}
	}

	std::cout << ((S == T) ? 1 : 0);

	return 0;
}