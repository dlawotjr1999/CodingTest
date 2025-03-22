#include <iostream>
#include <vector>
#include <algorithm>

// ���� ���� ��Ÿ���� �ڿ��� N�� �־�����, �� �� �ְ��� ��Ÿ���� N���� �ڿ������� �������� ���еǾ� ������� �־�����.
// �� �� �ִ� ������ ��Ÿ���� ������ ����Ѵ�

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        std::vector<int> vec(N);

        for (int& elm : vec) {
            std::cin >> elm;
        }

        int maxValue = 0;
        long long profit = 0;

        // idea : �������� �����ؾ� ���� ������ �� ����
        // �������� �����ϸ鼭 maxValue�� �����س���
        // maxValue���� ���� ������ ��������, maxValue���� ū ���� ������ maxValue�� �� ������ ������
        // maxValue���� ���� ������ maxValue���� �� ���� �� ��ġ(��, �� ���� ������ �ǹ���)�� ���ϸ鼭 �� ������ ����س���
        for (int i = (vec.size() - 1); i >= 0; i--) {
            if (maxValue < vec[i])
                maxValue = vec[i];
            else
                profit += (maxValue - vec[i]);
        }

        // diffrent access(iterator ���)
        /* 
        int maxValue = vec.back();
        long long profit = 0;

        for (auto it = vec.crbegin(); it != vec.crend(); it++) {
            if (maxValue < *it)
                maxValue = *it;
            else
                profit += (maxValue - *it);
        }
        */
        std::cout << profit << std::endl;
    }

    return 0;
}
