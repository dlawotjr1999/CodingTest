#include <iostream>
#include <vector>
#include <algorithm>

// 접미사 배열 구현 문제
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string str;
    std::vector<std::string> input;

    std::cin >> str;

    for (int i = 0; i < str.length(); i++) {
        std::string partitionInput;

        // 문자열의 시작 index를 하나씩 늘려가면서 접미사 문자열을 도출함
        for (int j = i; j < str.length(); j++) {
            partitionInput += str[j];
        }
        input.push_back(partitionInput);
    }

    std::sort(input.begin(), input.end());

    for (int k = 0; k < input.size(); k++)
        std::cout << input[k] << '\n';

    return 0;
}