#include <iostream>

// 주어진 입력에서 1은 0으로, 0은 1로 바꾸는 문제
// 붙어있는 문자열을 한 번에 뒤집을 수 있으며, 그 최소횟수를 구하는 문제
// idea : 연속적인 1의 문자열의 수와, 연속적인 0의 문자열의 수 중 적은 수의 갯수를 구하면 됨

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string input;
    std::cin >> input;

    int zero_cnt = 0;
    int one_cnt = 0;

    // 아래 반복문에서의 index 처리를 위해 첫 번째 문자열은 따로 처리
    // 반복문을 (input.length() - 1)까지 진행한 후 마지막 문자와 비교하는 방식도 가능함
    if (input[0] == '0') zero_cnt++;
    else one_cnt++;

    for (size_t i = 1; i < input.length(); i++) {
        // 문자열을 순차적으로 탐색하다가 전환되는 시점에서 cnt 증가
        if (input[i] != input[i - 1]) {
            if (input[i] == '0') zero_cnt++;
            else one_cnt++;
        }
    }

    if (zero_cnt <= one_cnt)
        std::cout << zero_cnt;
    else std::cout << one_cnt;

    return 0;
}