#include <iostream>
#include <vector>

int main() {
    long long N;
    std::cin >> N;

    std::vector<long long> result(10, 0);

    long long pos = 1;  
    while (pos <= N) {
        long long high = N / (pos * 10);
        long long cur = (N / pos) % 10;
        long long low = N % pos;

        for (int digit = 0; digit <= 9; digit++) {
            if (digit < cur) {
                result[digit] += (high + 1) * pos;
            }
            else if (digit == cur) {
                result[digit] += high * pos + low + 1;
            }
            else {
                result[digit] += high * pos;
            }
        }

        result[0] -= pos;
        pos *= 10;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}
