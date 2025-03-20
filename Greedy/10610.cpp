#include <iostream>
#include <vector>
#include <algorithm>

// 입력된 숫자의 자릿수들로 만들 수 있는 가장 큰 30의 배수를 찾는 문제
// 30의 배수 : 모든 자릿수의 합이 3의 배수이며, 0이 하나 이상 있어야 함

int main() {
    std::string input;
    int sum = 0;
    bool hasZero = false;
    std::vector<int> vec;

    std::cin >> input;

    for (int i = 0; i < input.size(); i++)
        // 입력을 문자열로 받아 숫자로 치환하는 과정이 필요
        vec.push_back(input[i] - '0');

    // 가장 큰 30의 배수를 구해야 하므로 내림차순으로 정렬이 이루어져야 함
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    for (int i = 0; i < vec.size(); i++) {
        // 3의 배수임을 확인하기 위해 각 자릿수의 합을 누적
        sum += vec[i];
        // 동시에, 요소에서 0을 찾으면 30의 배수를 구성할 수 있음
        // 0이 몇 개이든 상관없기 때문에 이를 bool로 저장 
        if (vec[i] == 0) hasZero = true;
    }

    // 0을 가지고 있고, 각 자릿수의 합이 3의 배수를 이루면 30의 배수를 만들 수 있음
    if (hasZero && (sum % 3 == 0)) {
        for (int& elm : vec)
            std::cout << elm;
    }
    else 
        std::cout << -1;

    return 0;
}
