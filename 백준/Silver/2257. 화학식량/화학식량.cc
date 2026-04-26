#include <bits/stdc++.h>

int answer;

int GetWeight(char c) {
	if (c == 'H')
		return 1;
	else if (c == 'C')
		return 12;
	else if (c == 'O')
		return 16;
}

int main() {
	std::string exp; std::cin >> exp;
	std::stack<int> s;

	int len = exp.length();
	int idx = 0;

	while (idx < len) {
		char cur = exp[idx];

		if (cur == '(') {
			s.push(-1);
		}
		else if (cur == ')') {
			int sum = 0;

			while (!s.empty() && s.top() != -1) {
				sum += s.top();
				s.pop();
			}
			s.pop();
			s.push(sum);
		}
		else if (isdigit(cur)) {
			int num = cur - '0';

			int top = s.top();
			s.pop();
			s.push(top * num);
		}
		else {
			s.push(GetWeight(cur));
		}

		idx++;
	}

	while (!s.empty()) {
		answer += s.top();
		s.pop();
	}

	std::cout << answer;
	return 0;
}