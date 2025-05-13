#include <iostream>
#include <string>

// 'I'�� 'O'�� ����� ������, (2^N - 1)���� �̷���� ���ڿ��� P_N�̶�� �� �� �־��� ���ڿ��� P_N�� ������ ���ϴ� ����

int answer;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::string S;
    std::cin >> S;

    int cnt = 0;

    for (int i = 1; i < M - 1;) {
        // "IOI"���ڿ��� ��� P_N�� �ش��ϴ� �� ����
        if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') {
            cnt++;

            // P_N�� ��� answer ����
            if (cnt == N) {
                answer++;
                
                // �ߺ� ���Ÿ� ���� cnt�� ����
                // ���� ���, "IOIOI"(cnt = 2) ������ "OI"�� ������ ��쿡�� cnt = 2�� �����ؾ� P_2�� ������ �� �ֱ� ���� 
                cnt--; 
            }
            i += 2;
        }
        // "IOI" ���ڿ��� �ƴ� ��� cnt �ʱ�ȭ �� ���� ���� ����
        else {
            cnt = 0;
            i++;
        }
    }

    std::cout << answer;
    return 0;
}
