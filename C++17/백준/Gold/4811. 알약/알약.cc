#include <iostream>
#include <algorithm>

int main() {
    long long DP[31][31] = { 0 };

    for (int w = 0; w <= 30; ++w)
        DP[0][w] = 1;

    for (int h = 1; h <= 30; ++h) {
        for (int w = h; w <= 30; ++w) {
            DP[h][w] = DP[h - 1][w] + DP[h][w - 1];
        }
    }
 
    while (true) {
        int N;
        std::cin >> N;

        if (N == 0)
            break;
        std::cout << DP[N][N] << '\n';
    }

    return 0;
}
