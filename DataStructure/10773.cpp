#include <iostream>
#include <stack>

// 스택 활용 문제
// 입력 숫자가 0이 아니면 push를, 0이면 pop을 하는 방식으로 구현

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

	// Better Solution 
	/* while (!stack.empty()) {
		result += stack.top();
		stack.pop();
	} */

	std::cout << result;
}
