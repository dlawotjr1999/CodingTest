#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string input;
    int sum = 0;
    bool hasZero = false;
    std::vector<int> vec;

    std::cin >> input;

    for (int i = 0; i < input.size(); i++)
        vec.push_back(input[i] - '0');
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
        if (vec[i] == 0) hasZero = true;
    }

    if (hasZero && (sum % 3 == 0)) {
        for (int& elm : vec)
            std::cout << elm;
    }
    else std::cout << -1;

    return 0;
}
