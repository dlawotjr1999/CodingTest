#include <iostream>
#include <vector>
#include <algorithm>

// �Էµ� ������ �ڸ������ ���� �� �ִ� ���� ū 30�� ����� ã�� ����
// 30�� ��� : ��� �ڸ����� ���� 3�� ����̸�, 0�� �ϳ� �̻� �־�� ��

int main() {
    std::string input;
    int sum = 0;
    bool hasZero = false;
    std::vector<int> vec;

    std::cin >> input;

    for (int i = 0; i < input.size(); i++)
        // �Է��� ���ڿ��� �޾� ���ڷ� ġȯ�ϴ� ������ �ʿ�
        vec.push_back(input[i] - '0');

    // ���� ū 30�� ����� ���ؾ� �ϹǷ� ������������ ������ �̷������ ��
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    for (int i = 0; i < vec.size(); i++) {
        // 3�� ������� Ȯ���ϱ� ���� �� �ڸ����� ���� ����
        sum += vec[i];
        // ���ÿ�, ��ҿ��� 0�� ã���� 30�� ����� ������ �� ����
        // 0�� �� ���̵� ������� ������ �̸� bool�� ���� 
        if (vec[i] == 0) hasZero = true;
    }

    // 0�� ������ �ְ�, �� �ڸ����� ���� 3�� ����� �̷�� 30�� ����� ���� �� ����
    if (hasZero && (sum % 3 == 0)) {
        for (int& elm : vec)
            std::cout << elm;
    }
    else 
        std::cout << -1;

    return 0;
}
