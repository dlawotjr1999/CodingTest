#include <iostream>
#include <vector>
#include <algorithm>

// ���̰� N�� ���� �迭 A�� B�� ���� ��, �Լ� S�� �Ʒ��� ���� ���ǵ�
// S = A[0] �� B[0] + ... + A[N - 1] �� B[N - 1]
// �� �� A�� ��迭�Ͽ� S�� �ּڰ��� ���ϴ� ���� 
// ��, B�� �ִ� ���� ��迭�ϸ� �� ��

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    // A�� �迭�Ѵٴ� ���� �� A�� �迭 ������ ������� �ٲ� �� �ִٴ� ���� �ǹ���
    // ��������� ������ ���ϴ� ���� �ƴϱ� ������ B�� ��迭�ص� ������(������ B�� ���� �ּڰ��� ���� �� �ֵ��� A�� ������ ������Ű�� ��) 
    // S�� �ּ�ȭ�Ϸ��� A�� ���� ������, B�� ū ������ �����Ͽ� ���� ���ϸ� ��

    // A�� ������������, B�� ������������ ����
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end(), std::greater<int>());

    long long S = 0;
    for (int i = 0; i < N; i++) {
        S += 1LL * A[i] * B[i];
    }

    std::cout << S << "\n";
    return 0;
}
