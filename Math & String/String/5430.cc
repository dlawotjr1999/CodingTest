#include <iostream>
#include <deque>
#include <string>

// ������ ����� AC�� ���� ���� ����� ���ؾ� ��
// AC���� R(������)�� D(������) ������ ����
// R�� �迭�� ���� ������ �Լ���, D�� ù ��° ���� ������ �Լ��̸�, �迭�� �� ���¿��� D�� �����ϸ� ������ �߻���
// �� ��, �� ������ �̷���� �Լ� p�� ������ ���� �迭�� ���� ���¸� ����ϴ� ����

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        std::string func;
        std::cin >> func;

        int n;
        std::cin >> n;

        std::string arys;
        std::cin >> arys;

        std::deque<int> deque;
        int num = 0;
        bool is_num = false;

        // ���ڿ� �Ľ� ����
        for (char c : arys) {
            // ���� ������ ��� is_num �÷��׸� Ȱ��ȭ��Ű�� �ڸ����� �������� num ���
            if (std::isdigit(c)) {
                is_num = true;
                num = num * 10 + (c - '0');
            }
            // ���ڰ� �ƴ� ��� ��������� ���� ���ڸ� deque�� �����ϰ� num�� �÷��� �ʱ�ȭ
            else {
                if (is_num) {
                    deque.push_back(num);
                    num = 0;
                    is_num = false;
                }
            }
        }

        bool is_reversed = false;
        bool is_error = false;
        for (char op : func) {

            // std::reverse�� O(N)�̱� ������ �ð� �ʰ��� �߻��� �� �ֱ� ������ reverse �÷��׷� ������ ������
            // R�� ������ ������ ������ ���� ���
            if (op == 'R') {
                is_reversed = !is_reversed;
            }
            else {  
                // deque�� ����ִ� ���¿��� D ������ �ϸ� ���� �߻�
                if (deque.empty()) {
                    is_error = true;
                    break;
                }
                // deque�� �� ���� ���� ����
                // �� �� ���¶�� �� ���� ���ڸ�, ������ ���¶�� �� ���� ���ڸ� ������
                if (!is_reversed) 
                    deque.pop_front();
                else              
                    deque.pop_back();
            }
        }

        // error �÷��װ� true�� error ���
        if (is_error) {
            std::cout << "error\n";
        }
        else {
            std::cout << '[';
            // ���������� ���� ������ ��쿡�� ���������� ���
            if (!is_reversed) {
                for (int i = 0; i < deque.size(); ++i) {
                    if (i) 
                        std::cout << ',';
                    std::cout << deque[i];
                }
            }
            // ������ ��쿡�� ���������� ���
            else {
                for (int i = deque.size(); i-- > 0; ) {
                    if (i != deque.size() - 1) 
                        std::cout << ',';
                    std::cout << deque[i];
                }
            }
            std::cout << "]\n";
        }
    }
    return 0;
}
