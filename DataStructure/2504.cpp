#include <iostream>
#include <stack>

// 주어진 괄호열이 올바른 괄호열일 경우 아래와 같은 규칙을 따른다
//‘()’ 인 괄호열의 값은 2이다
//‘[]’ 인 괄호열의 값은 3이다
//‘(X)’ 의 괄호값은 2×값(X) 으로 계산된다
//‘[X]’ 의 괄호값은 3×값(X) 으로 계산된다
// 올바른 괄호열 X와 Y가 결합된 XY의 괄호값은 값(XY) = 값(X) + 값(Y) 로 계산된다
// 이 때 주어진 괄호열이 올바른 괄호열일 경우 그 계산값을, 그렇지 않을 경우 0을 출력하는 문제

int main() {
	std::string str;

	// 기존 괄호열 검토 문제처럼 스택을 이ㅇ활용
	std::stack<char> stack;

	int mul = 1;
	int sum = 0;

	std::cin >> str;

	for (int i = 0; i < str.length(); i++) {
		// '['를 만나면 앞으로 닫힐 때 3을 곱한 값을 더할 수 있도록 계수 누적
		if (str[i] == '[') {
			mul *= 3;
			stack.push(str[i]);
		}
		// '('를 만나면 앞으로 닫힐 때 2를 곱한 값을 더할 수 있도록 계수 누적
		else if (str[i] == '(') {
			mul *= 2;
			stack.push(str[i]);
		}
		// ')'를 만났을 때: 올바른 괄호쌍인지 확인
		else if (str[i] == ')') {
			// 잘못된 괄호 구조면 결과 0
			if (stack.empty() || stack.top() != '(') {
				sum = 0;
				break;
			}
			// 직전 문자(str[i-1])가 '('였다면 '()' 한 쌍이므로, 현재 mul 값(현재 깊이에서 곱해진 2의 제곱)을 더함
			if (str[i - 1] == '(')
				sum += mul;
			stack.pop(); // '(' 짝 제거      
			mul /= 2;	 // 곱셈 계수를 한 단계 낮춤
		}
		// ']'를 만났을 때: ')'와 유사한 방식
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

	// 스택이 비어 있지 않으면 짝이 맞지 않은 것으로 간주
	if (stack.empty()) {
		std::cout << sum;
	}
	else {
		std::cout << '0';
	}
}