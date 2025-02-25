#include <iostream>
#include <stack>

int main() {
	int K, elm;
	int result = 0;
	std::stack<int> stack;

	std::cin >> K;

	for (int i = 0; i < K; i++) {
		std::cin >> elm;
		if (elm != 0)
			stack.push(elm);
		else
			stack.pop();
	}

  // 연산 과정에서 스택의 사이즈가 변하므로 먼저 스택의 크기 선언
	size_t stack_size = stack.size();
	for (int i = 0; i < stack_size; i++) {
		result += stack.top();
		stack.pop();
	}

	std::cout << result;
}
