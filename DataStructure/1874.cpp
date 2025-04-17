#include <iostream>
#include <stack>
#include <vector>

int main() {
	int n;
	int idx = 1;
	std::vector<char> answer;
	std::stack<int> s;

	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		int num; std::cin >> num;
		
		while (num >= idx) {
			s.push(idx);
			answer.push_back('+');
			idx++;
		}
		if (s.top() == num) {
			answer.push_back('-');
			s.pop();
		}
		else {
			std::cout << "NO";
			return 0;
		}
	}

	for (char& c : answer) {
		std::cout << c << '\n';
	}
	return 0;
}