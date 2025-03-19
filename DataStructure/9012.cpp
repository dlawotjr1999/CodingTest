#include <iostream>
#include <stack>
#include <string>

// 올바른 괄호 문자열인지 확인하는 문제
// 스택을 활용해서 구현
// '('이면 스택에 push, ')'이면 pop을 하는 것으로 구현

int main() {
    int T;
    std::string input;

    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> input;
        std::stack<char> stack;
        std::string answer = "YES";

        for (int j = 0; j < input.length(); j++) {
            if (input[j] == '(') {
                stack.push(input[j]);
            }
            else {

                // ')'가 빈 스택에 들어온 경우는 무조건 틀린 괄호 문자열
                if (stack.empty()) {
                    answer = "NO";
                    break;
                }
                else {
                    stack.pop();
                }
            }
        }

        // 스택이 비어있으면 올바른 괄호 문자열. 그렇지 않으면 틀린 문자열
        if (!stack.empty()) {
            answer = "NO";
        }
        std::cout << answer << std::endl;
    }
    return 0;
}
