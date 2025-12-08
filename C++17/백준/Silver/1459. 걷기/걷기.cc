#include <iostream>
#include <algorithm>

int main() {
    long long X, Y, W, S;
    std::cin >> X >> Y >> W >> S;

    long long a = std::max(X, Y);
    long long b = std::min(X, Y);

    long long result;

    if (S >= 2 * W) {
        result = (X + Y) * W;
    }
    else if (S <= W) {
        if ((X + Y) % 2 == 0) {
            result = a * S;
        }
        else {
            result = (a - 1) * S + W;
        }
    }
    else {
        result = b * S + (a - b) * W;
    }

    std::cout << result;
    return 0;
}