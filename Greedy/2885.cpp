#include <iostream>

// ����̰� K���� ���ݸ� ������ �Ա� ���� ���ݸ��� �ɰ��� ����
// �־��� ���ݸ��� 2�� ���� ������ �̷���� ���� ���ݸ��̸�, ������ ����θ� �ɰ� �� ����
// �� �� �� �� �ɰ��� K���� ���� �� �ִ����� ����ϴ� �ּ� ���ݸ� ũ�⸦ ���ϴ� ����

int main() {
    int K;
    std::cin >> K;

    int size = 1;   // ���ݸ��� ũ��
    int piece = 0;  // �������� ���ݸ� ���� ������ ��
    int cut = 0;    // ���ݸ��� �ڸ� Ƚ��

    // ���ݸ��� ũ��� K���� ū 2�� �������� �� ���� ���� ������ ��
    while (K > size) {
        size *= 2;
    }

    // ���ݸ��� �ڸ� Ƚ���� ���ϱ�
    // ������ �߷��� �ִ� ������(piece)�� �� �� �� �߶��� ���� ��(temp)�� ���� K�� ��� ����
    // �� ���� K���� ������ piece�� �߰�
    // K���� ũ�� �۵� �ڸ��� ������ ����Ǿ�� ��
    if (size != K) {
        int temp = size / 2;
        cut++;

        while (piece + temp != K) {
            if (piece + temp < K)
                piece += temp;
            temp /= 2;
            cut++;
        }

        // different solution
        /* 
        int temp = size;
        
        while (K % temp != 0) {
            temp /= 2;
            cnt++;
        }
        */
    }

    std::cout << size << " " << cut << std::endl;

    return 0;
}
