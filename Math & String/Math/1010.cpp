#include <iostream>

// 이항정리 구현 문제
// 결과값이 int 형을 벗어날 수 있으므로 long으로 자료형 설정

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