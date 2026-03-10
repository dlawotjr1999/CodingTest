#include <bits/stdc++.h>

int answer;

int main() {
	std::string input; std::cin >> input;

	std::stack<char> s;
	for (int i = 0; i < input.length(); ++i) {
		if (i + 1 < input.length() && input[i] == '(' && input[i + 1] == ')') {
			answer += s.size();
			i++;
		}
		else if (input[i] == '(') {
			s.push(input[i]);
		}
		else if (!s.empty() && input[i] == ')') {
			answer++;
			s.pop();
		}
	}
	std::cout << answer;
	return 0;
}