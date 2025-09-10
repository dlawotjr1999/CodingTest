#include <iostream>
#include <stack>
#include <algorithm>

int main() {
	int index = 1;

	while (true) {
		std::string input;
		std::cin >> input;

		if (std::find(input.begin(), input.end(), '-') != input.end()) {
			return 0;
		}

		int answer = 0;

		std::stack<char> s;
		for (char c : input) {
			if (c == '{')
				s.push(c);
			else {
				if (s.empty()) {
					answer++;
					s.push('{');
				}
				else {
					s.pop();
				}
			}
		}
		
		answer += static_cast<int>(s.size() / 2);
		std::cout << index << '.' << ' ' << answer << '\n';

		index++;
	}
}