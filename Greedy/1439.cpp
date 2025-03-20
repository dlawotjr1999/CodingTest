#include <iostream>

// �־��� �Է¿��� 1�� 0����, 0�� 1�� �ٲٴ� ����
// �پ��ִ� ���ڿ��� �� ���� ������ �� ������, �� �ּ�Ƚ���� ���ϴ� ����
// idea : �������� 1�� ���ڿ��� ����, �������� 0�� ���ڿ��� �� �� ���� ���� ������ ���ϸ� ��

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string input;
    std::cin >> input;

    int zero_cnt = 0;
    int one_cnt = 0;

    // �Ʒ� �ݺ��������� index ó���� ���� ù ��° ���ڿ��� ���� ó��
    // �ݺ����� (input.length() - 1)���� ������ �� ������ ���ڿ� ���ϴ� ��ĵ� ������
    if (input[0] == '0') zero_cnt++;
    else one_cnt++;

    for (size_t i = 1; i < input.length(); i++) {
        // ���ڿ��� ���������� Ž���ϴٰ� ��ȯ�Ǵ� �������� cnt ����
        if (input[i] != input[i - 1]) {
            if (input[i] == '0') zero_cnt++;
            else one_cnt++;
        }
    }

    if (zero_cnt <= one_cnt)
        std::cout << zero_cnt;
    else std::cout << one_cnt;

    return 0;
}