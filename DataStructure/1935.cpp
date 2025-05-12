#include <iostream>
#include <stack>

// 후위 표기식을 계산하는 문제

int ary[26];  
std::stack<double> s;  

int main() {
    int N;
    std::cin >> N;

    std::string expression;
    std::cin >> expression;

    for (int i = 0; i < N; i++) {
        std::cin >> ary[i];
    }

    for (int i = 0; i < expression.size(); i++) {
        // 피연산자가 나오는 경우
        // 각 알파벳에 해당하는 숫자를 계산
        if ('A' <= expression[i] && expression[i] <= 'Z') {
            s.push(ary[expression[i] - 'A']);
        }

        // 연산자가 나오는 경우
        else {
            // 스택에서 피연산자 두 개를 꺼내서 연산자에 맞게 계산을 한 뒤 다시 스택에 push
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();

            switch (expression[i]) {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                s.push(a / b);
                break;
            default:
                break;
            }
        }
    }

    // 최종 계산 후 스택에는 연산 결과만이 남게 됨
    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << s.top() << std::endl;

    return 0;
}
