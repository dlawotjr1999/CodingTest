#include <iostream>
#include <unordered_map>

// ó������ sliding window�� �� �����ͷ� �����Ͽ����� �ð� �ʰ� �߻�
// solution : ó���� ���κи� �����ϴ� ������� �ذ�

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
