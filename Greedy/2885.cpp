#include <iostream>

int main() {
    int K;
    std::cin >> K;

    int size = 1;
    int piece = 0;
    int cut = 0;

    while (K > size) {
        size *= 2;
    }

    if (size != K) {
        int temp = size / 2;
        cut++;

        while (piece != K) {
            if (piece + temp < K)
                piece += temp;
            if (piece + temp == K)
                break;
            temp /= 2;
            cut++;
        }
    }

    std::cout << size << " " << cut << std::endl;

    return 0;
}
