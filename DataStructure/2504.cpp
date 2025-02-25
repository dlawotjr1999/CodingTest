#include <iostream>
#include <stack>

int main() {
	std::string str;
	std::stack<char> stack;

	int mul = 1;
	int sum = 0;

	std::cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '[') {
			mul *= 3;
			stack.push(str[i]);
		}
		else if (str[i] == '(') {
			mul *= 2;
			stack.push(str[i]);
		}
		else if (str[i] == ')') {
			if (stack.empty() || stack.top() != '(') {
				sum = 0;
				break;
			}
			if (str[i - 1] == '(')
				sum += mul;
			stack.pop();
			mul /= 2;
		}
		else {
			if (stack.empty() || stack.top() != '[') {
				sum = 0;
				break;
			}
			if (str[i - 1] == '[')
				sum += mul;
			stack.pop();
			mul /= 3;
		}
	}

	if (stack.empty()) {
		std::cout << sum;
	}
	else {
		std::cout << '0';
	}
}