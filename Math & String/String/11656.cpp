#include <iostream>
#include <vector>
#include <algorithm>

// ���̻� �迭 ���� ����
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string str;
    std::vector<std::string> input;

    std::cin >> str;

    for (int i = 0; i < str.length(); i++) {
        std::string partitionInput;

        // ���ڿ��� ���� index�� �ϳ��� �÷����鼭 ���̻� ���ڿ��� ������
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