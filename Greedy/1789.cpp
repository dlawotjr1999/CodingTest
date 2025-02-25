#include <iostream>
#include <cmath> 

int main() {
    long long S;
    std::cin >> S;

    long long N = (-1 + static_cast<long long>(sqrt(1 + 8 * S))) / 2;

    if (N * (N + 1) / 2 > S) {
        N--;
    }

    std::cout << N;
}
