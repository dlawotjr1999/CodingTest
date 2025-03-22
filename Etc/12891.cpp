#include <iostream>
#include <unordered_map>

// 처음에는 sliding window를 투 포인터로 구현하였으나 시간 초과 발생
// solution : 처음과 끝부분만 변경하는 방식으로 해결

int main() {
    int S, P;
    std::cin >> S >> P;

    int answer[4] = { 0, 0, 0, 0 };
    std::unordered_map<char, int> partition;

    std::string str;
    std::cin >> str;

 
    for (int i = 0; i < 4; i++) {
        std::cin >> answer[i];
    }

    int cnt = 0;

    for (int i = 0; i < P; i++) {
        partition[str[i]]++;
    }

    auto check = [&]() {
        return partition['A'] >= answer[0] && partition['C'] >= answer[1] &&
            partition['G'] >= answer[2] && partition['T'] >= answer[3];
    };

    if (check()) {
        cnt++;
    }

    for (int i = P; i < S; i++) {
        partition[str[i]]++;
        partition[str[i - P]]--;

        if (check()) {
            cnt++;
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}
