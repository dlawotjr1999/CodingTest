#include <iostream>
#include <cmath> 

// 서로 다른 N개의 자연수의 합이 S일 때, N의 최댓값을 구하는 문제
// 즉 1+2+3+...+n <= S을 만족하는 1부터 n의 갯수를 구하면 됨
// 마지막 n은, S에서 1부터 (n - 1)까지의 합을 뺀 값으로 생각할 수 있기 때문
int main() {
    long long S;
    std::cin >> S;

    long long N = (-1 + static_cast<long long>(sqrt(1 + 8 * S))) / 2;

    std::cout << N;
}
