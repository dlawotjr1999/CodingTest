#include <iostream>
#include <stack>
#include <algorithm>

// 여는 괄호와 닫는 괄호로 이루어진 문자열이 있을 때, 안정적인 문자열로 만들기 위한 연산의 최소 횟수를 구하는 문제
// 문자열에 행할 수 있는 연산은 여는 괄호를 닫는 괄호로 바꾸거나, 닫는 괄호를 여는 괄호로 바꾸는 것임

int main() {
	int index = 1;

	while (true) {
		std::string input;
		std::cin >> input;

		// 한 개 이상의 '-'가 입력되면 종료
		if (std::find(input.begin(), input.end(), '-') != input.end()) {
			return 0;
		}

		int answer = 0;

		std::stack<char> s;
		for (char c : input) {
			if (c == '{')
				s.push(c);
			else {
				// 맨 처음에 '}'가 들어오면 올바르지 않으므로 '{'으로 치환하여 삽입 후 변환 수 증가
				if (s.empty()) {
					answer++;
					s.push('{');
				}
				else {
					s.pop();
				}
			}
		}
		
		// 스택 연산이 끝나면 짝이 맞지 않은 괄호들만이 남아있음
		// 남은 괄호들을 2개씩 묶어 안정적인 쌍으로 만들 수 있기 때문에, 현재 스택 크기의 절반만큼 추가 변환을 진행하면 됨
		answer += static_cast<int>(s.size() / 2);
		std::cout << index << '.' << ' ' << answer << '\n';

		index++;
	}
}