#include <iostream>
#include <stack>

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
        if ('A' <= expression[i] && expression[i] <= 'Z') {
            s.push(ary[expression[i] - 'A']);
        }
        else {
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

    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << s.top() << std::endl;

    return 0;
}
