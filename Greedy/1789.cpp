#include <iostream>
#include <cmath> 

// ���� �ٸ� N���� �ڿ����� ���� S�� ��, N�� �ִ��� ���ϴ� ����
// �� 1+2+3+...+n <= S�� �����ϴ� 1���� n�� ������ ���ϸ� ��
// ������ n��, S���� 1���� (n - 1)������ ���� �� ������ ������ �� �ֱ� ����
int main() {
    long long S;
    std::cin >> S;

    long long N = (-1 + static_cast<long long>(sqrt(1 + 8 * S))) / 2;

    std::cout << N;
}
