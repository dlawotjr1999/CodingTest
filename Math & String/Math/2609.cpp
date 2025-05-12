#include <iostream>

// 유클리드 호제법 구현 문제 

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int a, b;

    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    std::cout << a * b / gcd(a, b);
}