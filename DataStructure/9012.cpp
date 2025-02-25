#include <iostream>
#include <stack>
#include <string>

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
                if (stack.empty()) {
                    answer = "NO";
                    break;
                }
                else {
                    stack.pop();
                }
            }
        }
        if (!stack.empty()) {
            answer = "NO";
        }
        std::cout << answer << std::endl;
    }
    return 0;
}
