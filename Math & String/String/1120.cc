#include <bits/stdc++.h>

// �� ���ڿ� A�� B�� ���� ��(A�� ���� <= B�� ����), A�� ���̳� �ڿ� �ƹ� ���ĺ��� �߰��� �� ����
// �� ��, A�� B�� ���̰� �����鼭, A�� B�� ������ �ּڰ��� ���ϴ� ����

int main() {
    std::string A, B;
    std::cin >> A >> B;

    int diff = INT_MAX;

    // �� ���ڿ��� ���� ���̸�ŭ �ݺ��ϸ� �˻�
    for (int i = 0; i <= B.size() - A.size(); i++) {
        int cur = 0;

        // �� ��ġ���� �ٸ� ������ ������ �� ��, �ּڰ��� �����س���
        for (int j = 0; j < A.size(); j++) {
            if (A[j] != B[i + j]) cur++;
        }
        diff = std::min(diff, cur);
    }

    std::cout << diff << "\n";
    return 0;
}