#include <iostream>
#include <vector>
#include <algorithm>

// ���� �� �ִ� ����� �� N�� �� ����� ���� �����ϴµ� �ɸ��� �ð� P_i�� �־����� ��, �� ����� ���� �����ϴµ� �ʿ��� �ð��� ���� �ּڰ��� ���ϴ� ����
// ���ð��� ª�� ������ ������� ������ ���־��(��������) �� ���ð��� �ּҰ� ��
int main() {
    int N, elm, result = 0;

    std::vector<int> vec;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> elm;
        vec.push_back(elm);
    }

    // �ּ� ���ð��� ����� ���� ������ �����ؾ� ��
    std::sort(vec.begin(), vec.end());

    for (int i = 0; i < N; i++) {
        result += vec[i] * (N - i);
    }
    std::cout << result;

    return 0;
}
