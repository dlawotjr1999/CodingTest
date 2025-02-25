#include <iostream>

//Gredy
int main() {
    int num = 0;

    std::cin >> num;

    for (int i = 0; i < num; i++) {
        long result = 1;
        int N, M = 0;

        std::cin >> N >> M;

        int r = 1;
        for (int j = M; j > (M - N); j--) {
            result *= j;
            result /= r;
            r++;
        }
        std::cout << result << std::endl;
    }
    return 0;
}