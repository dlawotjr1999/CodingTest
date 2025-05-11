#include <iostream>
#include <stack>
#include <vector>

// 1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써 주어진 수열을 만들 수 있는지를 구하는 문제
// push는 +, pop은 -를 통해 두 연산들로 수열을 어떻게 만들 수 있는지 그 방법을 출력
// 즉 +는 특정 숫자를 만들기 위한 연산, -는 수열을 구성하는 원소를 의미함

int main() {
	int n;
	int idx = 1;
	std::vector<char> answer;
	std::stack<int> s;

	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		int num; std::cin >> num;
		
		// 스택의 top이 num보다 작거나 같을 때까지 1, 2, ... 를 스택에 push
		while (num >= idx) {
			s.push(idx);
			answer.push_back('+');
			idx++;
		}
		// 스택의 top이 num과 같으면 타깃으로 하는 숫자이므로 pop
		if (s.top() == num) {
			answer.push_back('-');
			s.pop();
		}
		// 스택의 top과 타깃 숫자가 다르면 스택 수열 불가능
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