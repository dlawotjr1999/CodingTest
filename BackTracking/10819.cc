#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// N���� ���ҵ�� �̷���� �迭 A�� �־��� ���� �� ���ҵ��� ������ �ٲ� �Ʒ� ������ �ִ��� ���ϴ� ����
// | A[0] - A[1] | +| A[1] - A[2] | +... + | A[N - 2] - A[N - 1] |

int main() {
    int N;
    std::cin >> N;

    std::vector<int> vec(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> vec[i];
    }

    // next_permutation�� ���� ���� ���� ����
    std::sort(vec.begin(), vec.end());
    
    // next_permutaion �Լ��� ���� ������ �����ϸ� �ش� ���� ������ �ٲٰ� true�� ��ȯ��
    // �� ���� ������ ���� ����� ����Ǿ�� �ϱ� ������ do-while���� ���� �����ؾ� ��
    int answer = 0;
    do {
        int sum = 0;
        for (int i = 0; i < N - 1; ++i) {
            sum += std::abs(vec[i] - vec[i + 1]);
        }
        answer = std::max(answer, sum);
    } while (std::next_permutation(vec.begin(), vec.end()));

    std::cout << answer << '\n';
    return 0;
}