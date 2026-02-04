#include <bits/stdc++.h>

int main() {
	std::string input;

	while (std::cin >> input) {
		bool isCyclic = true;
		std::string doubled = input + input;

		for (int i = 1; i <= (int)input.length(); ++i) {
			std::string res = "";
			int carry = 0;
			int digit = 0;

			for (int j = (int)input.length() - 1; j >= 0; --j) {
				int cur = (input[j] - '0') * i + carry;
				carry = cur / 10; 
				digit = cur % 10;
				res += (digit + '0');
			}
			std::reverse(res.begin(), res.end());

			if (carry > 0) {
				isCyclic = false;
				break;
			}

			if (doubled.find(res) == std::string::npos) {
				isCyclic = false;
				break;
			}
		}

		std::cout << (isCyclic ? (input + " is cyclic\n") : (input + " is not cyclic\n"));
	}

	return 0;
}